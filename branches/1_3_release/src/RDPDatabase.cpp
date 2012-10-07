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
        port( wxT("-1") ),
        connectionStatus( 2 ), // default to 2 which will paint us the connectionunk.xpm or .ico image in the ListCtrl
        connectionCheckerRunning( false ),
        lastchecked( 0 )
{
    parseFile();
}

RDPConnection::RDPConnection( wxString filename_, RDPConnection *copy )
    :   filename( filename_ ),
        connectionStatus( 2 ), // default to 2 which will paint us the connectionunk.xpm or .ico image in the ListCtrl
        lastchecked( 0 )
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

wxString RDPConnection::getHostname()
{
    wxMutexLocker lock(mutex);
    return hostname;
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
    wxMutexLocker lock(mutex);
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

wxString RDPConnection::getPort()
{
    wxString retval;
    wxMutexLocker lock(mutex);
    if ( port == wxT("-1") ) {
        switch ( getConnectionType() ) {
            case ConnectionType::RDP:
                retval = wxT("3389");
            break;
            case ConnectionType::TELNET:
                retval = wxT("23");
            break;
            case ConnectionType::SSH:
                retval = wxT("22");
            break;
            case ConnectionType::VNC:
                retval = wxT("5900");
            break;
            default:
                retval = wxT("");
        }
    } else {
        retval = port;
    }
    return retval;
}

wxString RDPConnection::getPortTrueValue() const
{
    return port;
}

int RDPConnection::getConnectionStatus() const
{
    return connectionStatus;
}

bool RDPConnection::isConnectionCheckerRunning() const
{
    return connectionCheckerRunning;
}

long RDPConnection::getLastChecked() const
{
    return lastchecked;
}

wxString RDPConnection::getResolutionString() const
{
    if ( getScreenMode() == wxT("2") ) {
        return wxT("Fullscreen");
    } else if ( getScreenMode() == wxT("1") && getDesktopHeight() == wxT("0") && getDesktopWidth() == wxT("0") ) {
        return wxT("Default resolution" );
    } else {
        return ( getDesktopWidth() + wxT(" x ") + getDesktopHeight() );
    }
}

wxString RDPConnection::getDomainUsernameString() const
{
    wxString username;
    if ( getDomain().Len() > 0 ) {
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
    wxMutexLocker lock(mutex);
    this->connectionType = connectionType;
}

void RDPConnection::setHostname( wxString hostname )
{
    wxMutexLocker lock(mutex);
    this->hostname = hostname;
}

void RDPConnection::setUsername( wxString username )
{
    wxMutexLocker lock(mutex);
    this->username = username;
}

void RDPConnection::setPassword( wxString password )
{
    wxMutexLocker lock(mutex);
    this->password = password;
}

void RDPConnection::setDomain( wxString domain )
{
    wxMutexLocker lock(mutex);
    this->domain = domain;
}

void RDPConnection::setComment( wxString comment )
{
    wxMutexLocker lock(mutex);
    this->comment = comment;
}

void RDPConnection::setClientHostname( wxString clienthostname )
{
    wxMutexLocker lock(mutex);
    this->clienthostname = clienthostname;
}

void RDPConnection::setDesktopHeight( wxString desktopheight )
{
    wxMutexLocker lock(mutex);
    this->desktopheight = desktopheight;
}

void RDPConnection::setDesktopWidth( wxString desktopwidth )
{
    wxMutexLocker lock(mutex);
    this->desktopwidth = desktopwidth;
}

void RDPConnection::setDesktopBpp( wxString desktopbpp )
{
    wxMutexLocker lock(mutex);
    this->desktopbpp = desktopbpp;
}

void RDPConnection::setScreenMode( wxString screenmode )
{
    wxMutexLocker lock(mutex);
    this->screenmode = screenmode;
}

void RDPConnection::setConsole( wxString console )
{
    wxMutexLocker lock(mutex);
    this->console = console;
}

void RDPConnection::setDiskMapping( wxString diskmapping )
{
    wxMutexLocker lock(mutex);
    this->diskmapping = diskmapping;
}

void RDPConnection::setSoundMode( wxString soundmode )
{
    wxMutexLocker lock(mutex);
    this->soundmode = soundmode;
}

void RDPConnection::setPort( wxString port )
{
    wxMutexLocker lock(mutex);
    if (( port == wxT("3389") && getConnectionType() == ConnectionType::RDP ) ||  /** check if any of the values set are default to their connection type **/
        ( port == wxT("23") && getConnectionType() == ConnectionType::TELNET ) ||
        ( port == wxT("22") && getConnectionType() == ConnectionType::SSH ) ||
        ( port == wxT("5900") && getConnectionType() == ConnectionType::VNC ) ||
        ( port.empty() == true ) ) {
            this->port = wxT("-1");
        } else {
            this->port = port;
        }
}

void RDPConnection::setConnectionStatus( int connectionStatus )
{
    wxMutexLocker lock(mutex);
    this->connectionStatus = connectionStatus;
}

void RDPConnection::setConnectionCheckerRunning( bool connectionCheckerRunning )
{
    wxMutexLocker lock(mutex);
    this->connectionCheckerRunning = connectionCheckerRunning;
}

void RDPConnection::setLastChecked( long lastchecked )
{
    wxMutexLocker lock(mutex);
    this->lastchecked = lastchecked;
}

void RDPConnection::connect()
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( getFilename().IsEmpty() == false ) {
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
                            RDPargument.append( wxT(" -r:local" ) );
                        } else if ( getSoundMode() == wxT("1" ) ) {
                            RDPargument.append( wxT(" -r:remote" ) );
                        } else {
                            RDPargument.append( wxT(" -r:off" ) );
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
	quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("port:i:")) + getPort() );

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
	    char *buffer;
		buffer = new char [length];
		std::vector<wxString> allLines;
		while ( getline(rfile,inputData) ) {
            wxString input( inputData.c_str(), wxConvUTF8 );
            input.Replace(wxT("\r"),wxT(""));
            input.Replace(wxT("\n"),wxT(""));
            allLines.push_back( input );
		}
		delete[] buffer;
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
		setPort( quickRDP::FileParser::getStringFromFile( wxT("port:i:"), allLines ) );
	}
	rfile.close();
    }
}

bool RDPConnection::doesRDPHasString( wxString searchString )
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
        addRDPConnection( fname.GetName( ) );
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

RDPConnection* RDPDatabase::getRDPFromListCtrl( long index )
{
    if ( index < listCtrlRelation.size() && index >= 0 ) {
        return listCtrlRelation[ index ];
    } else {
        return NULL;
    }
}

long RDPDatabase::getListCtrlIndexFromFilename( wxString filename )
{
    for ( std::vector< RDPConnection* >::const_iterator it = listCtrlRelation.begin(); it != listCtrlRelation.end(); ++it ) {
        if ( (*it)->getFilename() == filename ) {
            return it - listCtrlRelation.begin();
        }
    }
    return -1;
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
        case 0:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), hostnameCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), hostnameCompareDesc );
            }
        break;
        case 1:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), usernameCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), usernameCompareDesc );
            }
        break;
        case 2:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), useConnectionCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), useConnectionCompareDesc );
            }
        break;
        case 3:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), useConsoleCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), useConsoleCompareDesc );
            }
        break;
        case 4:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), resolutionCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), resolutionCompareDesc );
            }
        break;
        case 5:
            if ( isSortOrderAscending() == true ) {
                std::sort( database.begin(), database.end(), commentCompareAsc );
            } else {
                std::sort( database.begin(), database.end(), commentCompareDesc );
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
