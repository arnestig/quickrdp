/**
    Copyright (C) 2010-2016 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

    Written by Tobias Eliasson <arnestig@gmail.com>.

    This file is part of quickRDP <https://github.com/arnestig/quickrdp>.

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

#include "CommandDatabase.h"
#include "Resources.h"
#include <fstream>
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <wx/filefn.h>
#include <wx/filename.h>
#include <wx/textdlg.h>
#include "QuickrdpFunctions.h"

/** BEGIN COMMAND **/

Command::Command( wxString name, std::map< int, wxString > program, std::map< int, wxString > argument, wxString filename, bool favorite, bool safety, int shortcutModifier, int shortcutKey, bool useSpecificCommands )
    :   name( name ),
        program( program ),
        argument( argument ),
        filename( filename ),
        favorite( favorite ),
        safety( safety ),
        shortcutModifier( shortcutModifier ),
        shortcutKey( shortcutKey ),
        useSpecificCommands( useSpecificCommands )
{
}

Command::~Command()
{
}

wxString Command::getName() const
{
    return name;
}

std::map< int, wxString > Command::getProgram()
{
    return program;
}

std::map< int, wxString > Command::getArgument()
{
    return argument;
}

wxString Command::getProgramByConnection( ConnectionType::ConnectionType connectionType )
{
    /** if we have set connection target to 0 we return the generic program and argument string.
        if not we will have to return the specific value based on the connection **/
    if ( getUseSpecificCommands() == 0 ) {
        return program[ -1 ];
    } else {
        return program[ connectionType ];
    }
}

wxString Command::getArgumentByConnection( ConnectionType::ConnectionType connectionType )
{
    /** if we have set connection target to 0 we return the generic program and argument string.
        if not we will have to return the specific value based on the connection **/
    if ( getUseSpecificCommands() == 0 ) {
        return argument[ -1 ];
    } else {
        return argument[ connectionType ];
    }
}

wxString Command::getFilename() const
{
    return filename;
}

bool Command::getFavorite() const
{
    return favorite;
}

bool Command::getSafety() const
{
    return safety;
}

int Command::getShortcutModifier() const
{
    return shortcutModifier;
}

int Command::getShortcutKey() const
{
    return shortcutKey;
}

bool Command::getUseSpecificCommands() const
{
    return useSpecificCommands;
}

void Command::setName( wxString name )
{
    this->name = name;
}

void Command::setProgram( std::map< int, wxString > program )
{
    this->program = program;
}

void Command::setArgument( std::map< int, wxString > argument )
{
    this->argument = argument;
}

void Command::setFavorite( bool favorite )
{
    this->favorite = favorite;
}

void Command::setSafety( bool safety )
{
    this->safety = safety;
}

void Command::setShortcutModifier( int shortcutModifier )
{
    this->shortcutModifier = shortcutModifier;
}

void Command::setShortcutKey( int shortcutKey )
{
    this->shortcutKey = shortcutKey;
}

void Command::setUseSpecificCommands( bool useSpecificCommands )
{
    this->useSpecificCommands = useSpecificCommands;
}

wxString Command::loadCustomArguments( wxString &argument )
{
    /** locate custom ampersand arguments **/
    size_t cust_arg_pos = argument.find_first_of( wxT( "$" ) );
    while( cust_arg_pos != std::string::npos ) {
        size_t next_arg_pos = argument.find_first_of( wxT("$"), cust_arg_pos + 1 );
        if ( next_arg_pos != std::string::npos ) {
            int argLength = ( next_arg_pos - cust_arg_pos ) + 1;
            if ( argLength > 2 ) {
                wxString arg = argument.substr( cust_arg_pos, (next_arg_pos-cust_arg_pos)+1 );
                wxString argName = arg.substr( 1, arg.length() - 2 ) + wxT(":");
                wxString newArgument = wxGetTextFromUser( argName, wxT("Custom argument") );
                argument.Replace( arg, newArgument );
            }
        }
        cust_arg_pos = argument.find_first_of( wxT("$"), cust_arg_pos + 1 );
    }

    return argument;
}

bool Command::execute( RDPConnection *connection )
{
    if ( connection != NULL ) {
        wxString arguments = getArgumentByConnection( connection->getConnectionType() );
        loadCustomArguments( arguments );
        wxExecute( getProgramByConnection( connection->getConnectionType() ) + wxT(" ") + quickRDP::FileParser::getRealArgumentString( arguments, connection ) );
    } else {
        wxMessageBox( wxT("Invalid connection received when executing command!"), wxT("Error"), wxICON_ERROR );
        return false;
    }
    return true;
}

/** END COMMAND **/


/** BEGIN COMMANDDATABASE **/

CommandDatabase::CommandDatabase()
{
}

CommandDatabase::~CommandDatabase()
{
	for ( std::vector< Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
		delete (*it);
	}
	commands.clear();
}

void CommandDatabase::loadDatabase()
{
    // delete our previous command database
    for ( std::vector< Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
        delete (*it);
    }
    commands.clear();

    // traverse the commands folder and add the commands we find there.
    wxString f = wxFindFirstFile( Resources::Instance()->getSettings()->getCommandDatabasePath() );
    while ( f.empty() == false ) {
        wxFileName fname;
        fname.Assign( f );
        addCommand( fname.GetName( ) );
        f = wxFindNextFile();
    }
}

std::vector< Command* > CommandDatabase::getCommands( bool forceReload )
{
    if ( isDatabaseLoaded() == false || forceReload == true ) {
        loadDatabase();
    }

    return commands;
}

Command* CommandDatabase::getCommand( wxString name )
{
    if ( isDatabaseLoaded() == false ) {
        loadDatabase();
    }

    for ( std::vector< Command* >::const_iterator it = commands.begin(); it != commands.end(); ++it ) {
        if ( (*it)->getName() == name ) {
            return (*it);
        }
    }
    return NULL;
}

Command* CommandDatabase::getCommandWithShortcut( int shortcutModifier, int shortcutKey )
{
    if ( isDatabaseLoaded() == false ) {
        loadDatabase();
    }

    for ( std::vector< Command* >::const_iterator it = commands.begin(); it != commands.end(); ++it ) {
        if ( (*it)->getShortcutModifier() == shortcutModifier && (*it)->getShortcutKey() == shortcutKey ) {
            return (*it);
        }
    }
    return NULL;
}

void CommandDatabase::deleteCommand( wxString name )
{
    Command *curCommand = getCommand( name );
    if ( curCommand != NULL ) {
        if ( wxRemoveFile( Resources::Instance()->getSettings()->getCommandDatabasePath() + curCommand->getFilename() ) == false ) {
            wxMessageBox( wxString::Format( wxT("Unable to remove the command. Failure when deleting the file: %s"), wxSysErrorMsg( wxSysErrorCode() ) ), wxT("Error"), wxICON_ERROR );
        }
        for ( size_t commandId = 0; commandId < commands.size(); ++commandId ) {
            if ( commands[ commandId ]->getName() == name ) {
                delete commands[ commandId ];
                commands[ commandId ] = NULL;
                commands.erase( commands.begin() + commandId );
            }
        }
    }
}

bool CommandDatabase::addCommand( wxString name )
{
    wxString filename = Resources::Instance()->getSettings()->getCommandDatabasePath() + name;
    std::map< int, wxString > commandConnectionProgram;
    std::map< int, wxString > commandConnectionArgument;
    if ( wxFileExists( filename ) == true ) {
        std::ifstream rfile;

        rfile.open( filename.mb_str(), std::ios::in|std::ios::binary );

        rfile.seekg (0, std::ios::end);
        int length = rfile.tellg();
        rfile.seekg (0, std::ios::beg);

        if (length == -1) {
            return false;
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

            wxString properName = quickRDP::FileParser::getStringFromFile( wxT("name:s:"), allLines );
            commandConnectionProgram[ -1 ] = quickRDP::FileParser::getStringFromFile( wxT("program:s:"), allLines );
            commandConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = quickRDP::FileParser::getStringFromFile( wxT("programRDP:s:"), allLines );
            commandConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = quickRDP::FileParser::getStringFromFile( wxT("programTELNET:s:"), allLines );
            commandConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = quickRDP::FileParser::getStringFromFile( wxT("programSSH:s:"), allLines );
            commandConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = quickRDP::FileParser::getStringFromFile( wxT("programVNC:s:"), allLines );

            commandConnectionArgument[ -1 ] = quickRDP::FileParser::getStringFromFile( wxT("argument:s:"), allLines );
            commandConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = quickRDP::FileParser::getStringFromFile( wxT("argumentRDP:s:"), allLines );
            commandConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = quickRDP::FileParser::getStringFromFile( wxT("argumentTELNET:s:"), allLines );
            commandConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = quickRDP::FileParser::getStringFromFile( wxT("argumentSSH:s:"), allLines );
            commandConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = quickRDP::FileParser::getStringFromFile( wxT("argumentVNC:s:"), allLines );

            bool favorite = quickRDP::FileParser::getBoolFromFile( wxT("favorite:b:"), allLines );
            bool safety = quickRDP::FileParser::getBoolFromFile( wxT("safety:b:"), allLines );
            int shortcutModifier = quickRDP::FileParser::getIntegerFromFile( wxT("shortcutmodifier:i:"), allLines );
            int shortcutKey = quickRDP::FileParser::getIntegerFromFile( wxT("shortcutkey:i:"), allLines );
            bool useSpecificCommands = quickRDP::FileParser::getIntegerFromFile( wxT("connectiontarget:b:"), allLines );
            if ( properName.empty() == true ) {
                properName = name;
            }
            commands.push_back( new Command( properName, commandConnectionProgram, commandConnectionArgument, name, favorite, safety, shortcutModifier, shortcutKey, useSpecificCommands ) );
            return true;
        }
    }
    return false;
}

void CommandDatabase::saveCommand( Command *command )
{
    saveCommand( command->getName(), command->getProgram(), command->getArgument(), command->getFavorite(), command->getSafety(), command->getShortcutModifier(), command->getShortcutKey(), command->getUseSpecificCommands() );
}

void CommandDatabase::saveCommand( wxString name, std::map< int, wxString > program, std::map< int, wxString > argument, bool favorite, bool safety, int shortcutModifier, int shortcutKey, bool useSpecificCommands )
{
    wxString filename;
    Command *command = getCommand( name );
    if ( command != NULL ) { /** the command exists, overwrite the old **/
        command->setName( name );
        command->setProgram( program );
        command->setArgument( argument );
        command->setFavorite( favorite );
        command->setSafety( safety );
        command->setShortcutModifier( shortcutModifier );
        command->setShortcutKey( shortcutKey );
        command->setUseSpecificCommands( useSpecificCommands );
        filename = command->getFilename();
    } else { /** command doesn't exist, create a new one **/
        filename = quickRDP::Generators::generateHex( 8 );
        commands.push_back( new Command( name, program, argument, filename, favorite, safety, shortcutModifier, shortcutKey, useSpecificCommands ) );
    }

    /** write to the file as well **/
    std::ofstream ofile;
    ofile.open( wxString( Resources::Instance()->getSettings()->getCommandDatabasePath() + filename ).mb_str(), std::ios::out|std::ios::binary );
    if ( !ofile ) {
        wxMessageBox( wxT("Failed to save the command as file!" ) );
    } else {
        quickRDP::FileParser::writeLineToFile( ofile, wxT("name:s:") + name );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("program:s:") + program[ -1 ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("programRDP:s:") + program[ static_cast< int >( ConnectionType::RDP ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("programTELNET:s:") + program[ static_cast< int >( ConnectionType::TELNET ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("programSSH:s:") + program[ static_cast< int >( ConnectionType::SSH ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("programVNC:s:") + program[ static_cast< int >( ConnectionType::VNC ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("argument:s:") + argument[ -1 ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("argumentRDP:s:") + argument[ static_cast< int >( ConnectionType::RDP ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("argumentTELNET:s:") + argument[ static_cast< int >( ConnectionType::TELNET ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("argumentSSH:s:") + argument[ static_cast< int >( ConnectionType::SSH ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxT("argumentVNC:s:") + argument[ static_cast< int >( ConnectionType::VNC ) ] );
        quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("favorite:b:%d"), favorite ) );
        quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("safety:b:%d"), safety ) );
        quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("shortcutmodifier:i:%d"), shortcutModifier ) );
        quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("shortcutkey:i:%d"), shortcutKey ) );
        quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("connectiontarget:b:%d"), useSpecificCommands ) );
    }
    ofile.close();
}

bool CommandDatabase::isDatabaseLoaded() const
{
    return commands.size() > 0;
}

/** END COMMANDDATABASE **/
