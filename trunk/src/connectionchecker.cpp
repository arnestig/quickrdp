/**
    Copyright (C) 2010-2013 QuickRDP - Manages RDP, telnet and SSH connections

    Written by Tobias Eliasson <arnestig@gmail.com>.

    This file is part of quickRDP <http://sourceforge.net/projects/quickrdp/>.

    quickRDP is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    quickRDP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with quickRDP.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "connectionchecker.h"

#include <wx/msgdlg.h>
#include <iostream>
#include "Resources.h"

DEFINE_EVENT_TYPE( wxEVT_CONNECTION_CHECK_SEND_DATA )
DEFINE_EVENT_TYPE( wxEVT_CONNECTION_CHECK_STATUS_UPDATE )

ConnectionChecker::ConnectionChecker( wxEvtHandler *parent, unsigned int numWorkers, unsigned int timeout )
    :   wxThread( wxTHREAD_DETACHED),
        parent( parent ),
        queue( NULL ),
        willquit( false )
{
    /** define our numWorkers. For safety, we don't allow below 1 and not more than 8 workers.. For now this is for testing. **/
    if ( numWorkers > 8 ) {
        this->numWorkers = 8;
    } else if ( numWorkers < 1 ) {
        this->numWorkers = 1;
    } else {
        this->numWorkers = numWorkers;
    }

    /** define our socket select timeout.. Not too high and not too low. **/
    if ( timeout < 200000 ) {
        this->timeout = 20000;
    } else if ( timeout > 2000000 ) {
        this->timeout = 2000000;
    }

    queue = new wxSemaphore();
    /** create all our worker threads **/
    for ( unsigned int threadid = 0; threadid < numWorkers; ++threadid ) {
        workerThreads[ threadid ] = new ConnectionCheckerWorkerThread( this, queue, timeout );
        if ( workerThreads[ threadid ]->Create() != wxTHREAD_NO_ERROR ) {
            delete workerThreads[ threadid ];
            workerThreads[ threadid ] = NULL;
            wxMessageBox( wxT("Error creating ConnectionCheckerWorkerThread!"), wxT("Error!") );
        } else {
            if ( workerThreads[ threadid ]->Run() != wxTHREAD_NO_ERROR ) {
                delete workerThreads[ threadid ];
                workerThreads[ threadid ] = NULL;
                wxMessageBox( wxT("Error while running ConnectionCheckerWorkerThread!"), wxT("Error!") );
            }
        }
    }
}

ConnectionChecker::~ConnectionChecker()
{
	willquit = true;
	/** delete all our worker threads gracefully **/
	for ( unsigned int threadid = 0; threadid < numWorkers; ++threadid ) {
        workerThreads[ threadid ]->Delete();
	}

    /** remove all our targets left behind **/
	mutex.Lock();
	targets.clear();
	mutex.Unlock();
	delete queue;
}

void *ConnectionChecker::Entry()
{
    while ( TestDestroy() == false ) {
        wxCommandEvent evt_get_more_data( wxEVT_CONNECTION_CHECK_SEND_DATA, wxID_ANY );
        wxPostEvent( parent, evt_get_more_data );
        Sleep(100);
    }
    return 0;
}

void ConnectionChecker::addTargets( std::vector< RDPConnection* > newTargets )
{
    if ( newTargets.empty() == false ) {
	    mutex.Lock();
	    while ( newTargets.empty() == false ) {
	        RDPConnection *target = newTargets.back();
	        newTargets.pop_back();
	        std::string filename;
	        target->getFilename( filename );
	        if ( filename.empty() == false ) {
                if ( targets[ filename ] == NULL ) {
                    targets[ filename ] = target;
                    queue->Post();
                }
	        }
        }
	    mutex.Unlock();
	}
}

void ConnectionChecker::publishTarget( RDPConnection*& target )
{
    mutex.Lock();
    if ( targets.empty() == false ) {
        target = targets.begin()->second;
        targets.erase( targets.begin() );
    }
    mutex.Unlock();
}

void ConnectionChecker::postEvent( wxCommandEvent event )
{
    wxPostEvent( parent, event );
}

bool ConnectionChecker::aboutToQuit()
{
    return this->willquit;
}

/// BEGIN ConnectionCheckerWorkerThread

ConnectionCheckerWorkerThread::ConnectionCheckerWorkerThread( ConnectionChecker *parent, wxSemaphore *queue, unsigned int timeout )
    :   wxThread( wxTHREAD_DETACHED ),
        parent( parent ),
        queue( queue ),
        target( NULL )
{
    /** setting up our socket select timeout **/
    t.tv_sec = 0;
    t.tv_usec = timeout;

    /** socket settings **/
    sock_addr.sin_family = PF_INET;
    socket_mode = 1;

    #if defined(WIN32)
    	WSADATA info;
    	if (WSAStartup(MAKEWORD(2,0), &info)) {
         	wxMessageBox( wxT("Error during WSAStartup()") );
    	}
    #endif
}

ConnectionCheckerWorkerThread::~ConnectionCheckerWorkerThread()
{
}

void *ConnectionCheckerWorkerThread::Entry()
{
    hostent *host;
    while ( TestDestroy() == false ) {
        if ( target == NULL ) {
            /** get us a new target **/
            queue->WaitTimeout( 200 );
            if ( parent->aboutToQuit() == false ) {
                parent->publishTarget( target );
            }
        } else {
            /** Connect to our current target **/
            wxCommandEvent event( wxEVT_CONNECTION_CHECK_STATUS_UPDATE, wxID_ANY );
            int port = target->getPort();
            std::string hostname;
            std::string filename;
            target->getHostname( hostname );
            target->getFilename( filename );
            sock_addr.sin_port = htons( port );
            sock_addr.sin_addr.s_addr = 0;
            if ( inet_addr( hostname.c_str() ) == INADDR_NONE ) {
                host = gethostbyname( hostname.c_str() );
                if ( host != NULL ) {
                    sock_addr.sin_addr.s_addr = *((unsigned long*) host->h_addr_list[0] );
                }
            } else {
                sock_addr.sin_addr.s_addr = inet_addr( hostname.c_str() );
            }

            m_socket = socket( AF_INET, SOCK_STREAM, 0 );
            ioctlsocket( m_socket, FIONBIO, &socket_mode ); // Put the socket in non-blocking mode
            connect( m_socket, (struct sockaddr*) &sock_addr, sizeof( struct sockaddr ) );

            fd_set wfds;
            FD_ZERO( &wfds );
            FD_SET( m_socket, &wfds );
            int retval = select( m_socket+1, 0, &wfds, 0, &t );

            if ( retval <= 0 ) {
                event.SetInt( 0 );
            } else {
                event.SetInt( 1 );
            }

            wxString eventfilename( filename.c_str(), wxConvUTF8 );
            event.SetString( eventfilename );

            parent->postEvent( event );

            closesocket( m_socket );

            time_t seconds;
            seconds = time (NULL);
            target->setLastChecked( seconds );
            target->setConnectionCheckerRunning( false );
            target = NULL;
        }
    }

    return 0;
}
