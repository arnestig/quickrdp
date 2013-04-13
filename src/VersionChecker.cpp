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

#include <wx/msgdlg.h>
#include "VersionChecker.h"
#include "version.h"

DEFINE_EVENT_TYPE( wxEVT_VERSION_CHECK_DONE )
DEFINE_EVENT_TYPE( wxEVT_AUTOMATIC_VERSION_CHECK_DONE )

VersionChecker::VersionChecker( wxEvtHandler *parent, std::string url, bool automatic_check )
    :   wxThread( wxTHREAD_DETACHED ),
        parent( parent ),
        url( url ),
        automatic_check( automatic_check )

{
}

VersionChecker::~VersionChecker()
{
}

bool VersionChecker::execute( wxString &version )
{
    std::string retData = get( url.c_str() );

    if ( retData.empty() == false ) {
        std::string quickrdp_str = "QuickRDP-";
        std::string exe_str = "-setup.exe";
        std::string ourVersion = std::string( Version::getNumericVersion().mb_str() );
        std::string latestVersion;


        size_t first_quickrdp = retData.find( quickrdp_str );
        size_t first_exe = retData.find( exe_str );

        if ( first_exe != std::string::npos && first_quickrdp != std::string::npos ) { /** located the latest version **/
            latestVersion = retData.substr( first_quickrdp+quickrdp_str.length(),first_exe-first_quickrdp-exe_str.length()+1 );
        }

        if ( latestVersion.compare(ourVersion) > 0 ) { /** is this better than we got? **/
            version = wxString::FromUTF8( latestVersion.c_str() );
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }


}

int VersionChecker::writer( char *data, size_t size, size_t nmemb, std::string *buffer_in )
{
    if ( buffer_in != NULL )
    {
        buffer_in->append(data, size * nmemb );
        return size * nmemb;
    }

    return 0;
}
std::string VersionChecker::get( const char* url )
{
    CURL *curl;
    CURLcode result = CURLE_FAILED_INIT;
    curl = curl_easy_init();

    std::string buffer = "";

    if ( curl ) {
        curl_easy_setopt( curl, CURLOPT_URL, url );
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, &VersionChecker::writer );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, &buffer );
        result = curl_easy_perform( curl );
    }

    curl_easy_cleanup( curl );

    if ( result == CURLE_OK ) {
        return buffer;
    }
    return "";
}

void *VersionChecker::Entry()
{
    /** execute our thread and check for a new version, then return information to the main frame **/

    wxCommandEvent evt( wxEVT_AUTOMATIC_VERSION_CHECK_DONE, wxID_ANY );
    if ( automatic_check == false ) {
        evt.SetEventType( wxEVT_VERSION_CHECK_DONE );
    }

    wxString latestVersion = wxT("");
    if ( execute( latestVersion ) == true ) {
        evt.SetInt( 1 );
        evt.SetString( latestVersion );
    } else {
        evt.SetInt( 0 );
    }

    wxPostEvent( parent, evt );
    return 0;
}
