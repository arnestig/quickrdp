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

#ifndef RDPFRAME_H
#define RDPFRAME_H

#include "generalTabPanel.h"
#include "resourcesTabPanel.h"
#include "windowTabPanel.h"
#include "RDPDatabase.h"

//(*Headers(RDPFrame)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class generalTabPanel;
class windowTabPanel;
class resourcesTabPanel;

class RDPFrame: public wxDialog
{
	friend class generalTabPanel;
	friend class windowTabPanel;
	friend class resourcesTabPanel;

	public:

		RDPFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~RDPFrame();

		//(*Declarations(RDPFrame)
		wxNotebook* Notebook1;
		wxButton* Button1;
		wxPanel* Panel1;
		wxButton* Button2;
		//*)
		generalTabPanel* generalTab;
		windowTabPanel* windowTab;
        resourcesTabPanel* resourcesTab;
        void loadRDPConnection( RDPConnection* rdpConnection );

	protected:

		//(*Identifiers(RDPFrame)
		static const long ID_NOTEBOOK1;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(RDPFrame)
		void onCloseClick(wxCommandEvent& event);
		void onSaveClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		RDPConnection *rdpConnection;
		void checkForChanges();
		void switchConnectionType( ConnectionType::ConnectionType connectionType );

		DECLARE_EVENT_TABLE()
};

#endif
