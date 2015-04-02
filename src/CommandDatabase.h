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

#ifndef __COMMAND_DATABASE__H_
#define __COMMAND_DATABASE__H_

#include <wx/string.h>
#include <map>
#include <vector>
#include "RDPDatabase.h"

class Command
{
    public:
        Command( wxString name, std::map< int, wxString > program, std::map< int, wxString > argument, wxString filename, bool favorite, bool safety, int shortcutModifier, int shortcutKey, bool useSpecificCommands );
        ~Command();

        wxString getName() const;
        std::map< int, wxString > getProgram( );
        wxString getProgramByConnection( ConnectionType::ConnectionType connectionType );
        std::map< int, wxString > getArgument();
        wxString getArgumentByConnection( ConnectionType::ConnectionType connectionType );
        wxString getFilename() const;
        bool getFavorite() const;
        bool getSafety() const;
        int getShortcutModifier() const;
        int getShortcutKey() const;
        bool getUseSpecificCommands() const;

        void setName( wxString name );
        void setProgram( std::map< int, wxString > program );
        void setArgument( std::map< int, wxString > argument );
        void setFavorite( bool favorite );
        void setSafety( bool safety );
        void setShortcutModifier( int shortcutModifier );
        void setShortcutKey( int shortcutKey );
        void setUseSpecificCommands( bool useSpecificCommands );

        wxString loadCustomArguments( wxString &argument );

        bool execute( RDPConnection *connection );

    private:
        wxString name;
        std::map< int, wxString > program;
        std::map< int, wxString > argument;
        wxString filename;
        bool favorite;
        bool safety;
        int shortcutModifier;
        int shortcutKey;
        bool useSpecificCommands;
};

class CommandDatabase
{
    public:
        CommandDatabase();
        ~CommandDatabase();

        std::vector< Command* > getCommands( bool forceReload = false );
        Command* getCommand( wxString name );
        Command* getCommandWithShortcut( int shortcutModifier, int shortcutKey );
        void deleteCommand( wxString name );
        void saveCommand( Command *command );
        void saveCommand( wxString name, std::map< int, wxString > program, std::map< int, wxString > argument, bool favorite, bool safety, int shortcutModifier, int shortcutKey, bool useSpecificCommands );

    private:
        void loadDatabase();
        bool isDatabaseLoaded() const;
        bool addCommand( wxString name );
        std::vector< Command* > commands;
};

#endif
