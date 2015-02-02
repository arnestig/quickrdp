/**
    Copyright (C) 2010-2015 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#include "CommandDialog.h"
#include "Resources.h"
#include <vector>
#include "ExampleDialog.h"
#include "QuickrdpFunctions.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(CommandDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(CommandDialog)
const long CommandDialog::ID_STATICTEXT1 = wxNewId();
const long CommandDialog::ID_TEXTCTRL1 = wxNewId();
const long CommandDialog::ID_STATICTEXT10 = wxNewId();
const long CommandDialog::ID_CHECKBOX3 = wxNewId();
const long CommandDialog::ID_CHOICE2 = wxNewId();
const long CommandDialog::ID_STATICTEXT2 = wxNewId();
const long CommandDialog::ID_TEXTCTRL2 = wxNewId();
const long CommandDialog::ID_BUTTON1 = wxNewId();
const long CommandDialog::ID_STATICTEXT3 = wxNewId();
const long CommandDialog::ID_TEXTCTRL3 = wxNewId();
const long CommandDialog::ID_BUTTON5 = wxNewId();
const long CommandDialog::ID_STATICTEXT4 = wxNewId();
const long CommandDialog::ID_STATICTEXT9 = wxNewId();
const long CommandDialog::ID_CHECKBOX1 = wxNewId();
const long CommandDialog::ID_STATICTEXT5 = wxNewId();
const long CommandDialog::ID_STATICTEXT6 = wxNewId();
const long CommandDialog::ID_CHECKBOX2 = wxNewId();
const long CommandDialog::ID_STATICTEXT7 = wxNewId();
const long CommandDialog::ID_STATICTEXT8 = wxNewId();
const long CommandDialog::ID_TEXTCTRL4 = wxNewId();
const long CommandDialog::ID_BUTTON2 = wxNewId();
const long CommandDialog::ID_BUTTON3 = wxNewId();
const long CommandDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommandDialog,wxDialog)
	//(*EventTable(CommandDialog)
	//*)
END_EVENT_TABLE()

CommandDialog::CommandDialog(wxWindow* parent,wxWindowID WXUNUSED(id) )
{
	//(*Initialize(CommandDialog)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer14;
	wxBoxSizer* BoxSizer5;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(509,247));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(478,247), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 7);
	BoxSizer4->Add(10,20,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	nameTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(170,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(nameTextCtrl, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Run on"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer9->Add(StaticText10, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(6,20,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	connectionTargetCheckbox = new wxCheckBox(Panel1, ID_CHECKBOX3, _("All connections"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	connectionTargetCheckbox->SetValue(true);
	BoxSizer9->Add(connectionTargetCheckbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	connectionTypeChoice = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	connectionTypeChoice->Append(_("RDP"));
	connectionTypeChoice->Append(_("Telnet"));
	connectionTypeChoice->Append(_("SSH"));
	connectionTypeChoice->Append(_("VNC"));
	connectionTypeChoice->Disable();
	BoxSizer9->Add(connectionTypeChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer9, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Program"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer5->Add(StaticText2, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 7);
	programTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(250,21), wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer5->Add(programTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(25,21), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer5->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer10->Add(StaticText3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 7);
	argumentTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(250,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer10->Add(argumentTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ArgumentHelpButton = new wxButton(Panel1, ID_BUTTON5, _("\?"), wxDefaultPosition, wxSize(25,21), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer10->Add(ArgumentHelpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(BoxSizer10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Favorite"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer12->Add(StaticText4, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT9"));
	StaticText9->SetForegroundColour(wxColour(255,0,0));
	StaticText9->SetToolTip(_("Favorite commands will appear in the top right-click menu instead of in the sub-menu called \"Commands\"."));
	BoxSizer12->Add(StaticText9, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	favoriteCheckbox = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	favoriteCheckbox->SetValue(false);
	BoxSizer12->Add(favoriteCheckbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer12, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Safety check"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer13->Add(StaticText5, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT6"));
	StaticText6->SetForegroundColour(wxColour(255,0,0));
	StaticText6->SetToolTip(_("Running commands with safety check will require you to confirm the command before actually running it."));
	BoxSizer13->Add(StaticText6, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	safetyCheckbox = new wxCheckBox(Panel1, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	safetyCheckbox->SetValue(false);
	BoxSizer13->Add(safetyCheckbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer13, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Keyboard shortcut"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer14->Add(StaticText7, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT8"));
	StaticText8->SetForegroundColour(wxColour(255,0,0));
	StaticText8->SetToolTip(_("Create a shortcut key combination for executing the command on the selected connections.\nAvailable combinations are A-Z, 0-9 or F1-F12 combined with Alt,Ctrl and/or Shift.\n\nUse the textbox to input your combination."));
	BoxSizer14->Add(StaticText8, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcut = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer14->Add(TextShortcut, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer14, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	saveButton = new wxButton(Panel1, ID_BUTTON2, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer8->Add(saveButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	closeButton = new wxButton(Panel1, ID_BUTTON3, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer8->Add(closeButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommandDialog::OnNameTextChange);
	Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&CommandDialog::OnconnectionTargetCheckboxClick);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&CommandDialog::OnconnectionTypeChoiceSelect);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommandDialog::OnChangesMade);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnFileDialogClick);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommandDialog::OnChangesMade);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnArgumentHelpButton);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&CommandDialog::OnChangesMade);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&CommandDialog::OnChangesMade);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnSaveButton);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnCloseButton);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&CommandDialog::OnInit);
	//*)

	TextShortcut->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&CommandDialog::HandlePanelKeyDown,0,this);

    /** set the command file dialog depending on windows or linux **/
    #if defined(__WXMSW__)
        FileDialog1->SetWildcard( wxT("Executable (*.exe)|*.exe|All files (*.*)|*.*"));
    #elif defined(__UNIX__)
        FileDialog1->SetWildcard( wxT("All files (*)|*"));
        FileDialog1->SetDirectory( wxT("/usr/bin" ) );
    #endif

    /** make sure our shortcut modifiers are 0 **/
    curShortcutMod = 0;
    curShortcutKey = 0;
}

CommandDialog::~CommandDialog()
{
	//(*Destroy(CommandDialog)
	//*)
}

void CommandDialog::LoadCommand( Command* command )
{
    nameTextCtrl->SetValue( command->getName() );
    connectionTargetCheckbox->SetValue( command->getUseSpecificCommands() == false );
    program = command->getProgram();
    argument = command->getArgument();
    if ( connectionTargetCheckbox->IsChecked() == true ) {
        connectionTypeChoice->Enable( false );
        programTextCtrl->SetValue( program[ -1 ] );
        argumentTextCtrl->SetValue( argument[ -1 ] );
    } else {
        connectionTypeChoice->Enable( true );
        programTextCtrl->SetValue( program[ 0 ] );
        argumentTextCtrl->SetValue( argument[ 0 ] );
    }

    favoriteCheckbox->SetValue( command->getFavorite() );
    safetyCheckbox->SetValue( command->getSafety() );
    TextShortcut->AppendText( quickRDP::Shortcuts::ModifierString( command->getShortcutModifier() ) + quickRDP::Shortcuts::KeycodeString( command->getShortcutKey() ) );
    curShortcutMod = command->getShortcutModifier();
    curShortcutKey = command->getShortcutKey();

    prevChoiceSelection = 0;
    connectionTypeChoice->SetSelection( 0 );
	saveButton->Enable( false );
}

void CommandDialog::OnCloseButton(wxCommandEvent& WXUNUSED(event) )
{
   this->EndModal( 0 );
}

void CommandDialog::OnNameTextChange(wxCommandEvent& WXUNUSED(event) )
{
    if ( nameTextCtrl->IsEmpty() == true ) {
        saveButton->Enable( false );
    } else {
        saveButton->Enable( true );
    }
}

void CommandDialog::OnSaveButton(wxCommandEvent& WXUNUSED(event) )
{
    /** also make sure that we've triggered the last save on the choice list if that's being used. **/
    wxCommandEvent evt;
    OnconnectionTypeChoiceSelect( evt );

    if ( connectionTargetCheckbox->IsChecked() == true ) {
        program[ -1 ] = programTextCtrl->GetValue();
        argument[ -1 ] = argumentTextCtrl->GetValue();
    } else {
        program[ connectionTypeChoice->GetSelection() ] = programTextCtrl->GetValue();
        argument[ connectionTypeChoice->GetSelection() ] = argumentTextCtrl->GetValue();
    }

    Resources::Instance()->getCommandDatabase()->saveCommand(
                                                    nameTextCtrl->GetValue(),
                                                    program,
                                                    argument,
                                                    favoriteCheckbox->GetValue(),
                                                    safetyCheckbox->GetValue(),
                                                    curShortcutMod,
                                                    curShortcutKey,
                                                    connectionTargetCheckbox->GetValue() == false );
    this->EndModal( 1 );
}

void CommandDialog::OnInit(wxInitDialogEvent& WXUNUSED(event) )
{
}

void CommandDialog::OnExamplesButton(wxCommandEvent& WXUNUSED(event) )
{
    ExampleDialog *example;
    #if defined(__WXMSW__)
        example = new ExampleDialog( wxT("Example: Filezilla FTP connection\nProgram: C:\\Program Files (x86)\\FileZilla FTP Client\\filezilla.exe\nArgument: ftp://%username%:%password%@%hostname%\n\nExample: Mount and open shared folder\nProgram: cmd.exe\nArgument: /C \"net use X: /DELETE & net use X: \\\\%hostname%\\C$ %password% /USER:%username% & explorer X:\"\n\nExample: Continuously ping host\nProgram: ping.exe\nArgument: %hostname% -t"), this );
    #else
        example = new ExampleDialog( wxT("Example: Scan host on port 21,22,23 and 80 with nmap\nProgram: nmap\nArgument: -p21-23,80 %hostname%"), this );
    #endif
    example->ShowModal();
    delete example;
}

void CommandDialog::OnArgumentHelpButton(wxCommandEvent& WXUNUSED(event) )
{
    ExampleDialog *example = new ExampleDialog( wxT("Arguments sent to the command will be parsed before sent. Some special variables can be used to specialize the command.\n\nExample: A connection with the hostname telnet.example.com and username foobar would expand the argument string \"-telnet %username%@%hostname%\" to \"-telnet foobar@telnet.example.com\".\n\nIf you want to avoid expanding part of the argument if a specific string is empty you can define this using {}.\nExample: A connection without a password would expand the following argument \"-ssh {%username%@}%hostname%{ -pw %password%}\" to this: \"-ssh foobar@ssh.example.com\".\n\nFollowing strings can be used:\n%hostname%\n%connectiontype%\n%username%\n%password%\n%port%\n\nCustom arguments using $<argument_name>$ - Each time a command is executed using custom arguments they will require input from user and replaces the $argument$ in the argument string."), this );
    example->ShowModal();
    delete example;
}

void CommandDialog::OnFileDialogClick(wxCommandEvent& WXUNUSED(event) )
{
    if ( FileDialog1->ShowModal() == wxID_OK ) {
        programTextCtrl->SetValue( FileDialog1->GetPath() );
    }
}

void CommandDialog::SaveCurrentShortcut( std::pair< int, int > shortcut )
{
    TextShortcut->Clear();
    TextShortcut->AppendText( quickRDP::Shortcuts::ModifierString( shortcut.second ) + quickRDP::Shortcuts::KeycodeString( shortcut.first ) );
    curShortcutKey = shortcut.first;
    curShortcutMod = shortcut.second;
}

void CommandDialog::HandlePanelKeyDown(wxKeyEvent& event)
{
    std::pair< int, int > shortcut = std::make_pair( event.GetKeyCode(), event.GetModifiers() );

    if ( shortcut.first != curShortcutKey || shortcut.second != curShortcutMod ) {
        /** if we wanted to clear the shortcut handle that here **/
        if ( event.GetKeyCode() == WXK_DELETE || event.GetKeyCode() == WXK_BACK ) {
            shortcut.first = 0;
            SaveCurrentShortcut( shortcut );
        }

        if ( quickRDP::Shortcuts::IsValidKeycode( event.GetKeyCode() ) == true ) {
            wxString shortcutNameInUse;
            if ( quickRDP::Shortcuts::IsCombinationInUse( shortcut, shortcutNameInUse ) == true ) {
                if ( wxMessageBox( wxT("Already in use by: ") + shortcutNameInUse + wxT(".\nDo you want to use this keycombination anyway?"), wxT("Duplicate keycombination found"), wxYES_NO ) == wxYES ) {
                    SaveCurrentShortcut( shortcut );
                }
            } else {
                SaveCurrentShortcut( shortcut );
            }
        }
    }
	saveButton->Enable( true );
}

void CommandDialog::OnconnectionTargetCheckboxClick(wxCommandEvent& WXUNUSED( event ) )
{
    if ( connectionTargetCheckbox->IsChecked() == true ) {
        connectionTypeChoice->Enable( false );
        /** save the current command to our buffer **/
        program[ connectionTypeChoice->GetSelection() ] = programTextCtrl->GetValue();
        argument[ connectionTypeChoice->GetSelection() ] = argumentTextCtrl->GetValue();

        /** and load the new selected command **/
        programTextCtrl->SetValue( program[ -1 ] );
        argumentTextCtrl->SetValue( argument[ -1 ] );
    } else {
        connectionTypeChoice->Enable( true );
        /** save the current command to our buffer **/
        program[ -1 ] = programTextCtrl->GetValue();
        argument[ -1 ] = argumentTextCtrl->GetValue();

        /** and load the new selected command **/
        programTextCtrl->SetValue( program[ connectionTypeChoice->GetSelection() ] );
        argumentTextCtrl->SetValue( argument[ connectionTypeChoice->GetSelection() ] );
        prevChoiceSelection = connectionTypeChoice->GetSelection();
    }
    saveButton->Enable( true );
}

void CommandDialog::OnconnectionTypeChoiceSelect(wxCommandEvent& WXUNUSED( event ) )
{
    if ( connectionTargetCheckbox->IsChecked() == false ) {
        /** save the current command to our buffer **/
        program[ prevChoiceSelection ] = programTextCtrl->GetValue();
        argument[ prevChoiceSelection ] = argumentTextCtrl->GetValue();

        /** and load the new selected command **/
        programTextCtrl->SetValue( program[ connectionTypeChoice->GetSelection() ] );
        argumentTextCtrl->SetValue( argument[ connectionTypeChoice->GetSelection() ] );
        prevChoiceSelection = connectionTypeChoice->GetSelection();
    }
}

void CommandDialog::OnChangesMade(wxCommandEvent& event)
{
    saveButton->Enable( true );
}
