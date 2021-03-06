/**
    Copyright (C) 2010-2016 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#ifndef __QUICKRDP_FUNCTIONS__
#define __QUICKRDP_FUNCTIONS__

#include <wx/listctrl.h>
#include "RDPDatabase.h"
#include "CommandDatabase.h"
#include "Resources.h"
#include <fstream>
#include <sstream>

#include <iostream>

namespace quickRDP
{
    namespace Generators
    {
        inline wxString generateHex( unsigned int length )
        {
            wxString filename;
            const char hex[] = "ABCDEF0123456789";
            for ( size_t index = 0; index < length; index++ ) {
                filename.Append( wxString( &hex[ rand() % 16 ] , wxConvUTF8, 1 ) );
            }

            return filename;
        }

        inline long generateInt( unsigned int length )
        {
            std::stringstream ss;
            for ( size_t index = 0; index < length; index++ ) {
                ss << rand() % 10;
            }
            return atoi( ss.str().c_str() );
        }
    }

    namespace FileParser
    {
        inline unsigned int getIpValue( const char* ip )
        {
            int a, b, c, d;
            unsigned int addr = 0;

            if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) != 4) {
                return 0;
            }

            addr = a << 24;
            addr |= b << 16;
            addr |= c << 8;
            addr |= d;
            return addr;
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

        inline std::vector< wxString > getStringVectorFromFile( wxString searchPattern, std::vector< wxString > file )
        {
            std::vector< wxString > retVec;
            for ( size_t index = 0; index < file.size(); index++ ) {
                int searchRet = file[ index ].Find( searchPattern );
                if ( searchRet != wxNOT_FOUND ) {
                    retVec.push_back( file[ index ].SubString( searchPattern.Len(), file[ index ].Len() ) );
                }
            }
            return retVec;
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

        inline std::vector< int > getIntegerVectorFromFile( wxString searchPattern, std::vector< wxString > file )
        {
            std::vector< int > retVec;
            for ( size_t index = 0; index < file.size(); index++ ) {
                int searchRet = file[ index ].Find( searchPattern );
                if ( searchRet != wxNOT_FOUND ) {
                    retVec.push_back( wxAtoi( file[ index ].SubString( searchPattern.Len(), file[ index ].Len() ) ) );
                }
            }
            return retVec;
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
            strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%hostname%"), wxString( connection->getHostname().c_str() ) ) );
            strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%connectiontype%"), ConnectionType::getConnectionTypeName( connection->getConnectionType() ) ) );
            strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%username%"), connection->getUsername() ) );
            strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%password%"), connection->getPassword() ) );
            strings_to_parse.push_back( std::pair< wxString, wxString> ( wxT("%port%"), wxString::Format( wxT("%i"), connection->getPort() ) ) );


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
            argument.Replace( wxT("%hostname%"), connection->getHostname() );
            argument.Replace( wxT("%connectiontype%"), ConnectionType::getConnectionTypeName( connection->getConnectionType() ) );
            argument.Replace( wxT("%username%"), connection->getUsername() );
            argument.Replace( wxT("%password%"), connection->getPassword() );
            argument.Replace( wxT("%port%"), wxString::Format( wxT("%i"), connection->getPort() ) );
            return argument;
        }

        inline bool searchForString( std::string str, std::string pattern )
        {
            if ( pattern.empty() == true ) {
                return true;
            }

            /** Tokenize our pattern string based on | characters. This will cause us to look for any of these patterns when searching later on. **/
            std::vector< std::string > patterns;
            bool retVal = false;
            char *pch;
            char *tempPattern = new char[ pattern.size()+1 ];
            strcpy( tempPattern, pattern.c_str() );
            pch = strtok( tempPattern, "|" );
            while ( pch != NULL ) {
                patterns.push_back( std::string( pch ) );
                pch = strtok( NULL, "|" );
            }
            delete []tempPattern;

            for ( std::vector< std::string >::const_iterator it = patterns.begin(); it != patterns.end(); ++it ) {
                /** locate our first wildcard (if any) **/
                size_t wildcardPos = (*it).find( "*" );

                /** load up our pattern list with the first word. **/
                size_t foundPos = str.find( (*it).substr( 0, wildcardPos ) );
                if ( foundPos != std::string::npos ) {
                    retVal = true;
                }

                while ( wildcardPos != std::string::npos )
                {
                    std::string substring = "";
                    wildcardPos++;

                    /** locate our wildcards and get the subpatterns between them **/
                    size_t nextWildcard = (*it).find( "*", wildcardPos );
                    if ( nextWildcard == std::string::npos ) {
                        substring = (*it).substr( wildcardPos, nextWildcard );
                    } else {
                        substring = (*it).substr( wildcardPos, nextWildcard-wildcardPos );
                    }

                    /** now search the string using the pattern we found **/
                    foundPos = str.find( substring, foundPos );
                    if ( foundPos != std::string::npos ) {
                        retVal = true;
                    }

                    wildcardPos = (*it).find( "*", wildcardPos );
                }
            }
            return retVal;
        }
    }

    namespace Connections
    {
        inline bool getSelectedConnectionRect( wxListCtrl *listCtrl, wxRect &rect )
        {
            if ( listCtrl->GetSelectedItemCount() > 0 ) {
                long itemIndex = -1;
                itemIndex = listCtrl->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
                return listCtrl->GetItemRect( itemIndex, rect );
            }
            return false;
        }

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

    namespace Shortcuts
    {
        inline bool IsCombinationInUse( std::pair< int, int > shortcut, wxString &shortcutName )
        {
            Settings* settings = Resources::Instance()->getSettings();
            std::vector< Command* > commands = Resources::Instance()->getCommandDatabase()->getCommands();
            for ( std::vector< Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
                std::pair< int, int > curCommandShortcut = std::make_pair( (*it)->getShortcutKey(), (*it)->getShortcutModifier() );
                if ( curCommandShortcut == shortcut ) {
                    shortcutName = wxT("command ") + (*it)->getName();
                    return true;
                }
            }

            if ( shortcut == settings->getNewConnectionShortcut() ) {
                shortcutName = wxT("shortcut 'New connection'");
                return true;
            }
            if ( shortcut == settings->getDupConnectionShortcut() ) {
                shortcutName = wxT("shortcut 'Duplicate connection'");
                return true;
            }
            if ( shortcut == settings->getPropConnectionShortcut() ) {
                shortcutName = wxT("shortcut 'Connection properties'");
                return true;
            }
            if ( shortcut == settings->getSelectAllConnectionsShortcut() ) {
                shortcutName = wxT("shortcut 'Select all connection'");
                return true;
            }
            if ( shortcut == settings->getCommandDialogShortcut() ) {
                shortcutName = wxT("shortcut 'Commands dialog'");
                return true;
            }
            if ( shortcut == settings->getManualCCShortcut() ) {
                shortcutName = wxT("shortcut 'Manual connection check'");
                return true;
            }
            if ( shortcut == settings->getConnectWhenReadyShortcut() ) {
                shortcutName = wxT("shortcut 'Connect when ready'");
                return true;
            }
            if ( shortcut == settings->getNewTabShortcut() ) {
                shortcutName = wxT("shortcut 'Open new tab'");
                return true;
            }
            if ( shortcut == settings->getCloseTabShortcut() ) {
                shortcutName = wxT("shortcut 'Close current tab'");
                return true;
            }
            return false;
        }

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

        inline bool IsValidKeycode( int keycode ) {
            if ( ( keycode < 256 && wxIsalnum( keycode ) ) || ( keycode >= WXK_F1 && keycode <= WXK_F12 ) || ( keycode == WXK_TAB ) ) {
                return true;
            } else {
                return false;
            }
        }
    }
}
#endif
