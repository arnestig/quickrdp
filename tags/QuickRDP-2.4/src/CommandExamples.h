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

#ifndef COMMANDEXAMPLES_H
#define COMMANDEXAMPLES_H

#include <map>
#include "CommandDatabase.h"

//(*Headers(CommandExamples)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommandExamples: public wxDialog
{
	public:

		CommandExamples(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CommandExamples();

		//(*Declarations(CommandExamples)
		wxListCtrl* ListCtrl1;
		wxButton* ButtonClose;
		wxPanel* Panel1;
		wxButton* ButtonAdd;
		//*)

	protected:

		//(*Identifiers(CommandExamples)
		static const long ID_LISTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(CommandExamples)
		void AddCommand(wxCommandEvent& event);
		void OnClose(wxCommandEvent& event);
		void OnListCtrl1ItemSelectDeselect(wxListEvent& event);
		void OnListCtrl1ItemActivated(wxListEvent& event);
		//*)
		void loadExampleCommandsWindows();
		void loadExampleCommandsLinux();
		void displayCommands();
		Command* getCommandFromList();

		std::map< wxString, Command* > commands;

		DECLARE_EVENT_TABLE()
};

#endif
