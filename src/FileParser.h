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

#ifndef __FILE_PARSER__
#define __FILE_PARSER__

#include <fstream>

namespace FileParser
{
    inline wxString generateFilename()
    {
        wxString filename;
        const char hex[] = "ABCDEF0123456789";
        srand( time( NULL ) );
        for ( size_t index = 0; index < 8; index++ ) {
            filename.Append( wxString( &hex[ rand() % 16 ] , wxConvUTF8, 1 ) );
        }

        return filename;
    }

    inline void writeLineToFile( std::ofstream &file, wxString line )
    {
        file.write( line.mb_str(), line.Len() );
        file.write( "\r\n", 2 );
    }

    inline wxString getStringFromFile( wxString searchPattern, std::vector<wxString> file )
    {
        for ( size_t index = 0; index < file.size(); index++ ) {
            int searchRet = file[ index ].Find( searchPattern );
            if ( searchRet != wxNOT_FOUND ) {
                return file[ index ].SubString( searchPattern.Len(), file[ index ].Len() );
            }
        }
        return wxT("");
    };

    inline wxString getIntegerFromFile( wxString searchPattern, std::vector<wxString> file )
    {
        for ( size_t index = 0; index < file.size(); index++ ) {
            int searchRet = file[ index ].Find( searchPattern );
            if ( searchRet != wxNOT_FOUND ) {
                return file[ index ].SubString( searchPattern.Len(), file[ index ].Len() );
            }
        }
        return wxT("0");
    };

    inline wxString getRealArgumentString( wxString argument, RDPConnection* connection )
    {
        /** check if our argument is empty and inside a conditional output '{ }'. If so, we remove that from the argument **/
        std::vector< std::pair< wxString, wxString > > strings_to_parse;
        strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%hostname%"), connection->getHostname() ) );
        strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%connectiontype%"), ConnectionType::getConnectionTypeName( connection->getConnectionType() ) ) );
        strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%username%"), connection->getUsername() ) );
        strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%password%"), connection->getPassword() ) );

        for ( size_t stringId = 0; stringId < strings_to_parse.size(); ++stringId ) {
            if ( strings_to_parse[ stringId ].second.empty() == true ) {
                size_t foundPos = argument.find_first_of( wxT("{") );
                while ( foundPos != std::string::npos && foundPos < argument.length() ) {
                    size_t string_to_replace = argument.find( strings_to_parse[ stringId ].first, foundPos+1 );
                    size_t foundPosEnd = argument.find_first_of( wxT("}"), foundPos+1 );
                    if ( string_to_replace > foundPos && string_to_replace < foundPosEnd ) {
                        argument.erase( foundPos, foundPosEnd-foundPos+1 );
                    }
                    foundPos = argument.find_first_of( wxT("{"), foundPos+1 );
                }
            }
        }

        argument.Replace( wxT("{" ), wxT("") );
        argument.Replace( wxT("}" ), wxT("") );
        argument.Replace( wxT("%hostname%"), connection->getHostname()  );
        argument.Replace( wxT("%connectiontype%"), ConnectionType::getConnectionTypeName( connection->getConnectionType() ) );
        argument.Replace( wxT("%username%"), connection->getUsername() );
        argument.Replace( wxT("%password%"), connection->getPassword() );
        return argument;
    }
}

#endif
