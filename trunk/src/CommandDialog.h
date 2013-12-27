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

#ifndef COMMANDDIALOG_H
#define COMMANDDIALOG_H

#include "CommandDatabase.h"

//(*Headers(CommandDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommandDialog: public wxDialog
{
	public:

		CommandDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~CommandDialog();

		//(*Declarations(CommandDialog)
		wxStaticText* StaticText10;
		wxButton* ArgumentHelpButton;
		wxStaticText* StaticText9;
		wxBoxSizer* BoxSizer6;
		wxTextCtrl* argumentTextCtrl;
		wxChoice* connectionTypeChoice;
		wxButton* closeButton;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxCheckBox* safetyCheckbox;
		wxTextCtrl* TextShortcut;
		wxStaticText* StaticText8;
		wxButton* saveButton;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxFileDialog* FileDialog1;
		wxCheckBox* favoriteCheckbox;
		wxStaticText* StaticText3;
		wxTextCtrl* nameTextCtrl;
		wxCheckBox* connectionTargetCheckbox;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* programTextCtrl;
		wxBoxSizer* BoxSizer1;
		wxStaticText* StaticText4;
		//*)

		void LoadCommand( Command* command );

	protected:

		//(*Identifiers(CommandDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT10;
		static const long ID_CHECKBOX3;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT9;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(CommandDialog)
		void OnCloseButton(wxCommandEvent& event);
		void OnNameTextChange(wxCommandEvent& event);
		void OnSaveButton(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnExamplesButton(wxCommandEvent& event);
		void OnArgumentHelpButton(wxCommandEvent& event);
		void OnFileDialogClick(wxCommandEvent& event);
		void HandlePanelKeyDown(wxKeyEvent& event);
		void OnBindKeyClick(wxCommandEvent& event);
		void OnconnectionTargetCheckboxClick(wxCommandEvent& event);
		void OnconnectionTypeChoiceSelect(wxCommandEvent& event);
		//*)

		void SaveCurrentShortcut( std::pair< int, int > shortcut );

        int curShortcutMod;
        int curShortcutKey;
        std::map< int, wxString > program;
        std::map< int, wxString > argument;
        Command *command;
        int prevChoiceSelection;

		DECLARE_EVENT_TABLE()
};

#endif
