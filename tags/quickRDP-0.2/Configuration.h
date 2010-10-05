/**
    Copyright (C) 2010 quickRDP - Remote desktop organizer

    Written by Tobias Eliasson <arnestig@users.sourceforge.net>.

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

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <wx/stdpaths.h>
#include <memory>

namespace Configuration
{
    inline wxString getExecString( bool useAdminString = false )
    {
        #if defined(__WXMSW__)
            if ( useAdminString == true ) {
                return wxT("mstsc /admin ");
            } else {
                return wxT("mstsc ");
            }
        #elif defined(__UNIX__)
            return wxT("tsclient -x ");
        #endif
    };

    inline wxString getDatabaseFolder()
    {
        #if defined(__WXMSW__)
        return wxStandardPathsBase::Get().GetUserDataDir() + wxT("\\");
        #elif defined(__UNIX__)
        return wxStandardPathsBase::Get().GetUserDataDir() + wxT("/");
        #endif
    };
}

#endif
