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

#include <vector>
#include <wx/string.h>
#include <wx/thread.h>

#ifndef __RDP_DATABASE_H__
#define __RDP_DATABASE_H__

namespace ConnectionType
{
    enum ConnectionType
    {
        RDP,
        TELNET,
        SSH,
        VNC
    };

    inline wxString getConnectionTypeName( ConnectionType::ConnectionType connectionType )
    {
        switch ( connectionType )
        {
            default:
            case ConnectionType::RDP:
                return wxT("Remote Desktop");
            break;
            case ConnectionType::TELNET:
                return wxT("Telnet");
            break;
            case ConnectionType::SSH:
                return wxT("SSH");
            break;
            case ConnectionType::VNC:
                return wxT("VNC");
        }
    }
}

class RDPConnection
{
    public:
        RDPConnection( std::string filename );
        RDPConnection( std::string filename, RDPConnection *copy );
        ~RDPConnection();

        ConnectionType::ConnectionType getConnectionType() const;
        void getFilename( std::string &filename );
        wxString getFilename();
        void getHostname( std::string &hostname );
        wxString getHostname();
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
        int getPort();
        int getPortTrueValue(); // difference between getPort() and getPortTrueValue() is that TrueValue will return -1 if the connection is using the default values */
        int getConnectionStatus() const;
        bool isConnectionCheckerRunning() const;
        long getLastChecked() const;
        void Lock(); /** for mutex locking **/
        void Unlock(); /** for mutex locking **/

        // special string returns for the connection
        wxString getResolutionString() const;
        wxString getDomainUsernameString() const;
        wxString getColorsString() const;

        void connect();

        void setConnectionType( ConnectionType::ConnectionType connectionType );
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
        void setPort( int port );
        void setConnectionStatus( int connectionStatus );
        void setConnectionCheckerRunning( bool connectionCheckerRunning );
        void setLastChecked( long lastchecked );

        void saveFile();

        bool doesRDPHasString( wxString searchString );

    private:
        void parseFile();
        ConnectionType::ConnectionType connectionType;
        std::string filename;
        wxString comment, username, password, domain, clienthostname, desktopheight, desktopwidth, desktopbpp, console, screenmode, soundmode, diskmapping;
        std::string hostname;
        int port;
        int connectionStatus;
        bool connectionCheckerRunning;
        long lastchecked; /** seconds since a connection check was done. (seconds since 1970-01-01 00:00:00) **/
        wxMutex mutex;
};

class RDPDatabase
{
    public:
        RDPDatabase();
        ~RDPDatabase();
        RDPConnection *addRDPConnection( std::string filename );
        RDPConnection *duplicateRDPConnection( std::string filename, RDPConnection *copy );
        void deleteRDPConnectionByPointer( RDPConnection *rdpConnection );
        std::vector<RDPConnection*> getDatabase();

        RDPConnection* getRDPFromListCtrl( long index );
        void clearRDPListCtrl();
        void addRDPToListCtrl( RDPConnection *connection );

        long getListCtrlIndexFromFilename( std::string filename );

        void sortById( int id );
        bool isSortOrderAscending() const;
        void setSortOrder( bool database_sort_ascending );

    private:
        bool database_sort_ascending;
        void loadRDPFiles();
        std::vector<RDPConnection*> database;
        std::vector<RDPConnection*> listCtrlRelation;

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

        static bool useConnectionCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return ConnectionType::getConnectionTypeName( left->getConnectionType() ).Lower() < ConnectionType::getConnectionTypeName( right->getConnectionType() ).Lower();
        }

        static bool useConnectionCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return ConnectionType::getConnectionTypeName( left->getConnectionType() ).Lower() > ConnectionType::getConnectionTypeName( right->getConnectionType() ).Lower();
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
