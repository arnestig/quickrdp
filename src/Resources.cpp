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

#include "Resources.h"
#include "quickRDPApp.h"
#include <wx/msgdlg.h>

Resources* Resources::instance = NULL;

Resources::Resources()
    :   settings( NULL ),
        connectionDatabase( NULL ),
        commandDatabase( NULL ),
        connectionChecker( NULL ),
		versionChecker( NULL )
{
    settings = new Settings();
    connectionDatabase = new RDPDatabase();
    commandDatabase = new CommandDatabase();
}

Resources::~Resources()
{
	/** check that connection checker has exited cleanly **/
	connectionChecker->Delete();
	while ( true ) {
		/** make sure we process events here, since the thread will signal with an event when done **/
		wxTheApp->ProcessPendingEvents();
		if ( connectionChecker == NULL ) {
			break;
		}
		wxMilliSleep( 1 );
	}

	delete settings;
	delete connectionDatabase;
	delete commandDatabase;
	delete versionChecker;
}

void Resources::DestroyInstance()
{
    delete instance;
    instance = NULL;
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

VersionChecker* Resources::getVersionChecker() const
{
    return versionChecker;
}

RDPDatabase* Resources::getConnectionDatabase() const
{
    return connectionDatabase;
}

CommandDatabase* Resources::getCommandDatabase() const
{
    return commandDatabase;
}

ConnectionChecker* Resources::getConnectionChecker() const
{
    return connectionChecker;
}

void Resources::removeConnectionCheckerThread()
{
	connectionChecker = NULL;
}

void Resources::addVersionChecker( wxEvtHandler *parent )
{
	versionChecker = new VersionChecker( parent );
}

void Resources::addConnectionChecker( wxEvtHandler *parent )
{
    if ( connectionChecker == NULL ) {
        connectionChecker = new ConnectionChecker( parent, settings->getCCWorkerThreads(), settings->getCCTimeout() * 1000 );
        if ( connectionChecker->Create() != wxTHREAD_NO_ERROR ) {
            delete connectionChecker;
            connectionChecker = NULL;
            wxMessageBox( wxT("Error creating ConnectionChecker!"), wxT("Error!") );
        } else {
            if ( connectionChecker->Run() != wxTHREAD_NO_ERROR ) {
                delete connectionChecker;
                connectionChecker = NULL;
                wxMessageBox( wxT("Error while running ConnectionChecker!") );
            }
        }
    }
}

