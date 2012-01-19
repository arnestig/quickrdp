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
#include "FileParser.h"
#include "Resources.h"
#include <wx/filefn.h>
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
        diskmapping( wxT("0") )
{
    parseFile();
}

RDPConnection::RDPConnection( wxString filename_, RDPConnection *copy )
    :   filename( filename_ )
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
    saveFile();
}

RDPConnection::~RDPConnection()
{
}

ConnectionType::ConnectionType RDPConnection::getConnectionType() const
{
    return connectionType;
}

wxString RDPConnection::getHostname() const
{
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

wxString RDPConnection::getFilename() const
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
    this->connectionType = connectionType;
}

void RDPConnection::setHostname( wxString hostname )
{
    this->hostname = hostname;
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

void RDPConnection::connect()
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( getFilename().IsEmpty() == false ) {
        bool useAdminString = ( getConsole() == wxT("1") );
        /** connect to either RDP, telnet or SSH here.. also make sure we have an executable for the choosen connection **/
        wxString connectionTypeName = ConnectionType::getConnectionTypeName( getConnectionType() );
        switch ( getConnectionType() ) {
            case ConnectionType::RDP:
                wxExecute( settings->getRDPExec( useAdminString ) + wxT("\"") + settings->getDatabasePath() + getFilename() + wxT("\"") );
            break;
            case ConnectionType::SSH:
                if ( settings->getSSHExec().empty() == false ) {
                    wxExecute( settings->getSSHExec() + wxT(" ") + FileParser::getRealArgumentString( settings->getSSHArgument(), this ) );
                } else {
                    wxMessageBox( wxT("You have not defined an executable for your ") + connectionTypeName + wxT(" connection. Please do so under Settings -> Preferences."), wxT("Unable to locate ") + connectionTypeName + wxT(" executable"), wxICON_ERROR );
                }
            break;
            case ConnectionType::TELNET:
                if ( settings->getTelnetExec().empty() == false ) {
                    wxExecute( settings->getTelnetExec() + wxT(" ") + FileParser::getRealArgumentString( settings->getTelnetArgument(), this ) );
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

    FileParser::writeLineToFile( ofile, wxString(wxT("connectiontype:i:")) << getConnectionType() );
    FileParser::writeLineToFile( ofile, wxString(wxT("username:s:")) + getUsername() );
    FileParser::writeLineToFile( ofile, wxString(wxT("domain:s:")) + getDomain() );
    FileParser::writeLineToFile( ofile, wxString(wxT("password:s:")) + getPassword() );
    FileParser::writeLineToFile( ofile, wxString(wxT("full address:s:")) + getHostname() );
    FileParser::writeLineToFile( ofile, wxString(wxT("client hostname:s:")) + getClientHostname() );
    FileParser::writeLineToFile( ofile, wxString(wxT("description:s:")) + getComment() );
    FileParser::writeLineToFile( ofile, wxString(wxT("desktopheight:i:")) + getDesktopHeight() );
    FileParser::writeLineToFile( ofile, wxString(wxT("desktopwidth:i:")) + getDesktopWidth() );
    FileParser::writeLineToFile( ofile, wxString(wxT("session bpp:i:")) + getDesktopBpp() );
    FileParser::writeLineToFile( ofile, wxString(wxT("screen mode id:i:")) + getScreenMode() );
    FileParser::writeLineToFile( ofile, wxString(wxT("attach to console:i:")) + getConsole() );
    FileParser::writeLineToFile( ofile, wxString(wxT("audiomode:i:")) + getSoundMode() );
    FileParser::writeLineToFile( ofile, wxString(wxT("diskmapping:i:")) + getDiskMapping() );

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
        setConnectionType( static_cast< ConnectionType::ConnectionType >( wxAtoi( FileParser::getIntegerFromFile( wxT("connectiontype:i:"), allLines ) ) ) );
        setUsername( FileParser::getStringFromFile( wxT("username:s:"), allLines ) );
        setDomain( FileParser::getStringFromFile( wxT("domain:s:"), allLines ) );
        setPassword( FileParser::getStringFromFile( wxT("password:s:"), allLines ) );
        setHostname( FileParser::getStringFromFile( wxT("full address:s:"), allLines ) );
        setClientHostname( FileParser::getStringFromFile( wxT("client hostname:s:"), allLines ) );
        setComment( FileParser::getStringFromFile( wxT("description:s:"), allLines ) );
        setDesktopHeight( FileParser::getIntegerFromFile( wxT("desktopheight:i:"), allLines ) );
        setDesktopWidth( FileParser::getIntegerFromFile( wxT("desktopwidth:i:"), allLines ) );
        setDesktopBpp( FileParser::getIntegerFromFile( wxT("session bpp:i:"), allLines ) );
        setScreenMode( FileParser::getIntegerFromFile( wxT("screen mode id:i:"), allLines ) );
        setConsole( FileParser::getIntegerFromFile( wxT("attach to console:i:"), allLines ) );
        setSoundMode( FileParser::getIntegerFromFile( wxT("audiomode:i:"), allLines ) );
        setDiskMapping( FileParser::getIntegerFromFile( wxT("diskmapping:i:"), allLines ) );
	}
	rfile.close();
    }
}

bool RDPConnection::doesRDPHasString( wxString searchString ) const
{
    bool foundAnything = false;

    if ( getUsername().Lower().Find( searchString.Lower() ) != wxNOT_FOUND ) { foundAnything = true; }
    if ( getDomain().Lower().Find( searchString.Lower() ) != wxNOT_FOUND ) { foundAnything = true; }
    if ( getHostname().Lower().Find( searchString.Lower() ) != wxNOT_FOUND ) { foundAnything = true; }
    if ( getHostname().Lower().Find( searchString.Lower() ) != wxNOT_FOUND ) { foundAnything = true; }
    if ( getComment().Lower().Find( searchString.Lower() ) != wxNOT_FOUND ) { foundAnything = true; }

    return foundAnything;
}
///END RDPConnection



///BEGIN RDPDatabase
RDPDatabase::RDPDatabase()
    : database_sort_ascending( true )
{
    loadRDPFiles();
    sortById( 0 );
}

RDPDatabase::~RDPDatabase()
{
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

RDPConnection *RDPDatabase::getRDPConnectionByPointer( RDPConnection *rdpConnection )
{
    for ( size_t index = 0; index < database.size(); index++ ) {
        if ( database[ index ] == rdpConnection ) {
            return database[ index ];
        }
    }
    return NULL;
}

void RDPDatabase::deleteRDPConnectionByPointer( RDPConnection *rdpConnection )
{
    wxRemoveFile( Resources::Instance()->getSettings()->getDatabasePath() + rdpConnection->getFilename() );
    for ( size_t index = 0; index < database.size(); index++ ) {
        if ( database[ index ] == rdpConnection ) {
            database.erase( database.begin() + index );
        }
    }
}

std::vector<RDPConnection*> RDPDatabase::getDatabase()
{
    return database;
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
