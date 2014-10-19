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

#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include "CommandDatabase.h"

//(*Headers(CommandList)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommandList: public wxDialog
{
	public:

		CommandList(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CommandList();

		//(*Declarations(CommandList)
		wxListCtrl* ListCtrl1;
		wxButton* buttonEdit;
		wxButton* buttonNew;
		wxButton* Button1;
		wxPanel* Panel1;
		wxButton* buttonClose;
		wxButton* buttonDelete;
		//*)

	protected:

		//(*Identifiers(CommandList)
		static const long ID_LISTCTRL1;
		static const long ID_PANEL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON5;
		static const long ID_BUTTON4;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(CommandList)
		void OnbuttonCloseClick(wxCommandEvent& event);
		void OnbuttonNewClick(wxCommandEvent& event);
		void OnbuttonEditClick(wxCommandEvent& event);
		void OnbuttonDeleteClick(wxCommandEvent& event);
		void OnListCtrl1ItemActivated(wxListEvent& event);
		void OnListCtrl1ItemSelectDeselect(wxListEvent& event);
		void OnButtonExamples(wxCommandEvent& event);
		//*)
		void enableDisableButtons( wxListEvent& event );

		void reloadCommandList();
		wxString boolToText( bool value );
		int getSelectedCommand();

		DECLARE_EVENT_TABLE()
};

#endif
