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

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <wx/string.h>

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
        std::pair< int, int > getCommandDialogShortcut() const;
        std::pair< int, int > getManualCCShortcut() const;

        void setNewConnectionShortcut( std::pair< int, int > value );
        void setDupConnectionShortcut( std::pair< int, int > value );
        void setPropConnectionShortcut( std::pair< int, int > value );
        void setCommandDialogShortcut( std::pair< int, int > value );
        void setManualCCShortcut( std::pair< int, int > value );

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

        /** column functions. will be replaced in 1.2 or 1.3 once dynamic columns are in place **/
        void setColumn0Width( int column0Width );
        void setColumn1Width( int column1Width );
        void setColumn2Width( int column2Width );
        void setColumn3Width( int column3Width );
        void setColumn4Width( int column4Width );
        void setColumn5Width( int column5Width );

        int getColumn0Width() const;
        int getColumn1Width() const;
        int getColumn2Width() const;
        int getColumn3Width() const;
        int getColumn4Width() const;
        int getColumn5Width() const;


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
        std::pair< int, int > commandDialogShortcut;
        std::pair< int, int > manualccShortcut;

        int mainFrameWidth;
        int mainFrameHeight;

        /** Connection checker settings **/
        int CCTimeout;
        int CCUpdateInterval;
        int CCAutomaticCheck;

        /** frame and column settings **/
        int column0Width;
        int column1Width;
        int column2Width;
        int column3Width;
        int column4Width;
        int column5Width;
};

#endif
