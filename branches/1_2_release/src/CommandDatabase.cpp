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

#include "CommandDatabase.h"
#include "Resources.h"
#include <fstream>
#include <wx/filefn.h>
#include <wx/filename.h>
#include "FileParser.h"

/** BEGIN COMMAND **/

Command::Command( wxString name, wxString program, wxString argument, bool favorite, bool safety )
    :   name( name ),
        program( program ),
        argument( argument ),
        favorite( favorite ),
        safety( safety )
{
}

Command::~Command()
{
}

wxString Command::getName() const
{
    return name;
}

wxString Command::getProgram() const
{
    return program;
}

wxString Command::getArgument() const
{
    return argument;
}

bool Command::getFavorite() const
{
    return favorite;
}

bool Command::getSafety() const
{
    return safety;
}

void Command::setName( wxString name )
{
    this->name = name;
}

void Command::setProgram( wxString program )
{
    this->program = program;
}

void Command::setArgument( wxString argument )
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

bool Command::execute( RDPConnection *connection )
{
    if ( connection != NULL ) {
        if ( getSafety() == true ) {
            if ( wxMessageBox( wxT("Do you want to run the command ") + getName() + wxT("?"), wxT("Run command?"), wxYES_NO ) != wxYES ) {
                return false;
            }
        }
        wxExecute( getProgram() + wxT(" ") + quickRDP::FileParser::getRealArgumentString( getArgument(), connection ) );
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
}

void CommandDatabase::loadDatabase()
{
    // delete our previous command database
    for ( size_t commandId = 0; commandId < commands.size(); ++commandId ) {
        delete commands[ commandId ];
        commands.erase( commands.begin() + commandId );
    }

    // traverse the commands folder and add the commands we find there.
    wxString f = wxFindFirstFile( Resources::Instance()->getSettings()->getCommandDatabasePath() );
    while ( f.empty() == false ) {
        wxFileName fname;
        fname.Assign( f );
        addCommand( fname.GetName( ) );
        f = wxFindNextFile();
    }
}

std::vector< Command* > CommandDatabase::getCommands()
{
    if ( isDatabaseLoaded() == false ) {
        loadDatabase();
    }

    return commands;
}

Command* CommandDatabase::getCommand( wxString name )
{
    for ( std::vector< Command* >::const_iterator it = commands.begin(); it != commands.end(); ++it ) {
        if ( (*it)->getName() == name ) {
            return (*it);
        }
    }
    return NULL;
}

void CommandDatabase::deleteCommand( wxString name )
{
    wxRemoveFile( Resources::Instance()->getSettings()->getCommandDatabasePath() + name );
    for ( size_t commandId = 0; commandId < commands.size(); ++commandId ) {
        if ( commands[ commandId ]->getName() == name ) {
            delete commands[ commandId ];
            commands.erase( commands.begin() + commandId );
        }
    }
}

bool CommandDatabase::addCommand( wxString name )
{
    wxString filename = Resources::Instance()->getSettings()->getCommandDatabasePath() + name;
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

            wxString program = quickRDP::FileParser::getStringFromFile( wxT("program:s:"), allLines );
            wxString argument = quickRDP::FileParser::getStringFromFile( wxT("argument:s:"), allLines );
            bool favorite = quickRDP::FileParser::getBoolFromFile( wxT("favorite:b:"), allLines );
            bool safety = quickRDP::FileParser::getBoolFromFile( wxT("safety:b:"), allLines );
            commands.push_back( new Command( name, program, argument, favorite, safety ) );
            return true;
        }
    }
    return false;
}

void CommandDatabase::saveCommand( wxString name, wxString program, wxString argument, bool favorite, bool safety )
{
    Command *command = getCommand( name );
    if ( command != NULL ) { /** the command exists, overwrite the old **/
        command->setName( name );
        command->setProgram( program );
        command->setArgument( argument );
        command->setFavorite( favorite );
        command->setSafety( safety );
    } else { /** command doesn't exist, create a new one **/
        commands.push_back( new Command( name, program, argument, favorite, safety ) );
    }

    /** write to the file as well **/
    std::ofstream ofile;
    ofile.open( wxString( Resources::Instance()->getSettings()->getCommandDatabasePath() + name ).mb_str(), std::ios::out|std::ios::binary );
    quickRDP::FileParser::writeLineToFile( ofile, wxT("program:s:") + program );
    quickRDP::FileParser::writeLineToFile( ofile, wxT("argument:s:") + argument );
    quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("favorite:b:%d"), favorite ) );
    quickRDP::FileParser::writeLineToFile( ofile, wxString::Format( wxT("safety:b:%d"), safety ) );
    ofile.close();
}

bool CommandDatabase::isDatabaseLoaded() const
{
    return commands.size() > 0;
}

/** END COMMANDDATABASE **/
