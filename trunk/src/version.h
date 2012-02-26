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

#ifndef __VERSION_H__
#define __VERSION_H__

#ifndef SVN_REVISION
#define SVN_REVISION 0
#endif

namespace Version {
	static wxString name = wxT("QuickRDP");
	static wxString version = wxT("1.1.5");

	inline wxString getShortVersion()
	{
	    return name + wxT(" ") + version;
	}

	inline wxString getLongVersion()
	{
	    wxString retval = version;
	    if ( SVN_REVISION > 0 ) {
            retval << wxT("-") + wxString::Format( wxT("%d"), SVN_REVISION );
	    }
	    return retval;
	}
};

#endif
