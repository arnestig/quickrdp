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

#ifndef __QUICKRDP_FUNCTIONS__
#define __QUICKRDP_FUNCTIONS__

#include <wx/listctrl.h>
#include "RDPDatabase.h"
#include "Resources.h"
#include <fstream>

namespace quickRDP
{
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

        inline int getIntegerFromFile( wxString searchPattern, std::vector<wxString> file )
        {
            wxString retVal = getStringFromFile( searchPattern, file );
            if ( retVal == wxT("") ) {
                return 0;
            } else {
                return wxAtoi( retVal );
            }
        };

        inline bool getBoolFromFile( wxString searchPattern, std::vector<wxString> file )
        {
            wxString retVal = getStringFromFile( searchPattern, file );
            if ( retVal == wxT("") ) {
                return false;
            } else {
                return bool( wxAtoi( retVal ) );
            }
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

        inline bool searchForString( std::string str, std::string pattern )
        {
            /** locate our first wildcard (if any) **/
            size_t wildcardPos = pattern.find( "*" );
            size_t foundPos = 0;

            /** load up our pattern list with the first word. **/
            foundPos = str.find( pattern.substr( 0, wildcardPos ), foundPos );
            if ( foundPos == std::string::npos ) {
                return false;
            }

            while ( wildcardPos != std::string::npos )
            {
                std::string substring = "";
                wildcardPos++;

                /** locate our wildcards and get the subpatterns between them **/
                size_t nextWildcard = pattern.find( "*", wildcardPos );
                if ( nextWildcard == std::string::npos ) {
                    substring = pattern.substr( wildcardPos, nextWildcard );
                } else {
                    substring = pattern.substr( wildcardPos, nextWildcard-wildcardPos );
                }

                /** now search the string using the pattern we found **/
                foundPos = str.find( substring, foundPos );
                if ( foundPos == std::string::npos ) {
                    return false;
                }

                wildcardPos = pattern.find( "*", wildcardPos );
            }

            return true;
        }

    }

    namespace Connections
    {
        inline RDPConnection *getSelectedConnection( wxListCtrl *listCtrl )
        {
            if ( listCtrl->GetSelectedItemCount() > 0 ) {
                long itemIndex = -1;
                itemIndex = listCtrl->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
                if ( itemIndex == -1 ) {
                    return NULL;
                }
                return Resources::Instance()->getConnectionDatabase()->getRDPFromListCtrl( itemIndex );
            }
            return NULL;
        }

        inline std::vector< RDPConnection* > getAllSelectedConnections( wxListCtrl *listCtrl )
        {
            std::vector< RDPConnection* > retVec;
            if ( listCtrl->GetSelectedItemCount() > 0 ) {
                long itemIndex = -1;
                for ( ;; ) {
                    itemIndex = listCtrl->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
                    if ( itemIndex == -1 ) {
                        break;
                    }

                    retVec.push_back( Resources::Instance()->getConnectionDatabase()->getRDPFromListCtrl( itemIndex ) );

                }
            }
            return retVec;
        }
    }

    namespace Keybinder
    {
        inline wxString ModifierString( int modmask )
        {
            wxString retval;

            if ( modmask & wxMOD_ALT ) {
                retval << wxT("Alt+");
            }

            if (modmask & wxMOD_CONTROL)
            {
                retval << wxT("Ctrl+");
            }

            if (modmask & wxMOD_SHIFT)
            {
                retval << wxT("Shift+");
            }
            return retval;
        }

        inline wxString KeycodeString( int keycode )
        {
            wxString retval;

            switch (keycode) {

                /** F1 - F12 **/
                case WXK_F1: case WXK_F2: case WXK_F3: case WXK_F4: case WXK_F5: case WXK_F6: case WXK_F7: case WXK_F8: case WXK_F9: case WXK_F10: case WXK_F11: case WXK_F12:
                    retval << wxT('F') << keycode - WXK_F1 + 1;
                break;

                default:
                /** ASCI chars **/
                if ( keycode < 256 && wxIsalnum( keycode ) ) {
                    retval << (wxChar)keycode;
                }
                break;
            }

            return retval;
        }
    }
}
#endif
