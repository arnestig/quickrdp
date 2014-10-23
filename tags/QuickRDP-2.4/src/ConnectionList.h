/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

//(*Headers(ConnectionList)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
//*)
#include <vector>
#include "quickRDPMain.h"

namespace ConnectionListColumn
{
    enum ConnectionListColumn
    {
        HOSTNAME        = 0x01,
        PORT            = 0x02,
        USERNAME        = 0x04,
        CONNECTIONTYPE  = 0x08,
        USE_CONSOLE     = 0x10,
        RESOLUTION      = 0x20,
        COMMENT         = 0x40,
        CLIENT_NAME     = 0x80,

    };
}

class ConnectionList: public wxPanel
{
	public:

		ConnectionList(wxWindow* parent, quickRDPFrame *mainFrame, wxWindowID id=wxID_ANY );
		virtual ~ConnectionList();

		//(*Declarations(ConnectionList)
		wxMenuItem* MenuItem8;
		wxMenuItem* MenuItem7;
		wxListCtrl* ListCtrl1;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem4;
		wxMenuItem* MenuItem3;
		wxMenuItem* MenuItem6;
		wxMenu ColumnListChooserMenu;
		//*)
		wxListCtrl* getConnectionList();
		void UpdateColumnWidth();
		void addColumns();

	protected:

		//(*Identifiers(ConnectionList)
		static const long ID_LISTCTRL1;
		static const long ID_COLUMN_HOSTNAME;
		static const long ID_COLUMN_PORT;
		static const long ID_COLUMN_USERNAME;
		static const long ID_COLUMN_CONNECTIONTYPE;
		static const long ID_COLUMN_USECONSOLE;
		static const long ID_COLUMN_RESOLUTION;
		static const long ID_COLUMN_COMMENT;
		static const long ID_COLUMN_CLIENTNAME;
		//*)


	private:

		//(*Handlers(ConnectionList)
		void OnColumnClick(wxListEvent& event);
		void OnItemRightClick(wxListEvent& event);
		void OnItemActivated(wxListEvent& event);
		void OnItemSelected(wxListEvent& event);
		void OnItemDeselected(wxListEvent& event);
		void OnColumnEndDrag(wxListEvent& event);
		void OnColumnRightClick(wxListEvent& event);
		void OnColumnListChooserMenuClick(wxCommandEvent& event);
		//*)
		quickRDPFrame *mainFrame;
		std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap;

		DECLARE_EVENT_TABLE()
};

#endif
