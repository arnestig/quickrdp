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

#ifndef COMMANDDIALOG_H
#define COMMANDDIALOG_H

//(*Headers(CommandDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommandDialog: public wxDialog
{
	public:

		CommandDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~CommandDialog();

		//(*Declarations(CommandDialog)
		wxButton* ArgumentHelpButton;
		wxStaticText* StaticText9;
		wxTextCtrl* argumentTextCtrl;
		wxButton* closeButton;
		wxStaticText* StaticText2;
		wxButton* exampleButton;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxCheckBox* safetyCheckbox;
		wxButton* saveButton;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxFileDialog* FileDialog1;
		wxCheckBox* favoriteCheckbox;
		wxStaticText* StaticText3;
		wxTextCtrl* nameTextCtrl;
		wxStaticText* StaticText5;
		wxListBox* CommandList;
		wxStaticLine* StaticLine1;
		wxTextCtrl* programTextCtrl;
		wxButton* RemoveButton;
		wxStaticText* StaticText4;
		wxButton* editButton;
		//*)

		void reloadCommandList();

	protected:

		//(*Identifiers(CommandDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON7;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT9;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_CHECKBOX2;
		static const long ID_BUTTON2;
		static const long ID_STATICLINE1;
		static const long ID_LISTBOX1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON6;
		static const long ID_BUTTON5;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(CommandDialog)
		void OnCloseButton(wxCommandEvent& event);
		void OnListDoubleClick(wxCommandEvent& event);
		void OnCommandListClick(wxCommandEvent& event);
		void OnNameTextChange(wxCommandEvent& event);
		void OnSaveButton(wxCommandEvent& event);
		void OnRemoveButton(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnButtonEdit(wxCommandEvent& event);
		void OnExamplesButton(wxCommandEvent& event);
		void OnArgumentHelpButton(wxCommandEvent& event);
		void OnFileDialogClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
