/**
    Copyright (C) 2010-2015 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#ifndef __RDP_DATABASE_H__
#define __RDP_DATABASE_H__

#include <vector>
#include <wx/string.h>
#include <wx/thread.h>

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

    inline ConnectionType::ConnectionType getConnectionTypeForPort( int port )
    {
        switch ( port )
        {
            case 23:
                return ConnectionType::TELNET;
            break;
            case 5900:
                return ConnectionType::VNC;
            break;
            case 3389:
                return ConnectionType::RDP;
            break;
            default:
            case 22:
                return ConnectionType::SSH;
            break;
        }
    }
}

class RDPConnection
{
    public:
        RDPConnection( wxString filename );
        RDPConnection( wxString, RDPConnection *copy );
        ~RDPConnection();

        ConnectionType::ConnectionType getConnectionType() const;
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
        bool isConnectionCheckerRunning();
        long getLastChecked();
        bool getConnectWhenReady();

        long getConnectionCheckerId();

        // special string returns for the connection
        wxString getResolutionString() const;
        wxString getDomainUsernameString() const;
        wxString getColorsString() const;
        wxString getConsoleString() const;

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
        void setConnectWhenReady( bool connectWhenReady );
        void setConnectionCheckerId( long connectionCheckerId );
        void saveFile();
        bool doesRDPHaveString( wxString searchString );

    private:
        void parseFile();
        ConnectionType::ConnectionType connectionType;
        wxString filename,comment, username, password, domain, clienthostname, desktopheight, desktopwidth, desktopbpp, console, screenmode, soundmode, diskmapping;
        std::string hostname;
        int port;
        int connectionStatus;
        bool connectionCheckerRunning;
        long lastchecked; /** seconds since a connection check was done. (seconds since 1970-01-01 00:00:00) **/
        bool connectWhenReady;
        long connectionCheckerId;
        wxMutex mutex;
};

class RDPDatabase
{
    public:
        RDPDatabase();
        ~RDPDatabase();
        RDPConnection *addRDPConnection( wxString filename );
        RDPConnection *duplicateRDPConnection( wxString filename, RDPConnection *copy );
        void deleteRDPConnectionByPointer( RDPConnection *rdpConnection );
        std::vector< RDPConnection* > getDatabase();
        std::vector< RDPConnection* > getDatabaseWithFilter( wxString filter );

        RDPConnection* getRDPFromListCtrl( long index );
        void clearRDPListCtrl();
        void addRDPToListCtrl( RDPConnection *connection );
        long getListCtrlIndexFromId( long connectionId );
        RDPConnection* getRDPFromConnectionID( long connectionId );

        void sortByName( wxString name );
        bool isSortOrderAscending() const;
        void setSortOrder( bool database_sort_ascending );
        bool compareConnection( wxString left, wxString right );

    private:
        bool database_sort_ascending;
        void loadRDPFiles();
        std::vector<RDPConnection*> database;
        std::vector<RDPConnection*> listCtrlRelation;

        static bool hostnameCompareAsc( RDPConnection* left, RDPConnection* right );

        static bool hostnameCompareDesc( RDPConnection* left, RDPConnection* right );

        static bool portCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getPort() < right->getPort();
        }

        static bool portCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getPort() > right->getPort();
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
            return left->getConsoleString().Lower() < right->getConsoleString().Lower();
        }

        static bool useConsoleCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getConsoleString().Lower() > right->getConsoleString().Lower();
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

        static bool clientNameCompareAsc( RDPConnection* left, RDPConnection* right )
        {
            return left->getClientHostname().Lower() < right->getClientHostname().Lower();
        }

        static bool clientNameCompareDesc( RDPConnection* left, RDPConnection* right )
        {
            return left->getClientHostname().Lower() > right->getClientHostname().Lower();
        }
};
#endif
