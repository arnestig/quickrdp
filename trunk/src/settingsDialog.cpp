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

#include "settingsDialog.h"
#include "Resources.h"
#include "QuickrdpFunctions.h"

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
const long settingsDialog::ID_BUTTON3 = wxNewId();
const long settingsDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(settingsDialog,wxDialog)
	//(*EventTable(settingsDialog)
	//*)
END_EVENT_TABLE()

settingsDialog::settingsDialog(wxWindow* parent,wxWindowID id,const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(settingsDialog)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(373,153));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Telnet"));
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Executable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer7->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetExecutableText = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(217,21), wxTE_READONLY|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TelnetExecutableText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	BoxSizer7->Add(TelnetExecutableText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetExecutableBrowseButton = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer7->Add(TelnetExecutableBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer8->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetArgumentText = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer8->Add(TelnetArgumentText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetArgumentHelpButton = new wxButton(Panel1, ID_BUTTON9, _("\?"), wxDefaultPosition, wxSize(23,23), 0, wxDefaultValidator, _T("ID_BUTTON9"));
	BoxSizer8->Add(TelnetArgumentHelpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TelnetArgumentResetButton = new wxButton(Panel1, ID_BUTTON6, _("reset"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer8->Add(TelnetArgumentResetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer3->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("SSH"));
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Executable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer9->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHExecutableText = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(217,21), wxTE_READONLY|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	SSHExecutableText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	BoxSizer9->Add(SSHExecutableText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHExecutableBrowseButton = new wxButton(Panel1, ID_BUTTON2, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer9->Add(SSHExecutableBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer10->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHArgumentText = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer10->Add(SSHArgumentText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHArgumentHelpButton = new wxButton(Panel1, ID_BUTTON4, _("\?"), wxDefaultPosition, wxSize(23,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer10->Add(SSHArgumentHelpButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SSHArgumentResetButton = new wxButton(Panel1, ID_BUTTON7, _("reset"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON7"));
	BoxSizer10->Add(SSHArgumentResetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer4->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("VNC"));
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Executable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer11->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCExecutableText = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(217,21), wxTE_READONLY|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	VNCExecutableText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	BoxSizer11->Add(VNCExecutableText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCExecutableBrowseButton = new wxButton(Panel1, ID_BUTTON5, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer11->Add(VNCExecutableBrowseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer12->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCArgumentText = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer12->Add(VNCArgumentText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCArgumentHelpButton = new wxButton(Panel1, ID_BUTTON10, _("\?"), wxDefaultPosition, wxSize(23,23), 0, wxDefaultValidator, _T("ID_BUTTON10"));
	BoxSizer12->Add(VNCArgumentHelpButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VNCArgumentResetButton = new wxButton(Panel1, ID_BUTTON8, _("reset"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer12->Add(VNCArgumentResetButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer6->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	OKButton = new wxButton(Panel1, ID_BUTTON3, _("Ok"), wxDefaultPosition, wxSize(75,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer5->Add(OKButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CancelButton = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(75,23), 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer5->Add(CancelButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
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
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnSSHArgumentReset);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnButtonSave);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnButtonCancel);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&settingsDialog::OnInit);
	//*)

	Settings* settings = Resources::Instance()->getSettings();

	TelnetExecutableText->SetValue( settings->getTelnetExec() );
	SSHExecutableText->SetValue( settings->getSSHExec() );
	VNCExecutableText->SetValue( settings->getVNCExec() );



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
    Resources::Instance()->getSettings()->setTelnetExec( TelnetExecutableText->GetValue() );
    Resources::Instance()->getSettings()->setTelnetArgument( TelnetArgumentText->GetValue() );
    Resources::Instance()->getSettings()->setSSHExec( SSHExecutableText->GetValue() );
    Resources::Instance()->getSettings()->setSSHArgument( SSHArgumentText->GetValue() );
    Resources::Instance()->getSettings()->setVNCExec( VNCExecutableText->GetValue() );
    Resources::Instance()->getSettings()->setVNCArgument( VNCArgumentText->GetValue() );
    Resources::Instance()->getSettings()->saveSettings();
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

void settingsDialog::OnVNCBrowseClick(wxCommandEvent& event)
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

void settingsDialog::OnVNCArgumentResetButtonClick(wxCommandEvent& event)
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
        VNCArgumentText->SetValue( wxT("%hostname%::%port%") );
    #elif defined(__UNIX__)
        VNCArgumentText->SetValue( wxT("TODO") );
    #endif
}

void settingsDialog::OnHelpArgumentClick(wxCommandEvent& WXUNUSED(event) )
{
    wxMessageBox( wxT("Commandline-arguments sent to the choosen application will be parsed before sent.\n\nExample: A connection with the hostname telnet.example.com and username foobar would expand the argument string \"-telnet %username%@%hostname%\" to \"-telnet foobar@telnet.example.com\".\n\nIf you want to avoid expanding part of the argument if a specific string is empty you can define this using {}.\nExample: A connection without a password would expand the following argument \"-ssh {%username%@}%hostname%{ -pw %password%}\" to this: \"-ssh foobar@ssh.example.com\".\n\nFollowing strings can be used:\n%hostname%\n%connectiontype%\n%username%\n%password%\n%port%"), wxT("Command-line arguments"), wxICON_INFORMATION );
}
