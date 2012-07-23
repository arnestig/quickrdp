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

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

//(*Headers(settingsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class settingsDialog: public wxDialog
{
	public:

		settingsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~settingsDialog();

		//(*Declarations(settingsDialog)
		wxButton* TelnetArgumentHelpButton;
		wxFileDialog* TelnetExecDialog;
		wxButton* OKButton;
		wxButton* VNCArgumentResetButton;
		wxFileDialog* VNCExecDialog;
		wxStaticText* StaticText2;
		wxButton* VNCArgumentHelpButton;
		wxButton* VNCExecutableBrowseButton;
		wxStaticText* StaticText6;
		wxTextCtrl* VNCExecutableText;
		wxTextCtrl* SSHArgumentText;
		wxButton* SSHExecutableBrowseButton;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxTextCtrl* VNCArgumentText;
		wxStaticText* StaticText3;
		wxTextCtrl* TelnetExecutableText;
		wxTextCtrl* TelnetArgumentText;
		wxButton* SSHArgumentHelpButton;
		wxButton* TelnetExecutableBrowseButton;
		wxStaticText* StaticText5;
		wxFileDialog* SSHExecDialog;
		wxButton* TelnetArgumentResetButton;
		wxButton* SSHArgumentResetButton;
		wxStaticText* StaticText4;
		wxButton* CancelButton;
		wxTextCtrl* SSHExecutableText;
		//*)

	protected:

		//(*Identifiers(settingsDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON9;
		static const long ID_BUTTON6;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON4;
		static const long ID_BUTTON7;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL6;
		static const long ID_BUTTON10;
		static const long ID_BUTTON8;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(settingsDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnButtonSave(wxCommandEvent& event);
		void OnButtonCancel(wxCommandEvent& event);
		void OnTelnetArgumentReset(wxCommandEvent& event);
		void OnTelnetBrowseClick(wxCommandEvent& event);
		void OnSSHBrowseClick(wxCommandEvent& event);
		void OnSSHArgumentReset(wxCommandEvent& event);
		void OnHelpArgumentClick(wxCommandEvent& event);
		void OnVNCArgumentResetButtonClick(wxCommandEvent& event);
		void OnVNCBrowseClick(wxCommandEvent& event);
		//*)

		void resetTelnetArgument();
		void resetSSHArgument();
		void resetVNCArgument();

		DECLARE_EVENT_TABLE()
};

#endif
