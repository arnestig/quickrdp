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

#include <vector>
#include <wx/wx.h>

#ifndef __RDP_DATABASE_H__
#define __RDP_DATABASE_H__

class RDPConnection
{
    public:
        RDPConnection( wxString filename );
        ~RDPConnection();

        wxString getFilename() const;
        wxString getHostname() const;
        wxString getUsername() const;
        wxString getPassword() const;
        wxString getDomain() const;
        wxString getComment() const;
        wxString getClientHostname() const;
        wxString getDesktopHeight() const;
        wxString getDesktopWidth() const;
        wxString getScreenMode() const;
        wxString getConsole() const;

        void connect();

        bool operator<(const wxString& hostname1) const {
            return getHostname() > hostname1;
        }

        void setHostname( wxString hostname );
        void setUsername( wxString username );
        void setPassword( wxString password );
        void setDomain( wxString domain );
        void setComment( wxString comment );
        void setClientHostname( wxString clienthostname );
        void setDesktopHeight( wxString desktopheight );
        void setDesktopWidth( wxString desktopwidth );
        void setScreenMode( wxString screenmode );
        void setConsole( wxString console );

        void saveFile();

    private:
        void parseFile();
        void writeLineToFile( std::ofstream &file, wxString line );
        wxString filename, hostname, comment, username, password, domain, clienthostname, desktopheight, desktopwidth, console, screenmode ;
};

class RDPDatabase
{
    public:
        RDPDatabase();
        ~RDPDatabase();
        RDPConnection *addRDPConnection( wxString filename );
        RDPConnection *getRDPConnectionById( size_t id );
        void deleteRDPConnectionById( size_t id );
        void deleteRDPConnectionByPointer( RDPConnection *rdpConnection );
        std::vector<RDPConnection*> getDatabase();

    private:
        void loadRDPFiles();

        std::vector<RDPConnection*> database;
};

#endif
