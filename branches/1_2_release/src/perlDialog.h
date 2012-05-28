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

#ifndef PERLDIALOG_H
#define PERLDIALOG_H

//(*Headers(perlDialog)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class perlDialog: public wxDialog
{
	public:

		perlDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~perlDialog();

		//(*Declarations(perlDialog)
		wxButton* deleteButton;
		wxListCtrl* ListCtrl1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxButton* newButton;
		wxButton* editButton;
		wxTextCtrl* scriptNameText;
		wxButton* cancelButton;
		//*)

	protected:

		//(*Identifiers(perlDialog)
		static const long ID_LISTCTRL1;
		static const long ID_PANEL1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(perlDialog)
		void OnTextNameInput(wxCommandEvent& event);
		void OnScriptNameSelect(wxCommandEvent& event);
		void OnScriptListSelected(wxListEvent& event);
		void OnScriptListActivated(wxListEvent& event);
		void OnListScriptDeselected(wxListEvent& event);
		void OnButtonDelete(wxCommandEvent& event);
		void OnNewScriptButton(wxCommandEvent& event);
		void OnCancelClick(wxCommandEvent& event);
		//*)

		void reloadScriptList();

		DECLARE_EVENT_TABLE()
};

#endif
