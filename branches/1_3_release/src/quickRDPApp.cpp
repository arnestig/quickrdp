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

#include "quickRDPApp.h"
#include "Resources.h"
#include "QuickrdpFunctions.h"
#include <wx/icon.h>

//(*AppHeaders
#include "quickRDPMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(quickRDPApp);

quickRDPApp::quickRDPApp()
    :   Frame( NULL )
{
}

bool quickRDPApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new quickRDPFrame(0);
        #if defined(__UNIX__)
            Frame->SetIcon( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("quickrdp.xpm") ) );
        #else
            Frame->SetIcon(wxICON(aaaa));
        #endif
    	Frame->Show();
    	SetTopWindow(Frame);

    	/** Check if new version is available... **/
    	Frame->checkForNewAvailableVersion();

        /** Initialize the connection checker **/
        Resources::Instance()->addConnectionChecker( Frame );

    	/** run our init method for stuff that couldn't be done during the constructor of main frame **/
    	Frame->init();
    }
    //*)
    return wxsOK;

}

int quickRDPApp::FilterEvent(wxEvent& event)
{
    if ( event.GetEventType() == wxEVT_KEY_DOWN ) {
        wxKeyEvent ownevt = (wxKeyEvent&) event;
        /** check if we want to process this event.. */
        if ( quickRDP::Keybinder::IsValidKeycode( ownevt.GetKeyCode() ) == true ) {
            if ( Frame->handleShortcutKeys( ownevt ) == false ) {
                return -1;
            } else {
                return 0;
            }
        }
    }

    return -1;
}
