/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, telnet and SSH connections

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
#include "QuickrdpFunctions.h"
#include "ConnectionList.h"
#include <wx/stdpaths.h>
#include <fstream>
#include "version.h"

#ifndef DATA_PATH
#define DATA_PATH ""
#endif

Settings::Settings()
    :   mainFrameWidth(600),
        mainFrameHeight(400)
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

    // command database path
    #if defined(__WXMSW__)
        commandDatabasePath = getSettingsPath() + wxT("commands\\");
    #elif defined(__UNIX__)
        commandDatabasePath = getSettingsPath() + wxT("commands/");
    #endif

    /** make sure we have the folders created for our settings, connection database and command database **/
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

    if ( wxDirExists( getCommandDatabasePath() ) == false ) {
        #if defined(__WXMSW__)
            wxMkDir( getCommandDatabasePath().fn_str() );
        #elif defined(__UNIX__)
            wxMkDir( getCommandDatabasePath().fn_str(), 0700 );
        #endif
    }

    /** fill our connectionListColumMapo with all our available columns **/
    connectionListColumnMap.push_back( std::make_pair( wxT("Hostname"), ConnectionListColumn::HOSTNAME ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Port"), ConnectionListColumn::PORT ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Username"), ConnectionListColumn::USERNAME ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Connection"), ConnectionListColumn::CONNECTIONTYPE ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Use console"), ConnectionListColumn::USE_CONSOLE ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Resolution"), ConnectionListColumn::RESOLUTION ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Comment"), ConnectionListColumn::COMMENT ) );
    connectionListColumnMap.push_back( std::make_pair( wxT("Client name"), ConnectionListColumn::CLIENT_NAME ) );

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

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("telnetexec:s:")) + getTelnetExec() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("SSHexec:s:")) + getSSHExec() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("vncexec:s:")) + getVNCExec() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("telnetargument:s:")) + getTelnetArgument() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("SSHargument:s:")) + getSSHArgument() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("vncargument:s:")) + getVNCArgument() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("frameheight:i:")) << getMainFrameHeight() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("framewidth:i:")) << getMainFrameWidth() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("version:s:")) + Version::getNumericVersion() );

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectionlistcolumns:i:")) << getConnectionListColumns() );

    for ( std::vector< int >::const_iterator it = connectionListColumnWidths.begin(); it != connectionListColumnWidths.end(); ++it ) {
        quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectionlistcolumnwidth:i:")) << (*it) );
    }

    std::vector< wxString > conTabs = getConnectionTabs();
    for ( std::vector< wxString >::const_iterator it = conTabs.begin(); it != conTabs.end(); ++it ) {
        quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectiontab:s:")) << (*it) );
    }

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectiontabselected:i:")) << getConnectionTabSelected() );

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("newconkeycode:i:")) << getNewConnectionShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("newconmodifier:i:")) << getNewConnectionShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("dupconkeycode:i:")) << getDupConnectionShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("dupconmodifier:i:")) << getDupConnectionShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("propconkeycode:i:")) << getPropConnectionShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("propconmodifier:i:")) << getPropConnectionShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("selallconkeycode:i:")) << getSelectAllConnectionsShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("selallconmodifier:i:")) << getSelectAllConnectionsShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("commanddialogkeycode:i:")) << getCommandDialogShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("commanddialogmodifier:i:")) << getCommandDialogShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("manualcckeycode:i:")) << getManualCCShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("manualccmodifier:i:")) << getManualCCShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectwhenreadykeycode:i:")) << getConnectWhenReadyShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("connectwhenreadymodifier:i:")) << getConnectWhenReadyShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("newtabkeycode:i:")) << getNewTabShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("newtabmodifier:i:")) << getNewTabShortcut().second );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("closetabkeycode:i:")) << getCloseTabShortcut().first );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("closetabmodifier:i:")) << getCloseTabShortcut().second );

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("CCTimeout:i:")) << getCCTimeout() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("CCUpdateInterval:i:")) << getCCUpdateInterval() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("CCAutomaticCheck:i:")) << getCCAutomaticCheck() );
    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("CCWorkerThreads:i:")) << getCCWorkerThreads() );

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("GreyListBackground:b:")) << getGreyListBackground() );

    quickRDP::FileParser::writeLineToFile( ofile, wxString(wxT("RDPDefaultResolution:i:")) << getRDPDefaultResolution() );

    ofile.close();
}

void Settings::loadSettings()
{
    wxString filename( getSettingsPath() + wxT("settings") );

    /** make sure our settings file exist, even if it's empty ;) **/
    if ( wxFileExists( filename ) == false ) {
        std::ofstream ofile;
        ofile.open( filename.mb_str(), std::ios::out|std::ios::binary );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("" ) );
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
        std::vector<wxString> allLines;
        while ( getline(rfile,inputData) ) {
            wxString input( inputData.c_str(), wxConvUTF8 );
            input.Replace(wxT("\r"),wxT(""));
            input.Replace(wxT("\n"),wxT(""));
            allLines.push_back( input );
        }
        setTelnetExec( quickRDP::FileParser::getStringFromFile( wxT("telnetexec:s:"), allLines ) );
        setSSHExec( quickRDP::FileParser::getStringFromFile( wxT("SSHexec:s:"), allLines ) );
        setVNCExec( quickRDP::FileParser::getStringFromFile( wxT("vncexec:s:"), allLines ) );
        setTelnetArgument( quickRDP::FileParser::getStringFromFile( wxT("telnetargument:s:"), allLines ) );
        setSSHArgument( quickRDP::FileParser::getStringFromFile( wxT("SSHargument:s:"), allLines ) );
        setVNCArgument( quickRDP::FileParser::getStringFromFile( wxT("vncargument:s:"), allLines ) );
        setVersion( quickRDP::FileParser::getStringFromFile( wxT("version:s:"), allLines ) );

        int frameHeight = quickRDP::FileParser::getIntegerFromFile( wxT("frameheight:i:"), allLines );
        int frameWidth = quickRDP::FileParser::getIntegerFromFile( wxT("framewidth:i:"), allLines );
        if ( frameHeight > 0 ) {
            setMainFrameHeight( frameHeight );
        }
        if ( frameWidth > 0 ) {
            setMainFrameWidth( frameWidth );
        }

        int connectionListColumns = quickRDP::FileParser::getIntegerFromFile( wxT("connectionlistcolumns:i:"), allLines );
        connectionListColumns == 0 ? setConnectionListColumns(ConnectionListColumn::COMMENT|
                                                              ConnectionListColumn::CONNECTIONTYPE|
                                                              ConnectionListColumn::HOSTNAME|
                                                              ConnectionListColumn::USERNAME|
                                                              ConnectionListColumn::USE_CONSOLE ) : setConnectionListColumns( connectionListColumns );

        connectionListColumnWidths = quickRDP::FileParser::getIntegerVectorFromFile( wxT("connectionlistcolumnwidth:i:"), allLines );
        connectionListColumnWidths.resize( 8, 80 ); /** Make sure we have 8 items in our column width vector **/

        setConnectionTabs( quickRDP::FileParser::getStringVectorFromFile( wxT("connectiontab:s:"), allLines ) );
        setConnectionTabSelected( quickRDP::FileParser::getIntegerFromFile( wxT("connectiontabselected:i:"), allLines ) );

        setNewConnectionShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("newconkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("newconmodifier:i:"), allLines ) ) );
        setDupConnectionShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("dupconkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("dupconmodifier:i:"), allLines ) ) );
        setPropConnectionShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("propconkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("propconmodifier:i:"), allLines ) ) );
        setSelectAllConnectionsShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("selallconkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("selallconmodifier:i:"), allLines ) ) );
        setCommandDialogShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("commanddialogkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("commanddialogmodifier:i:"), allLines ) ) );
        setManualCCShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("manualcckeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("manualccmodifier:i:"), allLines ) ) );
        setConnectWhenReadyShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("connectwhenreadykeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("connectwhenreadymodifier:i:"), allLines ) ) );
        setNewTabShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("newtabkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("newtabmodifier:i:"), allLines ) ) );
        setCloseTabShortcut( std::make_pair< int, int > ( quickRDP::FileParser::getIntegerFromFile( wxT("closetabkeycode:i:"), allLines ), quickRDP::FileParser::getIntegerFromFile( wxT("closetabmodifier:i:"), allLines ) ) );

        /** Connection checker settings **/
        int l_CCTimeout = quickRDP::FileParser::getIntegerFromFile( wxT("CCTimeout:i:"), allLines );
        if ( l_CCTimeout  < 20 || l_CCTimeout > 2000 ) {
            setCCTimeout( 200 );
        } else {
            setCCTimeout( l_CCTimeout );
        }

        int l_CCUpdateInterval = quickRDP::FileParser::getIntegerFromFile( wxT("CCUpdateInterval:i:"), allLines );
        if ( l_CCUpdateInterval  < 10 || l_CCTimeout > 360 ) {
            setCCUpdateInterval( 60 );
        } else {
            setCCUpdateInterval( l_CCUpdateInterval );
        }

        setCCAutomaticCheck( quickRDP::FileParser::getIntegerFromFile( wxT("CCAutomaticCheck:i:"), allLines ) );
        unsigned int workerThreads = quickRDP::FileParser::getIntegerFromFile( wxT("CCWorkerThreads:i:"), allLines );
        if ( workerThreads == 0 ) {
            workerThreads = 4; // set default 4 worker threads
        }
        setCCWorkerThreads( workerThreads );

        /** stylistic features **/
        setGreyListBackground( quickRDP::FileParser::getBoolFromFile( wxT("GreyListBackground:b:"), allLines ) );

        /** default settings **/
        setRDPDefaultResolution( quickRDP::FileParser::getBoolFromFile( wxT("RDPDefaultResolution:i:"), allLines ) );
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

wxString Settings::getVNCExec() const
{
    return VNCExec;
}

wxString Settings::getVNCArgument() const
{
    return VNCArgument;
}

wxString Settings::getVersion() const
{
    return version;
}

std::pair< int, int > Settings::getNewConnectionShortcut() const
{
    return newConnectionShortcut;
}

std::pair< int, int > Settings::getDupConnectionShortcut() const
{
    return dupConnectionShortcut;
}

std::pair< int, int > Settings::getPropConnectionShortcut() const
{
    return propConnectionShortcut;
}

std::pair< int, int > Settings::getSelectAllConnectionsShortcut() const
{
    return selectAllConnectionsShortcut;
}

std::pair< int, int > Settings::getCommandDialogShortcut() const
{
    return commandDialogShortcut;
}

std::pair< int, int > Settings::getManualCCShortcut() const
{
    return manualccShortcut;
}

std::pair< int, int > Settings::getConnectWhenReadyShortcut() const
{
    return connectWhenReadyShortcut;
}

std::pair< int, int > Settings::getNewTabShortcut() const
{
    return newTabShortcut;
}

std::pair< int, int > Settings::getCloseTabShortcut() const
{
    return closeTabShortcut;
}

int Settings::getCCTimeout() const
{
    return CCTimeout;
}

void Settings::setCCTimeout( int CCTimeout )
{
    this->CCTimeout = CCTimeout;
}

int Settings::getCCUpdateInterval() const
{
    return CCUpdateInterval;
}

void Settings::setCCUpdateInterval( int CCUpdateInterval )
{
    this->CCUpdateInterval = CCUpdateInterval;
}

int Settings::getCCAutomaticCheck() const
{
    return CCAutomaticCheck;
}

void Settings::setCCAutomaticCheck( int CCAutomaticCheck )
{
    this->CCAutomaticCheck = CCAutomaticCheck;
}

unsigned int Settings::getCCWorkerThreads() const
{
    return CCWorkerThreads;
}

void Settings::setCCWorkerThreads( unsigned int CCWorkerThreads )
{
    this->CCWorkerThreads = CCWorkerThreads;
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

void Settings::setVNCExec( wxString VNCExec )
{
    this->VNCExec = VNCExec;
}

void Settings::setVNCArgument( wxString VNCArgument )
{
    this->VNCArgument = VNCArgument;
}

void Settings::setVersion( wxString version )
{
    this->version = version;
}

void Settings::setNewConnectionShortcut( std::pair< int, int > value )
{
    newConnectionShortcut = value;
}

void Settings::setDupConnectionShortcut( std::pair< int, int > value )
{
    dupConnectionShortcut = value;
}

void Settings::setPropConnectionShortcut( std::pair< int, int > value )
{
    propConnectionShortcut = value;
}

void Settings::setSelectAllConnectionsShortcut( std::pair< int, int > value )
{
    selectAllConnectionsShortcut = value;
}

void Settings::setCommandDialogShortcut( std::pair< int, int > value )
{
    commandDialogShortcut = value;
}

void Settings::setManualCCShortcut( std::pair< int, int > value )
{
    manualccShortcut = value;
}

void Settings::setConnectWhenReadyShortcut( std::pair< int, int > value )
{
    connectWhenReadyShortcut = value;
}

void Settings::setNewTabShortcut( std::pair< int, int > value )
{
    newTabShortcut = value;
}

void Settings::setCloseTabShortcut( std::pair< int, int > value )
{
    closeTabShortcut = value;
}

wxString Settings::getSettingsPath() const
{
    return settingsPath;
}

wxString Settings::getDatabasePath() const
{
    return databasePath;
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

void Settings::setConnectionListColumns( int connectionListColumns )
{
    this->connectionListColumns = connectionListColumns;
}

int Settings::getConnectionListColumns() const
{
    return connectionListColumns;
}

bool Settings::isConnectionListColumnActive( wxString columnName )
{
    bool isColumnActive = false;
    for ( std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > >::const_iterator it = connectionListColumnMap.begin(); it != connectionListColumnMap.end(); ++it ) {
        if ( (*it).first == columnName ) {
            isColumnActive = ( getConnectionListColumns() & (*it).second );
        }
    }
    return isColumnActive;
}

int Settings::getConnectionListColumnWidth( int columnId ) const
{
    return connectionListColumnWidths[ columnId ];
}

void Settings::setConnectionListColumnWidths( std::vector< int > connectionListColumnWidths )
{
    this->connectionListColumnWidths = connectionListColumnWidths;
}

std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > Settings::getConnectionListColumMap() const
{
    return connectionListColumnMap;
}

/** functions for setting and getting the saved connection tabs **/
void Settings::setConnectionTabs( std::vector< wxString > connectionTabs )
{
    this->connectionTabs = connectionTabs;
}

std::vector< wxString > Settings::getConnectionTabs() const
{
    return connectionTabs;
}

void Settings::setConnectionTabSelected( int selectedTab )
{
    this->selectedTab = selectedTab;
}

int Settings::getConnectionTabSelected() const
{
    return selectedTab;
}

bool Settings::getGreyListBackground() const
{
    return greyListBackground;
}

void Settings::setGreyListBackground( bool greyListBackground )
{
    this->greyListBackground = greyListBackground;
}

int Settings::getRDPDefaultResolution() const
{
    return RDPDefaultResolution;
}

void Settings::setRDPDefaultResolution( int RDPDefaultResolution )
{
    this->RDPDefaultResolution = RDPDefaultResolution;
}
