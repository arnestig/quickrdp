/**
    Copyright (C) 2010-2013 QuickRDP - Manages RDP, telnet and SSH connections

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

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <wx/string.h>
#include <vector>
#include "ConnectionList.h"

class Settings
{
    public:
        Settings();
        ~Settings();

        void saveSettings();
        wxString getRDPExec( bool useAdminString = false ) const;
        wxString getTelnetExec() const;
        wxString getTelnetArgument() const;
        wxString getSSHExec() const;
        wxString getSSHArgument() const;
        wxString getVNCExec() const;
        wxString getVNCArgument() const;
        wxString getVersion() const;
        std::pair< int, int > getNewConnectionShortcut() const;
        std::pair< int, int > getDupConnectionShortcut() const;
        std::pair< int, int > getPropConnectionShortcut() const;
        std::pair< int, int > getSelectAllConnectionsShortcut() const;
        std::pair< int, int > getCommandDialogShortcut() const;
        std::pair< int, int > getManualCCShortcut() const;
        std::pair< int, int > getConnectWhenReadyShortcut() const;
        std::pair< int, int > getNewTabShortcut() const;
        std::pair< int, int > getCloseTabShortcut() const;

        void setNewConnectionShortcut( std::pair< int, int > value );
        void setDupConnectionShortcut( std::pair< int, int > value );
        void setPropConnectionShortcut( std::pair< int, int > value );
        void setSelectAllConnectionsShortcut( std::pair< int, int > value );
        void setCommandDialogShortcut( std::pair< int, int > value );
        void setManualCCShortcut( std::pair< int, int > value );
        void setConnectWhenReadyShortcut( std::pair< int, int > value );
        void setNewTabShortcut( std::pair< int, int > value );
        void setCloseTabShortcut( std::pair< int, int > value );

        void setTelnetExec( wxString telnetExec );
        void setTelnetArgument( wxString telnetArgument );
        void setSSHExec( wxString SSHExec );
        void setSSHArgument( wxString SSHArgument );
        void setVNCExec( wxString VNCExec );
        void setVNCArgument( wxString VNCArgument );
        void setVersion( wxString version );
        wxString getDataPath() const;
        wxString getSettingsPath() const;
        wxString getDatabasePath() const;
        wxString getCommandDatabasePath() const;

        int getMainFrameWidth() const;
        int getMainFrameHeight() const;
        void setMainFrameWidth( int mainFrameWidth );
        void setMainFrameHeight( int mainFrameHeight );

        int getCCTimeout() const;
        void setCCTimeout( int CCTimeout );
        int getCCUpdateInterval() const;
        void setCCUpdateInterval( int CCUpdateInterval );
        int getCCAutomaticCheck() const;
        void  setCCAutomaticCheck( int CCAutomaticCheck );
        unsigned int getCCWorkerThreads() const;
        void setCCWorkerThreads( unsigned int CCWorkerThreads );

        void setConnectionListColumns( int connectionListColumns );
        int getConnectionListColumns() const;
        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > getConnectionListColumMap() const;
        bool isConnectionListColumnActive( wxString columnName );

        int getConnectionListColumnWidth( int columnId ) const;
        void setConnectionListColumnWidths( std::vector< int > connectionListColumnWidths );

        /** return tabs saved from closing the application **/
        void setConnectionTabs( std::vector< wxString > connectionTabs );
        std::vector< wxString > getConnectionTabs() const;

        void setConnectionTabSelected( int selectedTab );
        int getConnectionTabSelected() const;

        bool getGreyListBackground() const;
        void setGreyListBackground( bool greyListBackground );


    private:
        void loadSettings();

        wxString RDPExec;
        wxString telnetExec;
        wxString SSHExec;
        wxString VNCExec;
        wxString telnetArgument;
        wxString SSHArgument;
        wxString VNCArgument;
        wxString settingsPath;
        wxString databasePath;
        wxString commandDatabasePath;
        wxString version;

        std::pair< int, int > newConnectionShortcut;
        std::pair< int, int > dupConnectionShortcut;
        std::pair< int, int > propConnectionShortcut;
        std::pair< int, int > selectAllConnectionsShortcut;
        std::pair< int, int > commandDialogShortcut;
        std::pair< int, int > manualccShortcut;
        std::pair< int, int > connectWhenReadyShortcut;
        std::pair< int, int > newTabShortcut;
        std::pair< int, int > closeTabShortcut;

        int mainFrameWidth;
        int mainFrameHeight;

        /** Connection checker settings **/
        int CCTimeout;
        int CCUpdateInterval;
        int CCAutomaticCheck;
        unsigned int CCWorkerThreads;

        int connectionListColumns;
        std::vector< int > connectionListColumnWidths;

        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap;

        /** connection tabs saved from closing the application  **/
        std::vector< wxString > connectionTabs;
        int selectedTab;

        /** styling features **/
        bool greyListBackground;
};

#endif
