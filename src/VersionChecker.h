/**
    Copyright (C) 2010-2015 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

    Written by Tobias Eliasson <arnestig@gmail.com>.

    This file is part of quickRDP <https://github.com/arnestig/quickrdp>.

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

#ifndef __VERSIONCHECKER_H__
#define __VERSIONCHECKER_H__

#include <wx/string.h>
#include <curl/curl.h>
#include <iostream>
#include <vector>
#include <wx/thread.h>
#include <wx/event.h>
#include <wx/filename.h>
#include <fstream>

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE( wxEVT_VERSION_CHECK_DONE, -1 )
    DECLARE_EVENT_TYPE( wxEVT_AUTOMATIC_VERSION_CHECK_DONE, -1 )
    DECLARE_EVENT_TYPE( wxEVT_VERSION_DOWNLOAD_COMPLETE, -1 )
END_DECLARE_EVENT_TYPES()

class VersionCheckerWorker;

enum TaskType
{
    AUTOMATIC_CHECK,
    MANUAL_CHECK,
    DOWNLOAD_BINARY
};

class VersionChecker
{
	friend class VersionCheckerWorker;
    public:
        VersionChecker( wxEvtHandler *parent );
        ~VersionChecker();

        void checkForNewVersion( TaskType taskType, std::string url = "" );

    private:
		void workerThreadDone( VersionCheckerWorker *thread );
		void postEvent( wxCommandEvent event );
		void setNewVersionURL( wxString newVersionURL );
		wxString getNewVersionURL();
		std::vector< VersionCheckerWorker* > workerThreads;
		wxMutex mutex;
		wxString newVersionURL;

        wxEvtHandler *parent;
};

class VersionCheckerWorker : public wxThread
{
    public:
        VersionCheckerWorker( VersionChecker *parent, std::string url, TaskType taskType );
        ~VersionCheckerWorker();

    private:
        static int writer( char *data, size_t size, size_t nmemb, std::string *buffer_in );
        std::string get( const char* url );
        bool execute( wxString &version );
        bool download( wxString versionurl, wxString &filename );
        virtual void *Entry();
		VersionChecker *parent;

		std::string url;
		TaskType taskType;
};

#endif
