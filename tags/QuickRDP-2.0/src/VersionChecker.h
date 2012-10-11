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

#ifndef __VERSIONCHECKER_H__
#define __VERSIONCHECKER_H__

#include <wx/string.h>
#include <curl/curl.h>
#include <iostream>
#include <wx/thread.h>
#include <wx/event.h>

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE( wxEVT_VERSION_CHECK_DONE, -1 )
    DECLARE_EVENT_TYPE( wxEVT_AUTOMATIC_VERSION_CHECK_DONE, -1 )
END_DECLARE_EVENT_TYPES()

class VersionChecker : public wxThread
{
    public:
        VersionChecker( wxEvtHandler *parent, std::string url, bool automatic_check = true );
        ~VersionChecker();

    private:
        static int writer( char *data, size_t size, size_t nmemb, std::string *buffer_in );
        std::string get( const char* url );
        bool execute( wxString &version);
        virtual void *Entry();

        wxEvtHandler *parent;
        std::string url;
        bool automatic_check;
};

#endif
