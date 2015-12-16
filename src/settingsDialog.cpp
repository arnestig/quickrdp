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

#include "settingsDialog.h"
#include "Resources.h"
#include "QuickrdpFunctions.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(settingsDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(settingsDialog)
const long settingsDialog::ID_STATICTEXT1 = wxNewId();
const long settingsDialog::ID_TEXTCTRL1 = wxNewId();
const long settingsDialog::ID_BUTTON1 = wxNewId();
const long settingsDialog::ID_STATICTEXT4 = wxNewId();
const long settingsDialog::ID_TEXTCTRL4 = wxNewId();
const long settingsDialog::ID_BUTTON9 = wxNewId();
const long settingsDialog::ID_BUTTON6 = wxNewId();
const long settingsDialog::ID_STATICTEXT3 = wxNewId();
const long settingsDialog::ID_TEXTCTRL2 = wxNewId();
const long settingsDialog::ID_BUTTON2 = wxNewId();
const long settingsDialog::ID_STATICTEXT5 = wxNewId();
const long settingsDialog::ID_TEXTCTRL5 = wxNewId();
const long settingsDialog::ID_BUTTON4 = wxNewId();
const long settingsDialog::ID_BUTTON7 = wxNewId();
const long settingsDialog::ID_STATICTEXT2 = wxNewId();
const long settingsDialog::ID_TEXTCTRL3 = wxNewId();
const long settingsDialog::ID_BUTTON5 = wxNewId();
const long settingsDialog::ID_STATICTEXT6 = wxNewId();
const long settingsDialog::ID_TEXTCTRL6 = wxNewId();
const long settingsDialog::ID_BUTTON10 = wxNewId();
const long settingsDialog::ID_BUTTON8 = wxNewId();
const long settingsDialog::ID_PANEL2 = wxNewId();
const long settingsDialog::ID_STATICTEXT9 = wxNewId();
const long settingsDialog::ID_NEWCON = wxNewId();
const long settingsDialog::ID_STATICTEXT7 = wxNewId();
const long settingsDialog::ID_DUPCON = wxNewId();
const long settingsDialog::ID_STATICTEXT12 = wxNewId();
const long settingsDialog::ID_CONPROP = wxNewId();
const long settingsDialog::ID_STATICTEXT18 = wxNewId();
const long settingsDialog::ID_SELCON = wxNewId();
const long settingsDialog::ID_STATICTEXT11 = wxNewId();
const long settingsDialog::ID_COMMANDDIALOG = wxNewId();
const long settingsDialog::ID_STATICTEXT13 = wxNewId();
const long settingsDialog::ID_MANUALCC = wxNewId();
const long settingsDialog::ID_STATICTEXT19 = wxNewId();
const long settingsDialog::ID_CONNECTWHENREADY = wxNewId();
const long settingsDialog::ID_STATICTEXT14 = wxNewId();
const long settingsDialog::ID_NEWTAB = wxNewId();
const long settingsDialog::ID_STATICTEXT15 = wxNewId();
const long settingsDialog::ID_CLOSETAB = wxNewId();
const long settingsDialog::ID_PANEL3 = wxNewId();
const long settingsDialog::ID_STATICTEXT8 = wxNewId();
const long settingsDialog::ID_TEXTCTRL7 = wxNewId();
const long settingsDialog::ID_SLIDER1 = wxNewId();
const long settingsDialog::ID_CHECKBOX1 = wxNewId();
const long settingsDialog::ID_STATICTEXT10 = wxNewId();
const long settingsDialog::ID_TEXTCTRL8 = wxNewId();
const long settingsDialog::ID_SLIDER2 = wxNewId();
const long settingsDialog::ID_STATICTEXT20 = wxNewId();
const long settingsDialog::ID_TEXTCTRL10 = wxNewId();
const long settingsDialog::ID_SLIDER4 = wxNewId();
const long settingsDialog::ID_STATICTEXT16 = wxNewId();
const long settingsDialog::ID_STATICTEXT17 = wxNewId();
const long settingsDialog::ID_TEXTCTRL9 = wxNewId();
const long settingsDialog::ID_SLIDER3 = wxNewId();
const long settingsDialog::ID_PANEL4 = wxNewId();
const long settingsDialog::ID_USE_GREY_LIST_BACKGROUND = wxNewId();
const long settingsDialog::ID_PANEL5 = wxNewId();
const long settingsDialog::ID_STATICTEXT22 = wxNewId();
const long settingsDialog::ID_CHOICE1 = wxNewId();
const long settingsDialog::ID_PANEL6 = wxNewId();
const long settingsDialog::ID_NOTEBOOK1 = wxNewId();
const long settingsDialog::ID_BUTTON3 = wxNewId();
const long settingsDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(settingsDialog,wxDialog)
	//(*EventTable(settingsDialog)
	//*)
END_EVENT_TABLE()

settingsDialog::settingsDialog(wxWindow* parent,wxWindowID WXUNUSED( id ),const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(settingsDialog)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer29;
	wxBoxSizer* BoxSizer19;
	wxBoxSizer* BoxSizer15;
	wxBoxSizer* BoxSizer20;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer21;
	wxBoxSizer* BoxSizer13;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer23;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer16;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxBoxSizer* BoxSizer18;
	wxBoxSizer* BoxSizer30;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer28;
	wxBoxSizer* BoxSizer14;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxBoxSizer* BoxSizer27;
	wxBoxSizer* BoxSizer31;
	wxBoxSizer* BoxSizer17;
	wxBoxSizer* BoxSizer24;
	wxBoxSizer* BoxSizer26;
	wxBoxSizer* BoxSizer32;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer34;
	wxBoxSizer* BoxSizer22;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxBoxSizer* BoxSizer25;
	
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(392,465));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer13 = new wxBoxSizer(wxVERTICAL);
	Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxSize(424,432), 0, _T("ID_NOTEBOOK1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Telnet"));
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Executable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer7->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetExecutableText = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(217,21), wxTE_READONLY|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TelnetExecutableText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	BoxSizer7->Add(TelnetExecutableText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetExecutableBrowseButton = new wxButton(Panel2, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer7->Add(TelnetExecutableBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer7, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("  Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer8->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetArgumentText = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer8->Add(TelnetArgumentText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetArgumentHelpButton = new wxButton(Panel2, ID_BUTTON9, _("\?"), wxDefaultPosition, wxSize(23,23), 0, wxDefaultValidator, _T("ID_BUTTON9"));
	BoxSizer8->Add(TelnetArgumentHelpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetArgumentResetButton = new wxButton(Panel2, ID_BUTTON6, _("reset"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer8->Add(TelnetArgumentResetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer3->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("SSH"));
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Executable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer9->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHExecutableText = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(217,21), wxTE_READONLY|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	SSHExecutableText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	BoxSizer9->Add(SSHExecutableText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHExecutableBrowseButton = new wxButton(Panel2, ID_BUTTON2, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer9->Add(SSHExecutableBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer9, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("  Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer10->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHArgumentText = new wxTextCtrl(Panel2, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer10->Add(SSHArgumentText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHArgumentHelpButton = new wxButton(Panel2, ID_BUTTON4, _("\?"), wxDefaultPosition, wxSize(23,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer10->Add(SSHArgumentHelpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHArgumentResetButton = new wxButton(Panel2, ID_BUTTON7, _("reset"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON7"));
	BoxSizer10->Add(SSHArgumentResetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer10, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer4->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("VNC"));
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Executable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer11->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCExecutableText = new wxTextCtrl(Panel2, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(217,21), wxTE_READONLY|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	VNCExecutableText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	BoxSizer11->Add(VNCExecutableText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCExecutableBrowseButton = new wxButton(Panel2, ID_BUTTON5, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer11->Add(VNCExecutableBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer11, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("  Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer12->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCArgumentText = new wxTextCtrl(Panel2, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer12->Add(VNCArgumentText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCArgumentHelpButton = new wxButton(Panel2, ID_BUTTON10, _("\?"), wxDefaultPosition, wxSize(23,23), 0, wxDefaultValidator, _T("ID_BUTTON10"));
	BoxSizer12->Add(VNCArgumentHelpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCArgumentResetButton = new wxButton(Panel2, ID_BUTTON8, _("reset"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer12->Add(VNCArgumentResetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer12, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer6->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel2);
	BoxSizer2->SetSizeHints(Panel2);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxSize(360,373), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizer14 = new wxBoxSizer(wxVERTICAL);
	BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
	StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("New connection"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer17->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcutNewCon = new wxTextCtrl(Panel3, ID_NEWCON, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_NEWCON"));
	BoxSizer17->Add(TextShortcutNewCon, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer17, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("Duplicate connection"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer15->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcutDupCon = new wxTextCtrl(Panel3, ID_DUPCON, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_DUPCON"));
	BoxSizer15->Add(TextShortcutDupCon, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer15, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
	StaticText12 = new wxStaticText(Panel3, ID_STATICTEXT12, _("Connection properties"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer20->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcutConProp = new wxTextCtrl(Panel3, ID_CONPROP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CONPROP"));
	BoxSizer20->Add(TextShortcutConProp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer20, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
	StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT18, _("Select all connections"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	BoxSizer27->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcutSelectAllCon = new wxTextCtrl(Panel3, ID_SELCON, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SELCON"));
	BoxSizer27->Add(TextShortcutSelectAllCon, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer27, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(Panel3, ID_STATICTEXT11, _("Commands dialog"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer19->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcutCommandDialog = new wxTextCtrl(Panel3, ID_COMMANDDIALOG, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COMMANDDIALOG"));
	BoxSizer19->Add(TextShortcutCommandDialog, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer19, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
	ShortcutManualCCLabel = new wxStaticText(Panel3, ID_STATICTEXT13, _("Manual connection check"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizer23->Add(ShortcutManualCCLabel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ShortcutManualCCText = new wxTextCtrl(Panel3, ID_MANUALCC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_MANUALCC"));
	BoxSizer23->Add(ShortcutManualCCText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer23, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer30 = new wxBoxSizer(wxHORIZONTAL);
	StaticText13 = new wxStaticText(Panel3, ID_STATICTEXT19, _("Connect when ready"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	BoxSizer30->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ShortcutConnectWhenReadyText = new wxTextCtrl(Panel3, ID_CONNECTWHENREADY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CONNECTWHENREADY"));
	BoxSizer30->Add(ShortcutConnectWhenReadyText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer30, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
	ShortcutNewTabLabel = new wxStaticText(Panel3, ID_STATICTEXT14, _("Open new tab"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	BoxSizer24->Add(ShortcutNewTabLabel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ShortcutNewTabText = new wxTextCtrl(Panel3, ID_NEWTAB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_NEWTAB"));
	BoxSizer24->Add(ShortcutNewTabText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer24, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer25 = new wxBoxSizer(wxHORIZONTAL);
	ShortcutCloseTabLabel = new wxStaticText(Panel3, ID_STATICTEXT15, _("Close current tab"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	BoxSizer25->Add(ShortcutCloseTabLabel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ShortcutCloseTabText = new wxTextCtrl(Panel3, ID_CLOSETAB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CLOSETAB"));
	BoxSizer25->Add(ShortcutCloseTabText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14->Add(BoxSizer25, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(BoxSizer14);
	BoxSizer14->SetSizeHints(Panel3);
	Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	BoxSizer16 = new wxBoxSizer(wxVERTICAL);
	BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
	CCTimeoutLabel = new wxStaticText(Panel4, ID_STATICTEXT8, _("Connect scan timeout"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer18->Add(CCTimeoutLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer18->Add(24,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCTimeoutTextDisplay = new wxTextCtrl(Panel4, ID_TEXTCTRL7, _("0000 ms"), wxDefaultPosition, wxSize(66,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer18->Add(CCTimeoutTextDisplay, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCTimeoutSlider = new wxSlider(Panel4, ID_SLIDER1, 0, 2, 200, wxDefaultPosition, wxSize(100,24), 0, wxDefaultValidator, _T("ID_SLIDER1"));
	CCTimeoutSlider->SetPageSize(10);
	CCTimeoutSlider->SetLineSize(10);
	CCTimeoutSlider->SetThumbLength(10);
	BoxSizer18->Add(CCTimeoutSlider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16->Add(BoxSizer18, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
	CCAutoUpdateCheckbox = new wxCheckBox(Panel4, ID_CHECKBOX1, _("Enable automatic connection checks"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CCAutoUpdateCheckbox->SetValue(true);
	BoxSizer22->Add(CCAutoUpdateCheckbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16->Add(BoxSizer22, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
	CCUpdateIntervalLabel = new wxStaticText(Panel4, ID_STATICTEXT10, _("Check connections every"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer21->Add(CCUpdateIntervalLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21->Add(22,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCUpdateIntervalTextDisplay = new wxTextCtrl(Panel4, ID_TEXTCTRL8, _("180 s"), wxDefaultPosition, wxSize(44,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	BoxSizer21->Add(CCUpdateIntervalTextDisplay, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCUpdateIntervalSlider = new wxSlider(Panel4, ID_SLIDER2, 0, 1, 36, wxDefaultPosition, wxSize(100,24), 0, wxDefaultValidator, _T("ID_SLIDER2"));
	CCUpdateIntervalSlider->SetPageSize(10);
	BoxSizer21->Add(CCUpdateIntervalSlider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16->Add(BoxSizer21, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer32 = new wxBoxSizer(wxHORIZONTAL);
	StaticText14 = new wxStaticText(Panel4, ID_STATICTEXT20, _("\'Connect when ready\'\ninterval check"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	BoxSizer32->Add(StaticText14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer32->Add(44,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CWRUpdateIntervalTextDisplay = new wxTextCtrl(Panel4, ID_TEXTCTRL10, _("5 s"), wxDefaultPosition, wxSize(35,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	BoxSizer32->Add(CWRUpdateIntervalTextDisplay, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CWRUpdateIntervalSlider = new wxSlider(Panel4, ID_SLIDER4, 5, 5, 60, wxDefaultPosition, wxSize(100,24), 0, wxDefaultValidator, _T("ID_SLIDER4"));
	CWRUpdateIntervalSlider->SetPageSize(10);
	BoxSizer32->Add(CWRUpdateIntervalSlider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16->Add(BoxSizer32, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
	CCWorkerThreadLabel = new wxStaticText(Panel4, ID_STATICTEXT16, _("Number of worker threads"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	BoxSizer26->Add(CCWorkerThreadLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel4, ID_STATICTEXT17, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT17"));
	StaticText8->SetForegroundColour(wxColour(255,0,0));
	StaticText8->SetToolTip(_("Experimental setting. \nWill alter the number of threads used for connection checks. \nYou will need to restart the program for this setting to be effective."));
	BoxSizer26->Add(StaticText8, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer26->Add(13,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCWorkerThreadTextDisplay = new wxTextCtrl(Panel4, ID_TEXTCTRL9, _("0"), wxDefaultPosition, wxSize(25,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	BoxSizer26->Add(CCWorkerThreadTextDisplay, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCWorkerThreadSlider = new wxSlider(Panel4, ID_SLIDER3, 0, 1, 8, wxDefaultPosition, wxSize(100,24), 0, wxDefaultValidator, _T("ID_SLIDER3"));
	BoxSizer26->Add(CCWorkerThreadSlider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16->Add(BoxSizer26, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel4->SetSizer(BoxSizer16);
	BoxSizer16->Fit(Panel4);
	BoxSizer16->SetSizeHints(Panel4);
	Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxSize(478,368), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	BoxSizer28 = new wxBoxSizer(wxVERTICAL);
	BoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
	CheckboxGreyListBackground = new wxCheckBox(Panel5, ID_USE_GREY_LIST_BACKGROUND, _("Use grey background in connection list"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_USE_GREY_LIST_BACKGROUND"));
	CheckboxGreyListBackground->SetValue(false);
	BoxSizer29->Add(CheckboxGreyListBackground, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer28->Add(BoxSizer29, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel5->SetSizer(BoxSizer28);
	BoxSizer28->SetSizeHints(Panel5);
	Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	BoxSizer31 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("RDP"));
	BoxSizer34 = new wxBoxSizer(wxHORIZONTAL);
	StaticText16 = new wxStaticText(Panel6, ID_STATICTEXT22, _("Default resolution"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	BoxSizer34->Add(StaticText16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RDPDefaultResolutionChoice = new wxChoice(Panel6, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	RDPDefaultResolutionChoice->SetSelection( RDPDefaultResolutionChoice->Append(_("Default resolution")) );
	RDPDefaultResolutionChoice->Append(_("Fullscreen"));
	RDPDefaultResolutionChoice->Append(_("640 x 480"));
	RDPDefaultResolutionChoice->Append(_("800 x 600"));
	RDPDefaultResolutionChoice->Append(_("1024 x 768"));
	RDPDefaultResolutionChoice->Append(_("1152 x 864"));
	RDPDefaultResolutionChoice->Append(_("1280 x 960"));
	RDPDefaultResolutionChoice->Append(_("1400 x 1050"));
	BoxSizer34->Add(RDPDefaultResolutionChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer34, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer31->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("SSH"));
	BoxSizer31->Add(StaticBoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Telnet"));
	BoxSizer31->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("VNC"));
	BoxSizer31->Add(StaticBoxSizer7, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel6->SetSizer(BoxSizer31);
	BoxSizer31->Fit(Panel6);
	BoxSizer31->SetSizeHints(Panel6);
	Notebook1->AddPage(Panel2, _("Programs"), false);
	Notebook1->AddPage(Panel3, _("Hotkeys"), false);
	Notebook1->AddPage(Panel4, _("Connection checker"), false);
	Notebook1->AddPage(Panel5, _("Layout"), false);
	Notebook1->AddPage(Panel6, _("Defaults"), false);
	BoxSizer13->Add(Notebook1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	OKButton = new wxButton(Panel1, ID_BUTTON3, _("Ok"), wxDefaultPosition, wxSize(75,28), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer5->Add(OKButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CancelButton = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(75,28), 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer5->Add(CancelButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer13->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer13);
	BoxSizer13->Fit(Panel1);
	BoxSizer13->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	TelnetExecDialog = new wxFileDialog(this, _("Locate telnet executable"), wxEmptyString, wxEmptyString, _("PuTTY (putty.exe)|putty.exe|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	SSHExecDialog = new wxFileDialog(this, _("Locate SSH executable"), wxEmptyString, wxEmptyString, _("PuTTY (putty.exe)|putty.exe|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	VNCExecDialog = new wxFileDialog(this, _("Locate VNC executable"), wxEmptyString, wxEmptyString, _("PuTTY (putty.exe)|putty.exe|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->SetSizeHints(this);
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnTelnetBrowseClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnHelpArgumentClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnTelnetArgumentReset);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnSSHBrowseClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnHelpArgumentClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnSSHArgumentReset);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnVNCBrowseClick);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnHelpArgumentClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnVNCArgumentResetButtonClick);
	Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&settingsDialog::OnCCTimeoutSliderCmdSliderUpdated);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&settingsDialog::OnCCAutoUpdateCheckboxClick);
	Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&settingsDialog::OnCCUpdateIntervalSliderCmdSliderUpdated);
	Connect(ID_SLIDER4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&settingsDialog::OnCWRUpdateIntervalSliderCmdSliderUpdated);
	Connect(ID_SLIDER3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&settingsDialog::OnCCWorkerThreadSliderCmdSliderUpdated);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnButtonSave);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnButtonCancel);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&settingsDialog::OnInit);
	//*)

	TextShortcutNewCon->Connect(ID_NEWCON, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    TextShortcutDupCon->Connect(ID_DUPCON, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    TextShortcutConProp->Connect(ID_CONPROP, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    TextShortcutSelectAllCon->Connect(ID_SELCON, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    TextShortcutCommandDialog->Connect(ID_COMMANDDIALOG, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    ShortcutManualCCText->Connect(ID_MANUALCC, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    ShortcutConnectWhenReadyText->Connect(ID_CONNECTWHENREADY, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    ShortcutNewTabText->Connect(ID_NEWTAB, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );
    ShortcutCloseTabText->Connect(ID_CLOSETAB, wxEVT_KEY_DOWN,(wxObjectEventFunction)&settingsDialog::HandleKeyShortcutPress, 0, this );

	Settings* settings = Resources::Instance()->getSettings();

	TelnetExecutableText->SetValue( settings->getTelnetExec() );
	SSHExecutableText->SetValue( settings->getSSHExec() );
	VNCExecutableText->SetValue( settings->getVNCExec() );

    TextShortcutNewCon->AppendText( quickRDP::Shortcuts::ModifierString( settings->getNewConnectionShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getNewConnectionShortcut().first ) );
    TextShortcutDupCon->AppendText( quickRDP::Shortcuts::ModifierString( settings->getDupConnectionShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getDupConnectionShortcut().first ) );
    TextShortcutConProp->AppendText( quickRDP::Shortcuts::ModifierString( settings->getPropConnectionShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getPropConnectionShortcut().first ) );
    TextShortcutSelectAllCon->AppendText( quickRDP::Shortcuts::ModifierString( settings->getSelectAllConnectionsShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getSelectAllConnectionsShortcut().first ) );
    TextShortcutCommandDialog->AppendText( quickRDP::Shortcuts::ModifierString( settings->getCommandDialogShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getCommandDialogShortcut().first ) );
    ShortcutManualCCText->AppendText( quickRDP::Shortcuts::ModifierString( settings->getManualCCShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getManualCCShortcut().first ) );
    ShortcutConnectWhenReadyText->AppendText( quickRDP::Shortcuts::ModifierString( settings->getConnectWhenReadyShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getConnectWhenReadyShortcut().first ) );
    ShortcutNewTabText->AppendText( quickRDP::Shortcuts::ModifierString( settings->getNewTabShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getNewTabShortcut().first ) );
    ShortcutCloseTabText->AppendText( quickRDP::Shortcuts::ModifierString( settings->getCloseTabShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getCloseTabShortcut().first ) );

	/** set the telnet and ssh file dialog default values depending on windows or linux **/
    #if defined(__WXMSW__)
        TelnetExecDialog->SetWildcard( wxT("PuTTY (putty.exe)|putty.exe|All files (*.*)|*.*")); /** telnet **/
        SSHExecDialog->SetWildcard( wxT("PuTTY (putty.exe)|putty.exe|All files (*.*)|*.*")); /** ssh **/
        VNCExecDialog->SetWildcard( wxT("RealVNC / UltraVNC (vncviewer.exe)|vncviewer.exe|All files (*.*)|*.*")); /** VNC **/
    #elif defined(__UNIX__)
        /** telnet **/
        TelnetExecDialog->SetWildcard( wxT("Default terminal (x-terminal-emulator)|x-terminal-emulator|Gnome terminal (gnome-terminal)|gnome-terminal|KDE terminal (konsole)|konsole|All files (*)|*"));
        TelnetExecDialog->SetDirectory( wxT("/usr/bin" ) );

        /** ssh **/
        SSHExecDialog->SetWildcard( wxT("Default terminal (x-terminal-emulator)|x-terminal-emulator|Gnome terminal (gnome-terminal)|gnome-terminal|KDE terminal (konsole)|konsole|All files (*)|*"));
        SSHExecDialog->SetDirectory( wxT("/usr/bin" ) );

        /** VNC **/
        VNCExecDialog->SetWildcard( wxT("Default terminal (x-terminal-emulator)|x-terminal-emulator|Gnome terminal (gnome-terminal)|gnome-terminal|KDE terminal (konsole)|konsole|All files (*)|*"));
        VNCExecDialog->SetDirectory( wxT("/usr/bin" ) );
    #endif

    settings->getTelnetArgument().empty() == true ? resetTelnetArgument() : TelnetArgumentText->SetValue( settings->getTelnetArgument() );
    settings->getSSHArgument().empty() == true ? resetSSHArgument() : SSHArgumentText->SetValue( settings->getSSHArgument() );
    settings->getVNCArgument().empty() == true ? resetVNCArgument() : VNCArgumentText->SetValue( settings->getVNCArgument() );
    shortcutMap[ ID_NEWCON ] = settings->getNewConnectionShortcut();
    shortcutMap[ ID_DUPCON ] = settings->getDupConnectionShortcut();
    shortcutMap[ ID_CONPROP ] = settings->getPropConnectionShortcut();
    shortcutMap[ ID_SELCON ] = settings->getSelectAllConnectionsShortcut();
    shortcutMap[ ID_COMMANDDIALOG ] = settings->getCommandDialogShortcut();
    shortcutMap[ ID_MANUALCC ] = settings->getManualCCShortcut();
    shortcutMap[ ID_CONNECTWHENREADY ] = settings->getConnectWhenReadyShortcut();
    shortcutMap[ ID_NEWTAB ] = settings->getNewTabShortcut();
    shortcutMap[ ID_CLOSETAB ] = settings->getCloseTabShortcut();

    CCTimeoutSlider->SetValue( settings->getCCTimeout()/10 );
    CCUpdateIntervalSlider->SetValue( settings->getCCUpdateInterval()/10 );
    CWRUpdateIntervalSlider->SetValue( settings->getCWRUpdateInterval() );
    CCAutoUpdateCheckbox->SetValue( settings->getCCAutomaticCheck() );
    CCWorkerThreadSlider->SetValue( settings->getCCWorkerThreads() );

    wxScrollEvent evt;
    OnCCTimeoutSliderCmdSliderUpdated( evt );
    OnCCUpdateIntervalSliderCmdSliderUpdated( evt );
    OnCWRUpdateIntervalSliderCmdSliderUpdated( evt );
    OnCCAutoUpdateCheckboxClick( evt );
    OnCCWorkerThreadSliderCmdSliderUpdated( evt );

    CheckboxGreyListBackground->SetValue( settings->getGreyListBackground() );

    RDPDefaultResolutionChoice->SetSelection( settings->getRDPDefaultResolution() );
}

settingsDialog::~settingsDialog()
{
	//(*Destroy(settingsDialog)
	//*)
}

void settingsDialog::OnInit(wxInitDialogEvent& WXUNUSED(event) )
{
}

void settingsDialog::OnButtonSave(wxCommandEvent& WXUNUSED(event) )
{
    Settings *settings = Resources::Instance()->getSettings();
    settings->setTelnetExec( TelnetExecutableText->GetValue() );
    settings->setTelnetArgument( TelnetArgumentText->GetValue() );
    settings->setSSHExec( SSHExecutableText->GetValue() );
    settings->setSSHArgument( SSHArgumentText->GetValue() );
    settings->setVNCExec( VNCExecutableText->GetValue() );
    settings->setVNCArgument( VNCArgumentText->GetValue() );

    /** Save our shortcut keys **/
    settings->setNewConnectionShortcut( shortcutMap[ settingsDialog::ID_NEWCON ] );
    settings->setDupConnectionShortcut( shortcutMap[ settingsDialog::ID_DUPCON ] );
    settings->setPropConnectionShortcut( shortcutMap[ settingsDialog::ID_CONPROP ] );
    settings->setSelectAllConnectionsShortcut( shortcutMap[ settingsDialog::ID_SELCON ] );
    settings->setCommandDialogShortcut( shortcutMap[ settingsDialog::ID_COMMANDDIALOG ] );
    settings->setManualCCShortcut( shortcutMap[ settingsDialog::ID_MANUALCC ] );
    settings->setConnectWhenReadyShortcut( shortcutMap[ settingsDialog::ID_CONNECTWHENREADY ] );
    settings->setCloseTabShortcut( shortcutMap[ settingsDialog::ID_CLOSETAB ] );
    settings->setNewTabShortcut( shortcutMap[ settingsDialog::ID_NEWTAB ] );

    /** our connection checker settings **/
    settings->setCCTimeout( CCTimeoutSlider->GetValue()*10 );
    settings->setCCUpdateInterval( CCUpdateIntervalSlider->GetValue()*10 );
    settings->setCWRUpdateInterval( CWRUpdateIntervalSlider->GetValue() );
    settings->setCCAutomaticCheck( CCAutoUpdateCheckbox->GetValue() );
    settings->setCCWorkerThreads( CCWorkerThreadSlider->GetValue() );

    /** layout settings **/
    settings->setGreyListBackground( CheckboxGreyListBackground->GetValue() );

    /** default settings **/
    settings->setRDPDefaultResolution( RDPDefaultResolutionChoice->GetSelection() );

    settings->saveSettings();
    this->EndModal( 0 );
}

void settingsDialog::OnButtonCancel(wxCommandEvent& WXUNUSED(event) )
{
    this->EndModal( 1 );
}

void settingsDialog::OnTelnetBrowseClick(wxCommandEvent& WXUNUSED(event) )
{
    if ( TelnetExecDialog->ShowModal() == wxID_OK ) {
        TelnetExecutableText->SetValue( TelnetExecDialog->GetPath() );
    }
}

void settingsDialog::OnSSHBrowseClick(wxCommandEvent& WXUNUSED(event) )
{
    if ( SSHExecDialog->ShowModal() == wxID_OK ) {
        SSHExecutableText->SetValue( SSHExecDialog->GetPath() );
    }
}

void settingsDialog::OnVNCBrowseClick(wxCommandEvent& WXUNUSED(event) )
{
    if ( VNCExecDialog->ShowModal() == wxID_OK ) {
        VNCExecutableText->SetValue( VNCExecDialog->GetPath() );
    }
}

void settingsDialog::OnTelnetArgumentReset(wxCommandEvent& WXUNUSED(event) )
{
    resetTelnetArgument();
}

void settingsDialog::OnSSHArgumentReset(wxCommandEvent& WXUNUSED(event) )
{
    resetSSHArgument();
}

void settingsDialog::OnVNCArgumentResetButtonClick(wxCommandEvent& WXUNUSED(event) )
{
    resetVNCArgument();
}

void settingsDialog::resetTelnetArgument()
{
    #if defined(__WXMSW__)
        TelnetArgumentText->SetValue( wxT("-telnet {%username%@}%hostname% -P %port%") );
    #elif defined(__UNIX__)
        TelnetArgumentText->SetValue( wxT("-e \"telnet {-l %username%} %hostname%\"") );
    #endif
}

void settingsDialog::resetSSHArgument()
{
    #if defined(__WXMSW__)
        SSHArgumentText->SetValue( wxT("-ssh {%username%@}%hostname% -P %port%{ -pw %password%}") );
    #elif defined(__UNIX__)
        SSHArgumentText->SetValue( wxT("-e \"ssh {%username%@}%hostname%\"") );
    #endif
}

void settingsDialog::resetVNCArgument()
{
    #if defined(__WXMSW__)
        VNCArgumentText->SetValue( wxT("%hostname%::%port% -password %password%") );
    #elif defined(__UNIX__)
        VNCArgumentText->SetValue( wxT("%hostname%::%port% -password %password%") );
    #endif
}

void settingsDialog::OnHelpArgumentClick(wxCommandEvent& WXUNUSED(event) )
{
    wxMessageBox( wxT("Commandline-arguments sent to the choosen application will be parsed before sent.\n\nExample: A connection with the hostname telnet.example.com and username foobar would expand the argument string \"-telnet %username%@%hostname%\" to \"-telnet foobar@telnet.example.com\".\n\nIf you want to avoid expanding part of the argument if a specific string is empty you can define this using {}.\nExample: A connection without a password would expand the following argument \"-ssh {%username%@}%hostname%{ -pw %password%}\" to this: \"-ssh foobar@ssh.example.com\".\n\nFollowing strings can be used:\n%hostname%\n%connectiontype%\n%username%\n%password%\n%port%"), wxT("Command-line arguments"), wxICON_INFORMATION );
}

void settingsDialog::setShortcut( long controlId, std::pair< int, int > shortcut )
{
    shortcutMap[ controlId ] = shortcut;
    wxTextCtrl *modCtrl = NULL;

    if ( controlId == settingsDialog::ID_NEWCON ) {
        modCtrl = TextShortcutNewCon;
    } else if ( controlId == settingsDialog::ID_DUPCON ) {
        modCtrl = TextShortcutDupCon;
    } else if ( controlId == settingsDialog::ID_CONPROP ) {
        modCtrl = TextShortcutConProp;
    } else if ( controlId == settingsDialog::ID_SELCON ) {
        modCtrl = TextShortcutSelectAllCon;
    } else if ( controlId == settingsDialog::ID_COMMANDDIALOG ) {
        modCtrl = TextShortcutCommandDialog;
    } else if ( controlId == settingsDialog::ID_MANUALCC ) {
        modCtrl = ShortcutManualCCText;
    } else if ( controlId == settingsDialog::ID_CONNECTWHENREADY ) {
        modCtrl = ShortcutConnectWhenReadyText;
    } else if ( controlId == settingsDialog::ID_NEWTAB ) {
        modCtrl = ShortcutNewTabText;
    } else if ( controlId == settingsDialog::ID_CLOSETAB ) {
        modCtrl = ShortcutCloseTabText;
    }

    if ( modCtrl != NULL ) {
        modCtrl->Clear();
        modCtrl->AppendText( quickRDP::Shortcuts::ModifierString( shortcut.second ) + quickRDP::Shortcuts::KeycodeString( shortcut.first ) );
    }
}

void settingsDialog::HandleKeyShortcutPress( wxKeyEvent& event )
{
    std::pair< int, int > shortcut = std::make_pair( event.GetKeyCode(), event.GetModifiers() );

    /** if we wanted to clear the shortcut handle that here **/
    if ( event.GetKeyCode() == WXK_DELETE || event.GetKeyCode() == WXK_BACK ) {
        shortcut.first = 0;
        setShortcut( event.GetId(), shortcut );
    }

    if ( quickRDP::Shortcuts::IsValidKeycode( event.GetKeyCode() ) == true ) {
        wxString shortcutNameInUse;
        if ( quickRDP::Shortcuts::IsCombinationInUse( shortcut, shortcutNameInUse ) == true ) {
            if ( wxMessageBox( wxT("Already in use by: ") + shortcutNameInUse + wxT(".\nDo you want to use this keycombination anyway?"), wxT("Duplicate keycombination found"), wxYES_NO ) == wxYES ) {
                setShortcut( event.GetId(), shortcut );
            }
        } else {
            setShortcut( event.GetId(), shortcut );
        }
    }
}

void settingsDialog::OnCCTimeoutSliderCmdSliderUpdated( wxScrollEvent& WXUNUSED(event) )
{
    CCTimeoutTextDisplay->SetValue( wxString() << CCTimeoutSlider->GetValue()*10 << wxT(" ms") );
}

void settingsDialog::OnCCUpdateIntervalSliderCmdSliderUpdated(wxScrollEvent& WXUNUSED(event) )
{
    CCUpdateIntervalTextDisplay->SetValue( wxString() << CCUpdateIntervalSlider->GetValue()*10 << wxT(" s") );
}

void settingsDialog::OnCCAutoUpdateCheckboxClick(wxCommandEvent& WXUNUSED(event) )
{
    if ( CCAutoUpdateCheckbox->GetValue() == true ) {
        CCUpdateIntervalLabel->Enable( true );
        CCUpdateIntervalSlider->Enable( true );
        CCUpdateIntervalTextDisplay->Enable( true );
    } else {
        CCUpdateIntervalLabel->Enable( false );
        CCUpdateIntervalSlider->Enable( false );
        CCUpdateIntervalTextDisplay->Enable( false );
    }
}

void settingsDialog::OnCCWorkerThreadSliderCmdSliderUpdated(wxScrollEvent& WXUNUSED(event))
{
    CCWorkerThreadTextDisplay->SetValue( wxString::Format( wxT("%i"), CCWorkerThreadSlider->GetValue() ) );
}

void settingsDialog::OnCWRUpdateIntervalSliderCmdSliderUpdated(wxScrollEvent& WXUNUSED(event))
{
    CWRUpdateIntervalTextDisplay->SetValue( wxString() << CWRUpdateIntervalSlider->GetValue() << wxT(" s") );
}
