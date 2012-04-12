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

#ifndef __COMMAND_DATABASE__H_
#define __COMMAND_DATABASE__H_

#include <wx/string.h>
#include <map>
#include <vector>
#include "RDPDatabase.h"

class Command
{
    public:
        Command( wxString name, wxString program, wxString argument, bool favorite, bool safety );
        ~Command();

        wxString getName() const;
        wxString getProgram() const;
        wxString getArgument() const;
        bool getFavorite() const;
        bool getSafety() const;

        void setName( wxString name );
        void setProgram( wxString program );
        void setArgument( wxString argument );
        void setFavorite( bool favorite );
        void setSafety( bool safety );
        bool execute( RDPConnection *connection );

    private:
        wxString name;
        wxString program;
        wxString argument;
        bool favorite;
        bool safety;
};

class CommandDatabase
{
    public:
        CommandDatabase();
        ~CommandDatabase();

        std::vector< Command* > getCommands();
        Command* getCommand( wxString name );
        void deleteCommand( wxString name );
        void saveCommand( wxString name, wxString program, wxString argument, bool favorite, bool safety );

    private:
        void loadDatabase();
        bool isDatabaseLoaded() const;
        bool addCommand( wxString name );
        std::vector< Command* > commands;
};

#endif
