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
    :   wxThread( wxTHREAD_DETACHED ),
        parent( parent ),
        highest_fds( 0 )
{
    /** setting up our socket select timeout, parameterized in the future? **/
    t.tv_sec = 0;
    t.tv_usec = Resources::Instance()->getSettings()->getCCTimeout() * 1000;

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

ConnectionChecker::~ConnectionChecker()
{
	for ( std::vector< ConnectionTarget* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
		delete (*it);
	}
	targets.clear();
}

void ConnectionChecker::addTargets( wxString hostname, wxString port, wxString filename )
{
    mutex.Lock();
    targetsQueue[ filename ] = std::make_pair( hostname, port );
    mutex.Unlock();
}

void ConnectionChecker::getNewTargets()
{
    size_t counter = 0;
    mutex.Lock();
    /** add new targets to our processing thread from the queue **/
    for ( std::map< wxString, std::pair< wxString, wxString > >::iterator it = targetsQueue.begin(); it != targetsQueue.end(); ++it ) {
        targets.push_back( new ConnectionTarget( (*it).second.first, (*it).second.second, (*it).first ) );
        counter++;
        if ( counter < 10) {
            targetsQueue.erase( targetsQueue.begin() );
        } else {
            break;
        }
    }
    /** if there were no more targets in the queue, send an event to get more targets to the main thread **/
    if ( targets.empty() == true ) {
        wxCommandEvent evt_get_more_data( wxEVT_CONNECTION_CHECK_SEND_DATA, wxID_ANY );
        wxPostEvent( parent, evt_get_more_data );
    }

    mutex.Unlock();
}

void *ConnectionChecker::Entry()
{
    while ( TestDestroy() == false ) {
        mutex.Lock();
        bool queueEmpty = targets.empty();
        mutex.Unlock();
        if ( queueEmpty == true ) {
            /** get us 10 new targets **/
            getNewTargets();
            Sleep( 20 );
        } else {
            mutex.Lock();
            /** Connec to all our designated targets **/
            for ( std::vector< ConnectionTarget* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
                sock_addr.sin_port = htons(wxAtoi( (*it)->getPort() ) );
                sock_addr.sin_addr.s_addr = inet_addr( (*it)->getHostname().mb_str() );
                (*it)->socket = socket( AF_INET, SOCK_STREAM, 0 );
                ioctlsocket( (*it)->socket, FIONBIO, &socket_mode ); // Put the socket in non-blocking mode
                connect( (*it)->socket, (struct sockaddr*) &sock_addr, sizeof( struct sockaddr ) );
            }

            /** select() from all sockets and check if we're connected or not.. this will tell if the port is open or not. **/
            for ( std::vector< ConnectionTarget* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
                fd_set wfds;
                FD_ZERO(&wfds);
                FD_SET((*it)->socket, &wfds);

                if ( (*it)->socket > highest_fds ) {
                    highest_fds = (*it)->socket;
                }

                int retval = select( highest_fds+1, 0, &wfds, 0, &t );

                if ( retval <= 0 ) {
                    (*it)->setStatus( 0 );
                    closesocket( (*it)->socket );
                } else {
                    (*it)->setStatus( 1 );
                    closesocket( (*it)->socket );
                }
            }
            /** send event back to main thread about status of our connections **/
            for ( std::vector< ConnectionTarget* >::iterator it = targets.begin(); it != targets.end(); ) {
                wxCommandEvent evt( wxEVT_CONNECTION_CHECK_STATUS_UPDATE, wxID_ANY );
                evt.SetInt( (*it)->getStatus() );
                evt.SetString( (*it)->getFilename() );
                wxPostEvent( parent, evt );
                delete (*it);
                it = targets.erase( it );
            }
            mutex.Unlock();
        }
    }
    return 0;
}
