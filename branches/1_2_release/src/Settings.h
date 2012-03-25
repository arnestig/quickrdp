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
        wxString getPerlExec() const;
        wxString getPerlArgument() const;
        void setTelnetExec( wxString telnetExec );
        void setTelnetArgument( wxString telnetArgument );
        void setSSHExec( wxString SSHExec );
        void setSSHArgument( wxString SSHArgujment );
        void setPerlExec( wxString perlExec );
        void setPerlArgument( wxString perlArgument );
        wxString getDataPath() const;
        wxString getSettingsPath() const;
        wxString getDatabasePath() const;
        wxString getPerlDatabasePath() const;
        wxString getCommandDatabasePath() const;

        int getMainFrameWidth() const;
        int getMainFrameHeight() const;
        void setMainFrameWidth( int mainFrameWidth );
        void setMainFrameHeight( int mainFrameHeight );

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
        wxString perlExec;
        wxString telnetArgument;
        wxString SSHArgument;
        wxString perlArgument;
        wxString settingsPath;
        wxString databasePath;
        wxString perlDatabasePath;
        wxString commandDatabasePath;

        int mainFrameWidth;
        int mainFrameHeight;

        int column0Width;
        int column1Width;
        int column2Width;
        int column3Width;
        int column4Width;
        int column5Width;
};

#endif
