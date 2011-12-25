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

#include "PerlDatabase.h"
#include "Resources.h"
#include <fstream>
#include <wx/filefn.h>
#include <wx/filename.h>

PerlDatabase::PerlDatabase()
{
}

PerlDatabase::~PerlDatabase()
{
}

void PerlDatabase::loadDatabase()
{
    scripts.clear();
    // traverse the perl folder, looking for scripts
    wxString f = wxFindFirstFile( Resources::Instance()->getSettings()->getPerlDatabasePath() );
    while ( f.empty() == false ) {
        wxFileName fname;
        fname.Assign( f );
        addScript( fname.GetName( ) );
        f = wxFindNextFile();
    }
}

std::vector< wxString > PerlDatabase::getScripts()
{
    if ( isDatabaseLoaded() == false ) {
        loadDatabase();
    }

    std::vector< wxString > scriptNames;
    for ( std::map< wxString, wxString >::const_iterator it = scripts.begin(); it != scripts.end(); ++it ) {
        scriptNames.push_back( (*it).first );
    }
    return scriptNames;
}

const wxString PerlDatabase::getScriptContent( wxString script )
{
    for ( std::map< wxString, wxString >::const_iterator it = scripts.begin(); it != scripts.end(); ++it ) {
        if ( (*it).first == script ) {
            return (*it).second;
        }
    }
    return wxT("");
}

void PerlDatabase::deleteScript( wxString name )
{
    wxRemoveFile( Resources::Instance()->getSettings()->getPerlDatabasePath() + name );
    scripts.erase( name );
}

bool PerlDatabase::addScript( wxString name )
{
    wxString fullFilename = Resources::Instance()->getSettings()->getPerlDatabasePath() + name;
    if ( wxFileExists( fullFilename ) == true ) {
        int length;
        char * buffer;

        std::ifstream is;
        is.open( fullFilename.mb_str(), std::ios::binary );

        // get length of file:
        is.seekg (0, std::ios::end);
        length = is.tellg();
        is.seekg (0, std::ios::beg);

        // allocate memory:
        buffer = new char [length];

        // read data as a block:
        is.read (buffer,length);
        is.close();

        wxString data(buffer,wxConvUTF8);
        scripts[ name ] = data;

        delete[] buffer;

        return true;
    } else {
        return false;
    }
}

void PerlDatabase::saveScript( wxString name, wxString content )
{
    /** save to our memory database **/
    scripts[ name ] = content;

    /** write to the file as well **/
    std::ofstream ofile;
    ofile.open( wxString( Resources::Instance()->getSettings()->getPerlDatabasePath() + name ).mb_str(), std::ios::out|std::ios::binary );
    ofile.write( content.mb_str(), content.Len() );
    ofile.close();
}

bool PerlDatabase::isDatabaseLoaded() const
{
    return scripts.size() > 0;
}
