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
        RDPConnection( wxString filename, RDPConnection *copy );
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
        wxString getDesktopBpp() const;
        wxString getScreenMode() const;
        wxString getConsole() const;
        wxString getSoundMode() const;
        wxString getDiskMapping() const;

        // special string returns for the connection
        wxString getResolutionString() const;
        wxString getDomainUsernameString() const;
        wxString getColorsString() const;

        void connect();

        void setHostname( wxString hostname );
        void setUsername( wxString username );
        void setPassword( wxString password );
        void setDomain( wxString domain );
        void setComment( wxString comment );
        void setClientHostname( wxString clienthostname );
        void setDesktopHeight( wxString desktopheight );
        void setDesktopWidth( wxString desktopwidth );
        void setDesktopBpp( wxString desktopbpp );
        void setScreenMode( wxString screenmode );
        void setConsole( wxString console );
        void setSoundMode( wxString soundmode );
        void setDiskMapping( wxString diskmapping );

        void saveFile();

        bool doesRDPHasString( wxString searchString ) const;

    private:
        void parseFile();
        void writeLineToFile( std::ofstream &file, wxString line );
        wxString filename, hostname, comment, username, password, domain, clienthostname, desktopheight, desktopwidth, desktopbpp, console, screenmode, soundmode, diskmapping;
};

class RDPDatabase
{
    public:
        RDPDatabase();
        ~RDPDatabase();
        RDPConnection *addRDPConnection( wxString filename );
        RDPConnection *duplicateRDPConnection( wxString filename, RDPConnection *copy );
        RDPConnection *getRDPConnectionByPointer( RDPConnection *rdpConnection );
        void deleteRDPConnectionByPointer( RDPConnection *rdpConnection );
        std::vector<RDPConnection*> getDatabase();
        void sortById( int id );
        bool isSortOrderAscending() const;
        void setSortOrder( bool database_sort_ascending );

    private:
        bool database_sort_ascending;
        void loadRDPFiles();
        std::vector<RDPConnection*> database;

        static bool hostnameCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getHostname().Lower() < right->getHostname().Lower();
        }

        static bool hostnameCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getHostname().Lower() > right->getHostname().Lower();
        }

        static bool usernameCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getDomainUsernameString().Lower() < right->getDomainUsernameString().Lower();
        }

        static bool usernameCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getDomainUsernameString().Lower() > right->getDomainUsernameString().Lower();
        }

        static bool useConsoleCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getConsole().Lower() < right->getConsole().Lower();
        }

        static bool useConsoleCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getConsole().Lower() > right->getConsole().Lower();
        }

        static bool resolutionCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getResolutionString().Lower() < right->getResolutionString().Lower();
        }

        static bool resolutionCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getResolutionString().Lower() > right->getResolutionString().Lower();
        }

        static bool commentCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getComment().Lower() < right->getComment().Lower();
        }

        static bool commentCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getComment().Lower() > right->getComment().Lower();
        }
};
#endif
