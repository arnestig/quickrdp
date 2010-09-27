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

#include "RDPDatabase.h"
#include "FileParser.h"
#include "Configuration.h"
#include <wx/filefn.h>
#include <wx/filename.h>
#include <fstream>
#include <cstdarg>

///BEGIN RDPConnection
RDPConnection::RDPConnection( wxString filename_ )
    :   filename( filename_ ),
        desktopheight( wxT("0") ),
        desktopwidth( wxT("0") ),
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
    setClientHostname( copy->getClientHostname() );
    setComment( copy->getComment() );
    setConsole( copy->getConsole() );
    setDesktopWidth( copy->getDesktopWidth() );
    setDesktopHeight( copy->getDesktopHeight() );
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
    if ( getFilename().IsEmpty() == false ) {
        wxExecute( Configuration::getExecString() + wxT("\"") + Configuration::getDatabaseFolder() + getFilename() + wxT("\"") );
    }
}

void RDPConnection::writeLineToFile( std::ofstream &file, wxString line )
{
    file.write( line.mb_str(), line.Len() );
    file.write( "\r\n", 2 );
}

void RDPConnection::saveFile()
{
    std::ofstream ofile;
    ofile.open( wxString( Configuration::getDatabaseFolder() + getFilename() ).mb_str(), std::ios::out|std::ios::binary );

    writeLineToFile( ofile, wxString(wxT("username:s:")) + getUsername() );
    writeLineToFile( ofile, wxString(wxT("domain:s:")) + getDomain() );
    writeLineToFile( ofile, wxString(wxT("password:s:")) + getPassword() );
    writeLineToFile( ofile, wxString(wxT("full address:s:")) + getHostname() );
    writeLineToFile( ofile, wxString(wxT("client hostname:s:")) + getClientHostname() );
    writeLineToFile( ofile, wxString(wxT("description:s:")) + getComment() );
    writeLineToFile( ofile, wxString(wxT("desktopheight:i:")) + getDesktopHeight() );
    writeLineToFile( ofile, wxString(wxT("desktopwidth:i:")) + getDesktopWidth() );
    writeLineToFile( ofile, wxString(wxT("screen mode id:i:")) + getScreenMode() );
    writeLineToFile( ofile, wxString(wxT("attach to console:i:")) + getConsole() );
    writeLineToFile( ofile, wxString(wxT("audiomode:i:")) + getSoundMode() );
    writeLineToFile( ofile, wxString(wxT("diskmapping:i:")) + getDiskMapping() );

	ofile.close();
}

void RDPConnection::parseFile()
{
    wxString filename( Configuration::getDatabaseFolder() + getFilename() );

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
        setUsername( FileParser::getStringFromFile( wxT("username:s:"), allLines ) );
        setDomain( FileParser::getStringFromFile( wxT("domain:s:"), allLines ) );
        setPassword( FileParser::getStringFromFile( wxT("password:s:"), allLines ) );
        setHostname( FileParser::getStringFromFile( wxT("full address:s:"), allLines ) );
        setClientHostname( FileParser::getStringFromFile( wxT("client hostname:s:"), allLines ) );
        setComment( FileParser::getStringFromFile( wxT("description:s:"), allLines ) );
        setDesktopHeight( FileParser::getIntegerFromFile( wxT("desktopheight:i:"), allLines ) );
        setDesktopWidth( FileParser::getIntegerFromFile( wxT("desktopwidth:i:"), allLines ) );
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
{
    loadRDPFiles();
}

RDPDatabase::~RDPDatabase()
{
}

void RDPDatabase::loadRDPFiles()
{
    if ( wxDirExists( Configuration::getDatabaseFolder() ) == false ) {
        #if defined(__WXMSW__)
        wxMkDir( Configuration::getDatabaseFolder().fn_str() );
        #elif defined(__UNIX__)
        wxMkDir( Configuration::getDatabaseFolder().fn_str(), 0700);
        #endif

    }

    // traverse the database folder, looking for RDPConnections.
    wxString f = wxFindFirstFile( Configuration::getDatabaseFolder() );
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
///END RDPDatabase
