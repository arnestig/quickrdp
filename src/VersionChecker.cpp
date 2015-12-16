/**
    Copyright (C) 2010-2015 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#include <wx/msgdlg.h>
#include "VersionChecker.h"
#include "version.h"

DEFINE_EVENT_TYPE( wxEVT_VERSION_CHECK_DONE )
DEFINE_EVENT_TYPE( wxEVT_AUTOMATIC_VERSION_CHECK_DONE )
DEFINE_EVENT_TYPE( wxEVT_VERSION_DOWNLOAD_COMPLETE )

VersionChecker::VersionChecker( wxEvtHandler *parent )
	:	parent( parent )
{
}

VersionChecker::~VersionChecker()
{
	/** delete all our worker threads gracefully **/
	for ( std::vector< VersionCheckerWorker* >::iterator it = workerThreads.begin(); it != workerThreads.end(); ++it ) {
		if ( (*it) != NULL ) {
			(*it)->Delete();
		}
	}

	/** make sure that the threads are dead before leaving here **/
	while ( true ) {
		bool threadsDone = true;
		for ( std::vector< VersionCheckerWorker* >::iterator it = workerThreads.begin(); it != workerThreads.end(); ++it ) {
			if ( (*it) != NULL ) {
				threadsDone = false;
			}
		}

		if ( threadsDone == true ) {
			break;
		}

		wxMilliSleep( 1 );
	}
}

void VersionChecker::checkForNewVersion( TaskType taskType, std::string url )
{
    VersionCheckerWorker *worker = new VersionCheckerWorker( this, url, taskType );
    if ( worker->Create() != wxTHREAD_NO_ERROR ) {
        delete worker;
        worker = NULL;
        wxMessageBox( wxT("Error while creating HTTP thread!") );
    } else {
        if ( worker->Run() != wxTHREAD_NO_ERROR ) {
            delete worker;
            worker = NULL;
            wxMessageBox( wxT("Error while running HTTP thread!") );
        }
    }

	if ( worker != NULL ) {
		workerThreads.push_back( worker );
	}
}

void VersionChecker::workerThreadDone( VersionCheckerWorker *thread )
{
	mutex.Lock();
	for( unsigned int i = 0; i < workerThreads.size(); i++ ) {
		if ( workerThreads[ i ] == thread ) {
			workerThreads[ i ] = NULL;
		}
	}
	mutex.Unlock();
}

void VersionChecker::postEvent( wxCommandEvent event )
{
    mutex.Lock();
    wxPostEvent( parent, event );
    mutex.Unlock();
}

void VersionChecker::setNewVersionURL( wxString newVersionURL )
{
    this->newVersionURL = newVersionURL;
}

wxString VersionChecker::getNewVersionURL()
{
    return newVersionURL;
}

VersionCheckerWorker::VersionCheckerWorker( VersionChecker *parent, std::string url, TaskType taskType )
    :   wxThread( wxTHREAD_DETACHED ),
        parent( parent ),
        url( url ),
        taskType( taskType )
{
}

VersionCheckerWorker::~VersionCheckerWorker()
{
	parent->workerThreadDone( this );
}

bool VersionCheckerWorker::execute( wxString &version )
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

        /** okay, lets try and find the download url for this binary **/
        size_t curSeekPos = 0;
        while ( curSeekPos != std::string::npos ) {
            std::string firstDownload_str = "\"browser_download_url\"";
            size_t firstDownloadURL = retData.find( firstDownload_str, curSeekPos ) + firstDownload_str.length() + 2;
            size_t firstBracketAfterURL = retData.find( "}", firstDownloadURL ) - 1;
            std::string targetURL = retData.substr( firstDownloadURL, firstBracketAfterURL - firstDownloadURL );
            if ( targetURL.find( "exe" ) != std::string::npos ) {
                wxString versionurl = wxString::FromUTF8( targetURL.c_str() );
                parent->setNewVersionURL( versionurl );
                break;
            }
            curSeekPos = retData.find( firstDownload_str, firstBracketAfterURL );
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

bool VersionCheckerWorker::download( wxString versionurl, wxString &filename )
{
    if ( versionurl.IsEmpty() == true ) {
        return false;
    }
    filename = wxFileName::CreateTempFileName( wxT("quickrdp") );
    std::string retData = get( versionurl.c_str() );
    if ( retData.empty() == true ) {
        return false;
    }
    std::ofstream out;
    out.open(filename.mb_str(), std::ios::out | std::ios::binary );
    out.write( retData.c_str(), sizeof(char)*retData.size() );
    out.close();
    return true;
}

int VersionCheckerWorker::writer( char *data, size_t size, size_t nmemb, std::string *buffer_in )
{
    if ( buffer_in != NULL )
    {
        buffer_in->append(data, size * nmemb );
        return size * nmemb;
    }

    return 0;
}

std::string VersionCheckerWorker::get( const char* url )
{
    CURL *curl;
    CURLcode result = CURLE_FAILED_INIT;
    curl = curl_easy_init();

    std::string buffer = "";

    if ( curl ) {
        curl_easy_setopt( curl, CURLOPT_URL, url );
        curl_easy_setopt( curl, CURLOPT_FOLLOWLOCATION, 1 );
        curl_easy_setopt( curl, CURLOPT_USERAGENT, "QuickRDP/1.0");
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, &VersionCheckerWorker::writer );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, &buffer );
        result = curl_easy_perform( curl );
    }

    curl_easy_cleanup( curl );

    if ( result == CURLE_OK ) {
        return buffer;
    }
    return "";
}

void *VersionCheckerWorker::Entry()
{
    /** execute our thread and check for a new version, then return information to the main frame **/
    wxCommandEvent evt( wxEVT_AUTOMATIC_VERSION_CHECK_DONE, wxID_ANY );
    switch( taskType )
    {
        case AUTOMATIC_CHECK:
            evt.SetEventType( wxEVT_AUTOMATIC_VERSION_CHECK_DONE );
        break;
        case DOWNLOAD_BINARY:
            evt.SetEventType( wxEVT_VERSION_DOWNLOAD_COMPLETE );
        break;
        default:
        case MANUAL_CHECK:
            evt.SetEventType( wxEVT_VERSION_CHECK_DONE );
        break;
    }

    if ( taskType == DOWNLOAD_BINARY ) {
        wxString filename = wxT("");
        if ( download( parent->getNewVersionURL(), filename ) == true ) {
            evt.SetInt( 1 );
            evt.SetString( filename );
        } else {
            evt.SetInt( 0 );
        }
    } else {
        wxString latestVersion = wxT("");
        if ( execute( latestVersion ) == true ) {
            evt.SetInt( 1 );
            evt.SetString( latestVersion );
        } else {
            evt.SetInt( 0 );
        }
    }

    parent->postEvent( evt );
    return 0;
}
