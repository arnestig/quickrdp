/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#ifndef __CONNECTIONCHECKER_H__
#define __CONNECTIONCHECKER_H__

#include <wx/string.h>
#include <vector>
#include "RDPDatabase.h"
#include <wx/event.h>
#include <map>

#if defined(__unix__)
	#include <netdb.h>
	#include <sys/socket.h>
	#include <sys/ioctl.h>
	#include <arpa/inet.h>
#elif defined(WIN32)
	#include <WinSock2.h>
    #include <windows.h>
    #include <wx/msw/winundef.h>
#endif

#if defined(__unix__)
    typedef int SOCKET;
    #define closesocket(i) close(i)
    #define ioctlsocket(i,l,ul) ioctl(i,l,ul)
#endif

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE( wxEVT_CONNECTION_CHECK_STATUS_UPDATE, -1 )
    DECLARE_EVENT_TYPE( wxEVT_CONNECTION_CHECK_SEND_DATA, -1 )
    DECLARE_EVENT_TYPE( wxEVT_CONNECTION_CHECKER_DONE, -1 )
END_DECLARE_EVENT_TYPES()

class ConnectionCheckerWorkerThread;

class ConnectionChecker : public wxThread
{
	friend class ConnectionCheckerWorkerThread;
    public:
        ConnectionChecker( wxEvtHandler *parent, unsigned int numWorkers, unsigned int timeout );
        ~ConnectionChecker();

        void addTargets( std::vector< RDPConnection* > newTargets );
        void postEvent( wxCommandEvent event );

    private:
        virtual void *Entry();

        void publishTarget( RDPConnection*& target );
		void threadDone( ConnectionCheckerWorkerThread *thread );
        unsigned int numWorkers; /** how many worker threads we will spawn **/
        unsigned int timeout; /** socket select timeout **/
        ConnectionCheckerWorkerThread *workerThreads[ 8 ];
        wxMutex mutex;
        std::map< long, RDPConnection* > targets;
        wxEvtHandler *parent;
        wxSemaphore *queue;
};

class ConnectionCheckerWorkerThread : public wxThread
{
    public:
        ConnectionCheckerWorkerThread( ConnectionChecker *parent, wxSemaphore *queue, unsigned int timeout );
        ~ConnectionCheckerWorkerThread();

    private:
        virtual void *Entry();

        unsigned int workCompleted;
        struct timeval t;
        struct sockaddr_in sock_addr;
        unsigned long socket_mode;
        ConnectionChecker *parent;
        wxSemaphore *queue;
        RDPConnection *target;
        SOCKET m_socket;
};

#endif
