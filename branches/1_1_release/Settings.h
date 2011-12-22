/**
    Copyright (C) 2010 quickRDP - Remote desktop organizer

    Written by Tobias Eliasson <arnestig@users.sourceforge.net>.

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
        wxString getPuttyExec() const;
        wxString getPerlExec() const;
        void setPerlExec( wxString plinkExec );
        void setPuttyExec( wxString puttyExec );
        wxString getSettingsPath() const;
        wxString getDatabasePath() const;
        wxString getPerlDatabasePath() const;

    private:
        void loadSettings();

        wxString RDPExec;
        wxString puttyExec;
        wxString perlExec;
        wxString settingsPath;
        wxString databasePath;
        wxString perlDatabasePath;
};

#endif
