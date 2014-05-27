/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, telnet and SSH connections

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

#include <map>

//(*Headers(settingsDialog)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class settingsDialog: public wxDialog
{
	public:

		settingsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~settingsDialog();

		//(*Declarations(settingsDialog)
		wxButton* CancelButton;
		wxTextCtrl* ShortcutManualCCText;
		wxButton* TelnetArgumentHelpButton;
		wxButton* SSHExecutableBrowseButton;
		wxButton* VNCArgumentHelpButton;
		wxPanel* Panel1;
		wxPanel* Panel6;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxFileDialog* SSHExecDialog;
		wxStaticText* ShortcutCloseTabLabel;
		wxStaticText* ShortcutManualCCLabel;
		wxTextCtrl* TextShortcutCommandDialog;
		wxTextCtrl* TextShortcutNewCon;
		wxStaticText* CCWorkerThreadLabel;
		wxButton* VNCArgumentResetButton;
		wxSlider* CCWorkerThreadSlider;
		wxStaticText* ShortcutNewTabLabel;
		wxButton* VNCExecutableBrowseButton;
		wxButton* SSHArgumentResetButton;
		wxTextCtrl* ShortcutCloseTabText;
		wxTextCtrl* TelnetArgumentText;
		wxStaticText* StaticText1;
		wxStaticText* StaticText10;
		wxStaticText* StaticText16;
		wxTextCtrl* TextShortcutDupCon;
		wxPanel* Panel2;
		wxStaticText* StaticText3;
		wxPanel* Panel4;
		wxTextCtrl* SSHArgumentText;
		wxFileDialog* TelnetExecDialog;
		wxTextCtrl* ShortcutNewTabText;
		wxPanel* Panel5;
		wxTextCtrl* TextShortcutConProp;
		wxStaticText* StaticText8;
		wxStaticText* StaticText12;
		wxStaticText* CCTimeoutLabel;
		wxPanel* Panel3;
		wxStaticText* StaticText7;
		wxCheckBox* CCAutoUpdateCheckbox;
		wxTextCtrl* SSHExecutableText;
		wxButton* TelnetExecutableBrowseButton;
		wxSlider* CCUpdateIntervalSlider;
		wxSlider* CCTimeoutSlider;
		wxButton* SSHArgumentHelpButton;
		wxStaticText* StaticText4;
		wxTextCtrl* CWRUpdateIntervalTextDisplay;
		wxSlider* CWRUpdateIntervalSlider;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxTextCtrl* ShortcutConnectWhenReadyText;
		wxTextCtrl* CCUpdateIntervalTextDisplay;
		wxNotebook* Notebook1;
		wxStaticText* StaticText6;
		wxTextCtrl* TextShortcutSelectAllCon;
		wxTextCtrl* TelnetExecutableText;
		wxTextCtrl* VNCExecutableText;
		wxTextCtrl* CCWorkerThreadTextDisplay;
		wxButton* OKButton;
		wxStaticText* CCUpdateIntervalLabel;
		wxFileDialog* VNCExecDialog;
		wxTextCtrl* VNCArgumentText;
		wxCheckBox* CheckboxGreyListBackground;
		wxStaticText* StaticText9;
		wxChoice* RDPDefaultResolutionChoice;
		wxButton* TelnetArgumentResetButton;
		wxTextCtrl* CCTimeoutTextDisplay;
		wxStaticText* StaticText11;
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
		static const long ID_PANEL2;
		static const long ID_STATICTEXT9;
		static const long ID_NEWCON;
		static const long ID_STATICTEXT7;
		static const long ID_DUPCON;
		static const long ID_STATICTEXT12;
		static const long ID_CONPROP;
		static const long ID_STATICTEXT18;
		static const long ID_SELCON;
		static const long ID_STATICTEXT11;
		static const long ID_COMMANDDIALOG;
		static const long ID_STATICTEXT13;
		static const long ID_MANUALCC;
		static const long ID_STATICTEXT19;
		static const long ID_CONNECTWHENREADY;
		static const long ID_STATICTEXT14;
		static const long ID_NEWTAB;
		static const long ID_STATICTEXT15;
		static const long ID_CLOSETAB;
		static const long ID_PANEL3;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL7;
		static const long ID_SLIDER1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL8;
		static const long ID_SLIDER2;
		static const long ID_STATICTEXT20;
		static const long ID_TEXTCTRL10;
		static const long ID_SLIDER4;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		static const long ID_TEXTCTRL9;
		static const long ID_SLIDER3;
		static const long ID_PANEL4;
		static const long ID_USE_GREY_LIST_BACKGROUND;
		static const long ID_PANEL5;
		static const long ID_STATICTEXT22;
		static const long ID_CHOICE1;
		static const long ID_PANEL6;
		static const long ID_NOTEBOOK1;
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
		void OnCCTimeoutSliderCmdSliderUpdated(wxScrollEvent& event);
		void OnCCUpdateIntervalSliderCmdSliderUpdated(wxScrollEvent& event);
		void OnCCAutoUpdateCheckboxClick(wxCommandEvent& event);
		void OnCCWorkerThreadSliderCmdSliderUpdated(wxScrollEvent& event);
		void OnCWRUpdateIntervalSliderCmdSliderUpdated(wxScrollEvent& event);
		//*)

		void HandleKeyShortcutPress( wxKeyEvent& event );
		void setShortcut( long controlId, std::pair< int, int > shortcut );

		void resetTelnetArgument();
		void resetSSHArgument();
		void resetVNCArgument();

		std::map< const long, std::pair< int, int > > shortcutMap;

		DECLARE_EVENT_TABLE()
};

#endif
