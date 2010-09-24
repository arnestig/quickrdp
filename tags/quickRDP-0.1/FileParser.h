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

#ifndef __FILE_PARSER__
#define __FILE_PARSER__

namespace FileParser
{
    wxString getStringFromFile( wxString searchPattern, std::vector<wxString> file )
    {
        for ( size_t index = 0; index < file.size(); index++ ) {
            int searchRet = file[ index ].Find( searchPattern );
            if ( searchRet != wxNOT_FOUND ) {
                return file[ index ].SubString( searchPattern.Len(), file[ index ].Len() );
            }
        }
        return wxT("");
    };

    int getIntegerFromFile( wxString searchPattern, std::vector<wxString> file )
    {
        for ( size_t index = 0; index < file.size(); index++ ) {
            int searchRet = file[ index ].Find( searchPattern );
            if ( searchRet != wxNOT_FOUND ) {
                return wxAtoi( file[ index ].SubString( searchPattern.Len(), file[ index ].Len() ) );
            }
        }
        return 0;
    };
}

#endif
