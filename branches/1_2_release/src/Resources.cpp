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

#include "Resources.h"

Resources* Resources::instance = NULL;

Resources::Resources()
    :   settings( NULL ),
        connectionDatabase( NULL ),
        perlDatabase( NULL ),
        commandDatabase( NULL )
{
    settings = new Settings();
    connectionDatabase = new RDPDatabase();
    perlDatabase = new PerlDatabase();
    commandDatabase = new CommandDatabase();
}

Resources* Resources::Instance()
{
    if ( instance == NULL ) {
        instance = new Resources();
    }
    return instance;
}

Settings* Resources::getSettings() const
{
    return settings;
}

RDPDatabase* Resources::getConnectionDatabase() const
{
    return connectionDatabase;
}

PerlDatabase* Resources::getPerlDatabase() const
{
    return perlDatabase;
}

CommandDatabase* Resources::getCommandDatabase() const
{
    return commandDatabase;
}

