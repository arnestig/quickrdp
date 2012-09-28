/**
    Copyright (C) 2010-2012 QuickRDP - Manages RDP, telnet and SSH connections

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

ConnectionTarget::ConnectionTarget( wxString hostname, wxString port, wxString filename )
    :   hostname( hostname ),
        port( port ),
        filename( filename ),
        status( 0 )
{
}

ConnectionTarget::~ConnectionTarget()
{
}

wxString ConnectionTarget::getHostname() const
{
    return hostname;
}

wxString ConnectionTarget::getPort() const
{
    return port;
}

wxString ConnectionTarget::getFilename() const
{
    return filename;
}

int ConnectionTarget::getStatus() const
{
    return status;
}

void ConnectionTarget::setStatus( int status )
{
    this->status = status;
}

ConnectionChecker::ConnectionChecker( wxEvtHandler *parent )
    :   wxThread( wxTHREAD_DETACHED),
        parent( parent ),
        queue( NULL )
{
    queue = new wxSemaphore();
    /** create all our worker threads **/
    for ( unsigned int threadid = 0; threadid < numWorkers; ++threadid ) {
        workerThreads[ threadid ] = new ConnectionCheckerWorkerThread( this, queue );
        if ( workerThreads[ threadid ]->Create() != wxTHREAD_NO_ERROR ) {
            delete workerThreads[ threadid ];
            workerThreads[ threadid ] = NULL;
            wxMessageBox( wxT("Error creating ConnectionCheckerWorkerThread!"), wxT("Error!") );
        } else {
            if ( workerThreads[ threadid ]->Run() != wxTHREAD_NO_ERROR ) {
                delete workerThreads[ threadid ];
                workerThreads[ threadid ] = NULL;
                wxMessageBox( wxT("Error while running ConnectionCheckerWorkerThread!") );
            }
        }
    }
}

ConnectionChecker::~ConnectionChecker()
{
	/** delete all our worker threads gracefully **/
	for ( unsigned int threadid = 0; threadid < numWorkers; ++threadid ) {
        workerThreads[ threadid ]->Delete();
	}

    /** remove all our targets left behind **/
	mutex.Lock();
	for ( std::vector< ConnectionTarget* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
		delete (*it);
	}
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


void ConnectionChecker::addTargets( std::vector< ConnectionTarget* > newTargets )
{
    if ( newTargets.empty() == false ) {
	    mutex.Lock();
	    while ( newTargets.empty() == false ) {
	        targets.push_back( newTargets.back() );
            newTargets.pop_back();
            queue->Post();
        }
	    mutex.Unlock();
	}
}

void ConnectionChecker::publishTarget( ConnectionTarget*& target )
{
    mutex.Lock();
    if ( targets.empty() == false ) {
        target = targets.front();
        targets.erase( targets.begin() );
    }
    mutex.Unlock();
}

void ConnectionChecker::postEvent( wxCommandEvent event )
{
    wxPostEvent( parent, event );
}

/// BEGIN ConnectionCheckerWorkerThread

ConnectionCheckerWorkerThread::ConnectionCheckerWorkerThread( ConnectionChecker *parent, wxSemaphore *queue )
    :   wxThread( wxTHREAD_DETACHED ),
        parent( parent ),
        queue( queue ),
        target( NULL )
{
    /** setting up our socket select timeout **/
    t.tv_sec = 0;
    t.tv_usec = 200000;

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
    workCompleted = 0;
    while ( TestDestroy() == false ) {
        if ( target == NULL ) {
            /** get us a new target **/
            queue->WaitTimeout( 200 );
            getNewTarget();
        } else {
            /** Connect to our current target **/
            wxCommandEvent event( wxEVT_CONNECTION_CHECK_STATUS_UPDATE, wxID_ANY );
            sock_addr.sin_port = htons(wxAtoi( target->getPort() ) );
            sock_addr.sin_addr.s_addr = 0;
            if ( inet_addr( target->getHostname().mb_str() ) == INADDR_NONE ) {
                host = gethostbyname( target->getHostname().mb_str() );
                if ( host != NULL ) {
                    sock_addr.sin_addr.s_addr = *((unsigned long*) host->h_addr_list[0] );
                }
            } else {
                sock_addr.sin_addr.s_addr = inet_addr( target->getHostname().mb_str() );
            }

            m_socket = socket( AF_INET, SOCK_STREAM, 0 );
            //std::cout << "socket created = " << m_socket << std::endl;
            ioctlsocket( m_socket, FIONBIO, &socket_mode ); // Put the socket in non-blocking mode
            bool optval = true;
            //setsockopt( m_socket, SOL_SOCKET, SO_REUSEADDR, (char *) optval, sizeof(optval) );
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

            event.SetString( target->getFilename() );

            parent->postEvent( event );

            closesocket( m_socket );

            delete target;
            target = NULL;
            workCompleted++;
        }
    }
    std::cout << "Thread " << GetCurrentId() << " done, targets scanned: " << workCompleted << std::endl;
    return 0;
}

void ConnectionCheckerWorkerThread::getNewTarget()
{
    target = NULL;
    parent->publishTarget( target );
}
