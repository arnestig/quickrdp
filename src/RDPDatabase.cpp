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

#include "RDPDatabase.h"
#include "QuickrdpFunctions.h"
#include "Resources.h"
#include <wx/filefn.h>
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <cstdarg>
#include <algorithm>

///BEGIN RDPConnection
RDPConnection::RDPConnection( wxString filename )
    :   connectionType( ConnectionType::RDP ),
        filename( filename ),
        desktopheight( wxT("0") ),
        desktopwidth( wxT("0") ),
        desktopbpp( wxT("0") ),
        console( wxT("0") ),
        screenmode( wxT("1") ),
        soundmode( wxT("0") ),
        diskmapping( wxT("0") ),
        port( -1 ),
        connectionStatus( 2 ), // default to 2 which will paint us the connectionunk.xpm or .ico image in the ListCtrl
        connectionCheckerRunning( false ),
        lastchecked( 0 ),
        connectWhenReady( false ),
        connectionCheckerId( 0 )
{
    // if we have an empty string here, we don't intend to read it
    if ( filename.empty() == false ) {
        parseFile();
    }

    /** handle default settings **/
    Settings *settings = Resources::Instance()->getSettings();
    switch ( settings->getRDPDefaultResolution() ) {
        case 0: // default resolution
            setDesktopHeight( wxT("0") );
            setDesktopWidth( wxT("0") );
            setScreenMode( wxT("1") );
        break;
        case 1: // full screen
            setDesktopHeight( wxT("0") );
            setDesktopWidth( wxT("0") );
            setScreenMode( wxT("2") );
        break;
        case 2: // custom resolutions 640x480
            setScreenMode( wxT("1") );
            setDesktopWidth( wxT("640") );
            setDesktopHeight( wxT("480") );
        break;
        case 3: // custom resolutions 800x600
            setScreenMode( wxT("1") );
            setDesktopWidth( wxT("800") );
            setDesktopHeight( wxT("600") );
        break;
        case 4: // custom resolutions 1024x768
            setScreenMode( wxT("1") );
            setDesktopWidth( wxT("1024") );
            setDesktopHeight( wxT("768") );
        break;
        case 5: // custom resolutions 1152x864
            setScreenMode( wxT("1") );
            setDesktopWidth( wxT("1152") );
            setDesktopHeight( wxT("864") );
        break;
        case 6: // custom resolutions 1280x960
            setScreenMode( wxT("1") );
            setDesktopWidth( wxT("1280") );
            setDesktopHeight( wxT("960") );
        break;
        case 7: // custom resolutions 1400x1050
            setScreenMode( wxT("1") );
            setDesktopWidth( wxT("1400") );
            setDesktopHeight( wxT("1050") );
        break;
    }
}

RDPConnection::RDPConnection( wxString filename, RDPConnection *copy )
    :   filename( filename ),
        connectionStatus( 2 ), // default to 2 which will paint us the connectionunk.xpm or .ico image in the ListCtrl
        connectionCheckerRunning( false ),
        lastchecked( 0 ),
        connectWhenReady( false ),
        connectionCheckerId( 0 )
{
    setConnectionType( copy->getConnectionType() );
    setClientHostname( copy->getClientHostname() );
    setComment( copy->getComment() );
    setConsole( copy->getConsole() );
    setDesktopWidth( copy->getDesktopWidth() );
    setDesktopHeight( copy->getDesktopHeight() );
    setDesktopBpp( copy->getDesktopBpp() );
    setDomain( copy->getDomain() );
    setHostname( copy->getHostname() );
    setPassword( copy->getPassword() );
    setScreenMode( copy->getScreenMode() );
    setUsername( copy->getUsername() );
    setSoundMode( copy->getSoundMode() );
    setDiskMapping( copy->getDiskMapping() );
    setPort( copy->getPort() );
    saveFile();
}

RDPConnection::~RDPConnection()
{
}

ConnectionType::ConnectionType RDPConnection::getConnectionType() const
{
    return connectionType;
}

void RDPConnection::getHostname( std::string &hostname )
{
    wxMutexLocker lock(mutex);
    hostname = this->hostname;
}

wxString RDPConnection::getHostname()
{
    std::string originHostname;
    getHostname( originHostname );
    wxString retval( originHostname.c_str(),wxConvUTF8 );
    return retval;
}

wxString RDPConnection::getUsername() const
{
    return username;
}

wxString RDPConnection::getPassword() const
{
    return password;
}

wxString RDPConnection::getDomain() const
{
    return domain;
}

wxString RDPConnection::getComment() const
{
    return comment;
}

wxString RDPConnection::getClientHostname() const
{
    return clienthostname;
}

wxString RDPConnection::getFilename()
{
    return filename;
}

wxString RDPConnection::getDesktopHeight() const
{
    return desktopheight;
}

wxString RDPConnection::getDesktopWidth() const
{
    return desktopwidth;
}

wxString RDPConnection::getDesktopBpp() const
{
    return desktopbpp;
}

wxString RDPConnection::getScreenMode() const
{
    return screenmode;
}

wxString RDPConnection::getConsole() const
{
    return console;
}

wxString RDPConnection::getSoundMode() const
{
    return soundmode;
}

wxString RDPConnection::getDiskMapping() const
{
    return diskmapping;
}

int RDPConnection::getPort()
{
    int retval;
    wxMutexLocker lock(mutex);
    if ( port == -1 ) {
        switch ( getConnectionType() ) {
            case ConnectionType::TELNET:
                retval = 23;
            break;
            case ConnectionType::SSH:
                retval = 22;
            break;
            case ConnectionType::VNC:
                retval = 5900;
            break;
            case ConnectionType::RDP:
            default:
                retval = 3389;
            break;
        }
    } else {
        retval = port;
    }
    return retval;
}

int RDPConnection::getPortTrueValue()
{
    wxMutexLocker lock( mutex );
    return port;
}

int RDPConnection::getConnectionStatus() const
{
    return connectionStatus;
}

bool RDPConnection::isConnectionCheckerRunning()
{
    wxMutexLocker lock( mutex );
    return connectionCheckerRunning;
}

long RDPConnection::getLastChecked()
{
    wxMutexLocker lock( mutex );
    return lastchecked;
}

bool RDPConnection::getConnectWhenReady()
{
    wxMutexLocker lock( mutex );
    return connectWhenReady;
}

long RDPConnection::getConnectionCheckerId()
{
    wxMutexLocker lock( mutex );
    return connectionCheckerId;
}

wxString RDPConnection::getResolutionString() const
{
    wxString retval = wxT("");
    if ( getConnectionType() == ConnectionType::RDP ) {
        if ( getScreenMode() == wxT("2") ) {
            retval = wxT("Fullscreen");
        } else if ( getScreenMode() == wxT("1") && getDesktopHeight() == wxT("0") && getDesktopWidth() == wxT("0") ) {
            retval = wxT("Default resolution" );
        } else {
            retval = getDesktopWidth() << wxT(" x ") << getDesktopHeight();
        }
    }
    return retval;
}

wxString RDPConnection::getConsoleString() const
{
    wxString retval = wxT("");
    if ( getConnectionType() == ConnectionType::RDP ) {
        if ( getConsole() == wxT("1") ) {
            retval = wxT("Yes");
        } else {
            retval= wxT("No" );
        }
    }
    return retval;
}

wxString RDPConnection::getDomainUsernameString() const
{
    wxString username;
    if ( getDomain().Len() > 0 && getConnectionType() == ConnectionType::RDP ) {
        username.Append( getDomain() + wxT("\\") );
    }
    username.Append( getUsername() );
    return username;
}

wxString RDPConnection::getColorsString() const
{
    if ( getDesktopBpp() == wxT("0") ) {
        return wxT("Default colors");
    } else {
        if ( getDesktopBpp() == wxT("15") ) { return wxT("\"High Color\" (15 bits)"); }
        if ( getDesktopBpp() == wxT("16") ) { return wxT("\"High Color\" (16 bits)"); }
        if ( getDesktopBpp() == wxT("24") ) { return wxT("\"True Color\" (24 bits)"); }
    }
    return wxT("");
}

void RDPConnection::setConnectionType( ConnectionType::ConnectionType connectionType )
{
    this->connectionType = connectionType;
}

void RDPConnection::setHostname( wxString hostname )
{
    this->hostname = std::string( hostname.mb_str() );
}

void RDPConnection::setUsername( wxString username )
{
    this->username = username;
}

void RDPConnection::setPassword( wxString password )
{
    this->password = password;
}

void RDPConnection::setDomain( wxString domain )
{
    this->domain = domain;
}

void RDPConnection::setComment( wxString comment )
{
    this->comment = comment;
}

void RDPConnection::setClientHostname( wxString clienthostname )
{
    this->clienthostname = clienthostname;
}

void RDPConnection::setDesktopHeight( wxString desktopheight )
{
    this->desktopheight = desktopheight;
}

void RDPConnection::setDesktopWidth( wxString desktopwidth )
{
    this->desktopwidth = desktopwidth;
}

void RDPConnection::setDesktopBpp( wxString desktopbpp )
{
    this->desktopbpp = desktopbpp;
}

void RDPConnection::setScreenMode( wxString screenmode )
{
    this->screenmode = screenmode;
}

void RDPConnection::setConsole( wxString console )
{
    this->console = console;
}

void RDPConnection::setDiskMapping( wxString diskmapping )
{
    this->diskmapping = diskmapping;
}

void RDPConnection::setSoundMode( wxString soundmode )
{
    this->soundmode = soundmode;
}

void RDPConnection::setPort( int port )
{
    wxMutexLocker lock(mutex);
    if (( port == 3389 && getConnectionType() == ConnectionType::RDP ) ||  /** check if any of the values set are default to their connection type **/
        ( port == 23 && getConnectionType() == ConnectionType::TELNET ) ||
        ( port == 22 && getConnectionType() == ConnectionType::SSH ) ||
        ( port == 5900 && getConnectionType() == ConnectionType::VNC ) ||
        ( port == 0 ) ) {
            this->port = -1;
        } else {
            this->port = port;
        }
}

void RDPConnection::setConnectionStatus( int connectionStatus )
{
    this->connectionStatus = connectionStatus;
}

void RDPConnection::setConnectionCheckerRunning( bool connectionCheckerRunning )
{
    wxMutexLocker lock( mutex );
    this->connectionCheckerRunning = connectionCheckerRunning;
}

void RDPConnection::setLastChecked( long lastchecked )
{
    wxMutexLocker lock( mutex );
    this->lastchecked = lastchecked;
}

void RDPConnection::setConnectWhenReady( bool connectWhenReady )
{
    wxMutexLocker lock( mutex );
    this->connectWhenReady = connectWhenReady;
}

void RDPConnection::setConnectionCheckerId( long connectionCheckerId )
{
    wxMutexLocker lock( mutex );
    this->connectionCheckerId = connectionCheckerId;
}

void RDPConnection::connect()
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( getFilename().empty() == false ) {
        bool useAdminString = ( getConsole() == wxT("1") );
        /** connect to either RDP, telnet or SSH here.. also make sure we have an executable for the choosen connection **/
        wxString connectionTypeName = ConnectionType::getConnectionTypeName( getConnectionType() );
        switch ( getConnectionType() ) {
            case ConnectionType::RDP:
                {
                    #if defined(__UNIX__)
                        wxString RDPargument = settings->getRDPExec( useAdminString );
                        /// setup resolution argument
                        if ( getScreenMode() == wxT("1") && getDesktopHeight() != wxT("0") && getDesktopHeight() != wxT("0") ) {
                            RDPargument.append( wxT(" -g") + getDesktopWidth() + wxT("x") + getDesktopHeight() );
                        } else if ( getScreenMode() == wxT("2" ) ) {
                            RDPargument.append( wxT(" -f" ) );
                        }
                        /// bits per pixel argument.
                        if ( getDesktopBpp() != wxT("0") ) {
                            RDPargument.append( wxT(" -a") + getDesktopBpp() );
                        }
                        /// attach to console argument
                        if ( getConsole() == wxT("1" ) ) {
                            RDPargument.append( wxT(" -0" ) );
                        }
                        ///audi settings
                        if ( getSoundMode() == wxT("0") ) {
                            RDPargument.append( wxT(" -r sound:local" ) );
                        } else if ( getSoundMode() == wxT("1" ) ) {
                            RDPargument.append( wxT(" -r sound:remote" ) );
                        } else {
                            RDPargument.append( wxT(" -r sound:off" ) );
                        }
                        ///window caption
						if ( getComment().empty() == true ) {
							RDPargument.append( wxT(" -T") + getHostname() );
						} else {
							RDPargument.append( wxT(" -T") + getComment() );
						}
                        ///client hostname
                        if ( getClientHostname().empty() == false ) {
                            RDPargument.append( wxT(" -n") + getClientHostname() );
                        }
                        ///password
                        if ( getPassword().empty() == false ) {
                            RDPargument.append( wxT(" -p") + getPassword() );
                        }
                        ///domain
                        if ( getDomain().empty() == false ) {
                            RDPargument.append( wxT(" -d") + getDomain() );
                        }
                        ///username
                        if ( getUsername().empty() == false ) {
                            RDPargument.append( wxT(" -u") + getUsername() );
                        }
                        RDPargument.append( wxT(" ") + getHostname() );
						std::cout << RDPargument.mb_str() << std::endl;
                        wxExecute( RDPargument );
                    #elif(__WXMSW__)
                        wxExecute( settings->getRDPExec( useAdminString ) + wxT("\"") + settings->getDatabasePath() + getFilename() + wxT("\"") );
                    #endif
                }
            break;
            case ConnectionType::SSH:
                if ( settings->getSSHExec().empty() == false ) {
                    wxExecute( settings->getSSHExec() + wxT(" ") + quickRDP::FileParser::getRealArgumentString( settings->getSSHArgument(), this ) );
                } else {
                    wxMessageBox( wxT("You have not defined an executable for your ") + connectionTypeName + wxT(" connection. Please do so under Settings -> Preferences."), wxT("Unable to locate ") + connectionTypeName + wxT(" executable"), wxICON_ERROR );
                }
            break;
            case ConnectionType::TELNET:
                if ( settings->getTelnetExec().empty() == false ) {
                    wxExecute( settings->getTelnetExec() + wxT(" ") + quickRDP::FileParser::getRealArgumentString( settings->getTelnetArgument(), this ) );
                } else {
                    wxMessageBox( wxT("You have not defined an executable for your ") + connectionTypeName + wxT(" connection. Please do so under Settings -> Preferences."), wxT("Unable to locate ") + connectionTypeName + wxT(" executable"), wxICON_ERROR );
                }
            break;
            case ConnectionType::VNC:
                if ( settings->getVNCExec().empty() == false ) {
                    wxExecute( settings->getVNCExec() + wxT(" ") + quickRDP::FileParser::getRealArgumentString( settings->getVNCArgument(), this ) );
                } else {
                    wxMessageBox( wxT("You have not defined an executable for your ") + connectionTypeName + wxT(" connection. Please do so under Settings -> Preferences."), wxT("Unable to locate ") + connectionTypeName + wxT(" executable"), wxICON_ERROR );
                }
            break;
        }
    }
}

void RDPConnection::saveFile()
{
    std::ofstream ofile;
    ofile.open( wxString( Resources::Instance()->getSettings()->getDatabasePath() + getFilename() ).mb_str(), std::ios::out|std::ios::binary );

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectiontype:i:")) << getConnectionType() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("username:s:")) + getUsername() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("domain:s:")) + getDomain() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("password:s:")) + getPassword() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("full address:s:")) + getHostname() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("client hostname:s:")) + getClientHostname() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("description:s:")) + getComment() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("desktopheight:i:")) + getDesktopHeight() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("desktopwidth:i:")) + getDesktopWidth() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("session bpp:i:")) + getDesktopBpp() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("screen mode id:i:")) + getScreenMode() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("attach to console:i:")) + getConsole() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("audiomode:i:")) + getSoundMode() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("diskmapping:i:")) + getDiskMapping() );
	quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("port:i:")) + wxString::Format( wxT("%i"), getPort() ) );

	ofile.close();
}

void RDPConnection::parseFile()
{
    wxString filename( Resources::Instance()->getSettings()->getDatabasePath() + getFilename() );

    if ( wxFileExists( filename ) == true ) {
        std::ifstream rfile;
        rfile.open( filename.mb_str(), std::ios::in|std::ios::binary );
        rfile.seekg (0, std::ios::end);
        int length = rfile.tellg();
        rfile.seekg (0, std::ios::beg);

        if (length == -1) {
            return;
        }
        std::string inputData;

        if (length > 0) {
            std::vector<wxString> allLines;
            while ( getline(rfile,inputData) ) {
                wxString input( inputData.c_str(), wxConvUTF8 );
                input.Replace(wxT("\r"),wxT(""));
                input.Replace(wxT("\n"),wxT(""));
                allLines.push_back( input );
            }
            setConnectionType( static_cast< ConnectionType::ConnectionType >( quickRDP::FileParser::getIntegerFromFile( wxT("connectiontype:i:"), allLines ) ) );
            setUsername( quickRDP::FileParser::getStringFromFile( wxT("username:s:"), allLines ) );
            setDomain( quickRDP::FileParser::getStringFromFile( wxT("domain:s:"), allLines ) );
            setPassword( quickRDP::FileParser::getStringFromFile( wxT("password:s:"), allLines ) );
            setHostname( quickRDP::FileParser::getStringFromFile( wxT("full address:s:"), allLines ) );
            setClientHostname( quickRDP::FileParser::getStringFromFile( wxT("client hostname:s:"), allLines ) );
            setComment( quickRDP::FileParser::getStringFromFile( wxT("description:s:"), allLines ) );
            setDesktopHeight( quickRDP::FileParser::getStringFromFile( wxT("desktopheight:i:"), allLines ) );
            setDesktopWidth( quickRDP::FileParser::getStringFromFile( wxT("desktopwidth:i:"), allLines ) );
            setDesktopBpp( quickRDP::FileParser::getStringFromFile( wxT("session bpp:i:"), allLines ) );
            setScreenMode( quickRDP::FileParser::getStringFromFile( wxT("screen mode id:i:"), allLines ) );
            setConsole( quickRDP::FileParser::getStringFromFile( wxT("attach to console:i:"), allLines ) );
            setSoundMode( quickRDP::FileParser::getStringFromFile( wxT("audiomode:i:"), allLines ) );
            setDiskMapping( quickRDP::FileParser::getStringFromFile( wxT("diskmapping:i:"), allLines ) );
            setPort( quickRDP::FileParser::getIntegerFromFile( wxT("port:i:"), allLines ) );
        }
        rfile.close();
    }
}

bool RDPConnection::doesRDPHaveString( wxString searchString )
{
    bool foundAnything = false;
    if ( quickRDP::FileParser::searchForString( std::string( getUsername().Lower().mb_str() ), std::string( searchString.Lower().mb_str() ) ) == true ) { foundAnything = true; }
    if ( quickRDP::FileParser::searchForString( std::string( getDomain().Lower().mb_str() ), std::string( searchString.Lower().mb_str() ) ) == true ) { foundAnything = true; }
    if ( quickRDP::FileParser::searchForString( std::string( getHostname().Lower().mb_str() ), std::string( searchString.Lower().mb_str() ) ) == true ) { foundAnything = true; }
    if ( quickRDP::FileParser::searchForString( std::string( getComment().Lower().mb_str() ), std::string( searchString.Lower().mb_str() ) ) == true ) { foundAnything = true; }
    return foundAnything;
}
///END RDPConnection



///BEGIN RDPDatabase
RDPDatabase::RDPDatabase()
    : database_sort_ascending( true )
{
}

RDPDatabase::~RDPDatabase()
{
	for ( std::vector< RDPConnection* >::iterator it = database.begin(); it != database.end(); ++it ) {
		delete (*it);
	}
	database.clear();
}

void RDPDatabase::loadRDPFiles()
{
    // traverse the database folder, looking for RDPConnections.
    wxString f = wxFindFirstFile( Resources::Instance()->getSettings()->getDatabasePath() );
    while ( f.empty() == false ) {
        wxFileName fname;
        fname.Assign( f );
        addRDPConnection( fname.GetName() );
        f = wxFindNextFile();
    }
    sortById( 0 );
}

RDPConnection *RDPDatabase::addRDPConnection( wxString filename )
{
    RDPConnection *newRDP = new RDPConnection( filename );
    database.push_back( newRDP );
    return newRDP;
}

RDPConnection *RDPDatabase::duplicateRDPConnection( wxString filename, RDPConnection *copy )
{
    RDPConnection *newRDP = new RDPConnection( filename, copy );
    database.push_back( newRDP );
    return newRDP;
}

void RDPDatabase::deleteRDPConnectionByPointer( RDPConnection *rdpConnection )
{
    for ( size_t index = 0; index < database.size(); index++ ) {
        if ( database[ index ] == rdpConnection ) {
            wxRemoveFile( Resources::Instance()->getSettings()->getDatabasePath() + rdpConnection->getFilename() );
            delete rdpConnection;
            rdpConnection = NULL;
            database.erase( database.begin() + index );
        }
    }
}

std::vector<RDPConnection*> RDPDatabase::getDatabase()
{
    if ( database.empty() == true ) {
        loadRDPFiles();
    }
    return database;
}

std::vector< RDPConnection* > RDPDatabase::getDatabaseWithFilter( wxString filter )
{
    std::vector< RDPConnection* > retval;
    if ( database.empty() == true ) {
        loadRDPFiles();
    }

    for ( std::vector< RDPConnection* >::iterator it = database.begin(); it != database.end(); ++it ) {
        if ( (*it)->doesRDPHaveString( filter ) == true ) {
            retval.push_back( (*it) );
        }
    }
    return retval;
}


RDPConnection* RDPDatabase::getRDPFromListCtrl( long index )
{
    if ( index < static_cast<long>( listCtrlRelation.size() ) && index >= 0 ) {
        return listCtrlRelation[ index ];
    } else {
        return NULL;
    }
}

long RDPDatabase::getListCtrlIndexFromId( long connectionId )
{
    for ( std::vector< RDPConnection* >::const_iterator it = listCtrlRelation.begin(); it != listCtrlRelation.end(); ++it ) {
        if ( (*it)->getConnectionCheckerId() == connectionId ) {
            return it - listCtrlRelation.begin();
        }
    }
    return -1;
}

RDPConnection* RDPDatabase::getRDPFromConnectionID( long connectionId )
{
    for ( std::vector< RDPConnection* >::const_iterator it = database.begin(); it != database.end(); ++it ) {
        if ( (*it)->getConnectionCheckerId() == connectionId ) {
            return (*it);
        }
    }
    return NULL;
}

void RDPDatabase::clearRDPListCtrl()
{
    listCtrlRelation.clear();
}

void RDPDatabase::addRDPToListCtrl( RDPConnection *connection )
{
    listCtrlRelation.push_back( connection );
}

void RDPDatabase::sortById( int id )
{
    switch ( id )
    {
        case 0: // hostname sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), hostnameCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), hostnameCompareDesc );
            }
        break;
        case 1: // port sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), portCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), portCompareDesc );
            }
        break;
        case 2: // username  sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), usernameCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), usernameCompareDesc );
            }
        break;
        case 3: // connection type sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), useConnectionCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), useConnectionCompareDesc );
            }
        break;
        case 4: // use console sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), useConsoleCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), useConsoleCompareDesc );
            }
        break;
        case 5: // resolution sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), resolutionCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), resolutionCompareDesc );
            }
        break;

        case 6: // comment sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), commentCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), commentCompareDesc );
            }
        break;

        case 7: // client name sorting
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), clientNameCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), clientNameCompareDesc );
            }
        break;
        default:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), hostnameCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), hostnameCompareDesc );
            }
        break;
    }
}

bool RDPDatabase::isSortOrderAscending() const
{
    return database_sort_ascending;
}

void RDPDatabase::setSortOrder( bool database_sort_ascending )
{
    this->database_sort_ascending = database_sort_ascending;
}

///END RDPDatabase
