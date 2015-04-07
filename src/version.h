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

#ifndef __VERSION_H__
#define __VERSION_H__

#ifndef GIT_HASH
#define GIT_HASH ""
#endif

#include <curl/curlver.h>

namespace Version {
	static wxString name = wxT("QuickRDP");
	static wxString version = wxT("2.4.2");

	inline wxString getNumericVersion()
	{
	    return version;
	}

	inline wxString getShortVersion()
	{
	    return name + wxT(" ") + version;
	}

	inline wxString getLongVersion()
	{
	    wxString retval = version;
        wxString gitHash( GIT_HASH, wxConvUTF8 );
        if ( gitHash.length() > 0 ) {
            retval << wxT("-") + gitHash;
        }
	    return retval;
	}

	inline wxString getwxWidgetsVersion()
	{
	    return wxVERSION_STRING;
	}

	inline wxString getgccVersion()
	{
	    return wxString::Format( wxT("gcc %d.%d.%d"), __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__ );
	}

	inline wxString getlibcurlVersion()
	{
	    return wxString::Format( wxT("libcurl %d.%d.%d"), LIBCURL_VERSION_MAJOR, LIBCURL_VERSION_MINOR, LIBCURL_VERSION_PATCH );
	}
};

#endif
