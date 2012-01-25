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

#include "Settings.h"
#include "Resources.h"
#include "FileParser.h"
#include <wx/stdpaths.h>
#include <fstream>

#ifndef DATA_PATH
#define DATA_PATH ""
#endif

Settings::Settings()
{
    /** load all settings for quickRDP **/

    // RDP executable
    #if defined(__WXMSW__)
        RDPExec = wxT("mstsc ");
    #elif defined(__UNIX__)
        RDPExec = wxT("rdesktop ");
    #endif

    // settings path
    #if defined(__WXMSW__)
        settingsPath = wxStandardPathsBase::Get().GetUserDataDir() + wxT("\\");
    #elif defined(__UNIX__)
        settingsPath = wxStandardPathsBase::Get().GetUserDataDir() + wxT("/");
    #endif

    // database path
    #if defined(__WXMSW__)
        databasePath = getSettingsPath() + wxT("connections\\");
    #elif defined(__UNIX__)
        databasePath = getSettingsPath() + wxT("connections/");
    #endif

    // perl database path
    #if defined(__WXMSW__)
        perlDatabasePath = getSettingsPath() + wxT("perl\\");
    #elif defined(__UNIX__)
        perlDatabasePath = getSettingsPath() + wxT("perl/");
    #endif

    /** make sure we have the folders created for our settings, connection database and perl database **/
    if ( wxDirExists( getSettingsPath() ) == false ) {
        #if defined(__WXMSW__)
            wxMkDir( getSettingsPath().fn_str() );
        #elif defined(__UNIX__)
            wxMkDir( getSettingsPath().fn_str(), 0700 );
        #endif
    }

    if ( wxDirExists( getDatabasePath() ) == false ) {
        #if defined(__WXMSW__)
            wxMkDir( getDatabasePath().fn_str() );
        #elif defined(__UNIX__)
            wxMkDir( getDatabasePath().fn_str(), 0700 );
        #endif
    }

    if ( wxDirExists( getPerlDatabasePath() ) == false ) {
        #if defined(__WXMSW__)
            wxMkDir( getPerlDatabasePath().fn_str() );
        #elif defined(__UNIX__)
            wxMkDir( getPerlDatabasePath().fn_str(), 0700 );
        #endif
    }

    /** parse our settings file **/
    loadSettings();
}

Settings::~Settings()
{

}

wxString Settings::getDataPath() const
{
	wxString retString( DATA_PATH, wxConvUTF8 );
	return retString + wxT("data/");
}

void Settings::saveSettings()
{
    std::ofstream ofile;
    ofile.open( wxString( Resources::Instance()->getSettings()->getSettingsPath() + wxT("settings") ).mb_str(), std::ios::out|std::ios::binary );

    FileParser::writeLineToFile( ofile, wxString(wxT("telnetexec:s:")) + getTelnetExec() );
    FileParser::writeLineToFile( ofile, wxString(wxT("SSHexec:s:")) + getSSHExec() );
    FileParser::writeLineToFile( ofile, wxString(wxT("perlexec:s:")) + getPerlExec() );
    FileParser::writeLineToFile( ofile, wxString(wxT("telnetargument:s:")) + getTelnetArgument() );
    FileParser::writeLineToFile( ofile, wxString(wxT("SSHargument:s:")) + getSSHArgument() );
    FileParser::writeLineToFile( ofile, wxString(wxT("perlargument:s:")) + getPerlArgument() );

    ofile.close();
}

void Settings::loadSettings()
{
    wxString filename( getSettingsPath() + wxT("settings") );

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
        setTelnetExec( FileParser::getStringFromFile( wxT("telnetexec:s:"), allLines ) );
        setSSHExec( FileParser::getStringFromFile( wxT("SSHexec:s:"), allLines ) );
        setPerlExec( FileParser::getStringFromFile( wxT("perlexec:s:"), allLines ) );
        setTelnetArgument( FileParser::getStringFromFile( wxT("telnetargument:s:"), allLines ) );
        setSSHArgument( FileParser::getStringFromFile( wxT("SSHargument:s:"), allLines ) );
        setPerlArgument( FileParser::getStringFromFile( wxT("perlargument:s:"), allLines ) );
	}
	rfile.close();
    }
}

wxString Settings::getRDPExec( bool useAdminString ) const
{
    #if defined(__WXMSW__)
        if ( useAdminString == true ) {
            return RDPExec + wxT("/admin ");
        }
    #endif
    return RDPExec;
}

wxString Settings::getTelnetExec() const
{
    return telnetExec;
}
wxString Settings::getTelnetArgument() const
{
    return telnetArgument;
}

wxString Settings::getSSHExec() const
{
    return SSHExec;
}

wxString Settings::getSSHArgument() const
{
    return SSHArgument;
}

wxString Settings::getPerlExec() const
{
    return perlExec;
}

wxString Settings::getPerlArgument() const
{
    return perlArgument;
}

void Settings::setTelnetExec( wxString telnetExec )
{
    this->telnetExec = telnetExec;
}

void Settings::setTelnetArgument( wxString telnetArgument )
{
    this->telnetArgument = telnetArgument;
}

void Settings::setSSHExec( wxString SSHExec )
{
    this->SSHExec = SSHExec;
}

void Settings::setSSHArgument( wxString SSHArgument)
{
    this->SSHArgument = SSHArgument;
}

void Settings::setPerlExec( wxString perlExec )
{
    this->perlExec = perlExec;
}

void Settings::setPerlArgument( wxString perlArgument )
{
    this->perlArgument = perlArgument;
}

wxString Settings::getSettingsPath() const
{
    return settingsPath;
}

wxString Settings::getDatabasePath() const
{
    return databasePath;
}

wxString Settings::getPerlDatabasePath() const
{
    return perlDatabasePath;
}
