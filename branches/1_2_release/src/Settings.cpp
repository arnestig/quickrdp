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
    :   mainFrameWidth(0),
        mainFrameHeight(0)
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

    // command database path
    #if defined(__WXMSW__)
        commandDatabasePath = getSettingsPath() + wxT("commands\\");
    #elif defined(__UNIX__)
        commandDatabasePath = getSettingsPath() + wxT("commands/");
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

    if ( wxDirExists( getCommandDatabasePath() ) == false ) {
        #if defined(__WXMSW__)
            wxMkDir( getCommandDatabasePath().fn_str() );
        #elif defined(__UNIX__)
            wxMkDir( getCommandDatabasePath().fn_str(), 0700 );
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
    ofile.open( wxString( getSettingsPath() + wxT("settings") ).mb_str(), std::ios::out|std::ios::binary );

    FileParser::writeLineToFile( ofile, wxString(wxT("telnetexec:s:")) + getTelnetExec() );
    FileParser::writeLineToFile( ofile, wxString(wxT("SSHexec:s:")) + getSSHExec() );
    FileParser::writeLineToFile( ofile, wxString(wxT("perlexec:s:")) + getPerlExec() );
    FileParser::writeLineToFile( ofile, wxString(wxT("telnetargument:s:")) + getTelnetArgument() );
    FileParser::writeLineToFile( ofile, wxString(wxT("SSHargument:s:")) + getSSHArgument() );
    FileParser::writeLineToFile( ofile, wxString(wxT("perlargument:s:")) + getPerlArgument() );
    FileParser::writeLineToFile( ofile, wxString(wxT("frameheight:i:")) << getMainFrameHeight() );
    FileParser::writeLineToFile( ofile, wxString(wxT("framewidth:i:")) << getMainFrameWidth() );

    FileParser::writeLineToFile( ofile, wxString(wxT("column0width:i:")) << getColumn0Width() );
    FileParser::writeLineToFile( ofile, wxString(wxT("column1width:i:")) << getColumn1Width() );
    FileParser::writeLineToFile( ofile, wxString(wxT("column2width:i:")) << getColumn2Width() );
    FileParser::writeLineToFile( ofile, wxString(wxT("column3width:i:")) << getColumn3Width() );
    FileParser::writeLineToFile( ofile, wxString(wxT("column4width:i:")) << getColumn4Width() );
    FileParser::writeLineToFile( ofile, wxString(wxT("column5width:i:")) << getColumn5Width() );

    ofile.close();
}

void Settings::loadSettings()
{
    wxString filename( getSettingsPath() + wxT("settings") );

    /** make sure our settings file exist, even if it's empty ;) **/
    if ( wxFileExists( filename ) == false ) {
        std::ofstream ofile;
        ofile.open( filename.mb_str(), std::ios::out|std::ios::binary );
        FileParser::writeLineToFile( ofile, wxT("" ) );
        ofile.close();
    }

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

        setMainFrameHeight( wxAtoi( FileParser::getStringFromFile( wxT("frameheight:i:"), allLines ) ) );
        setMainFrameWidth( wxAtoi( FileParser::getStringFromFile( wxT("framewidth:i:"), allLines ) ) );

        int col0width = FileParser::getIntegerFromFile( wxT("column0width:i:"), allLines );
        col0width == 0 ? setColumn0Width( 80 ) : setColumn0Width( col0width );

        int col1width = FileParser::getIntegerFromFile( wxT("column1width:i:"), allLines );
        col1width == 0 ? setColumn1Width( 90 ) : setColumn1Width( col1width );

        int col2width = FileParser::getIntegerFromFile( wxT("column2width:i:"), allLines );
        col2width == 0 ? setColumn2Width( 100 ) : setColumn2Width( col2width );

        int col3width = FileParser::getIntegerFromFile( wxT("column3width:i:"), allLines );
        col3width == 0 ? setColumn3Width( 87 ) : setColumn3Width( col3width );

        int col4width = FileParser::getIntegerFromFile( wxT("column4width:i:"), allLines );
        col4width == 0 ? setColumn4Width( 82 ) : setColumn4Width( col4width );

        int col5width = FileParser::getIntegerFromFile( wxT("column5width:i:"), allLines );
        col5width == 0 ? setColumn5Width( 107 ) : setColumn5Width( col5width );
    }
    rfile.close();
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

wxString Settings::getCommandDatabasePath() const
{
    return commandDatabasePath;
}

int Settings::getMainFrameWidth() const
{
    return mainFrameWidth;
}

int Settings::getMainFrameHeight() const
{
    return mainFrameHeight;
}

void Settings::setMainFrameWidth( int mainFrameWidth )
{
    this->mainFrameWidth = mainFrameWidth;
}

void Settings::setMainFrameHeight( int mainFrameHeight )
{
    this->mainFrameHeight = mainFrameHeight;
}

/** column settings. These will be replaced at 1.2 or 1.3 once dynamic columns are in place **/
void Settings::setColumn0Width( int column0Width )
{
    this->column0Width = column0Width;
}

int Settings::getColumn0Width() const
{
    return column0Width;
}

void Settings::setColumn1Width( int column1Width )
{
    this->column1Width = column1Width;
}

int Settings::getColumn1Width() const
{
    return column1Width;
}

void Settings::setColumn2Width( int column2Width )
{
    this->column2Width = column2Width;
}

int Settings::getColumn2Width() const
{
    return column2Width;
}

void Settings::setColumn3Width( int column3Width )
{
    this->column3Width = column3Width;
}

int Settings::getColumn3Width() const
{
    return column3Width;
}

void Settings::setColumn4Width( int column4Width )
{
    this->column4Width = column4Width;
}

int Settings::getColumn4Width() const
{
    return column4Width;
}

void Settings::setColumn5Width( int column5Width )
{
    this->column5Width = column5Width;
}

int Settings::getColumn5Width() const
{
    return column5Width;
}
