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

#ifndef EXAMPLEDIALOG_H
#define EXAMPLEDIALOG_H

//(*Headers(ExampleDialog)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class ExampleDialog: public wxDialog
{
	public:

		ExampleDialog(wxString example, wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ExampleDialog();

		//(*Declarations(ExampleDialog)
		wxButton* Button1;
		wxPanel* Panel1;
		wxTextCtrl* exampleTextCtrl;
		//*)

	protected:

		//(*Identifiers(ExampleDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ExampleDialog)
		void OnCloseButton(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
