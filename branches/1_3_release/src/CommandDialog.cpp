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

#include "CommandDialog.h"
#include "Resources.h"
#include <vector>
#include "ExampleDialog.h"
#include "QuickrdpFunctions.h"

//(*InternalHeaders(CommandDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CommandDialog)
const long CommandDialog::ID_STATICTEXT1 = wxNewId();
const long CommandDialog::ID_TEXTCTRL1 = wxNewId();
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
const long CommandDialog::ID_STATICLINE1 = wxNewId();
const long CommandDialog::ID_LISTBOX1 = wxNewId();
const long CommandDialog::ID_BUTTON3 = wxNewId();
const long CommandDialog::ID_BUTTON4 = wxNewId();
const long CommandDialog::ID_BUTTON6 = wxNewId();
const long CommandDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommandDialog,wxDialog)
	//(*EventTable(CommandDialog)
	//*)
END_EVENT_TABLE()

CommandDialog::CommandDialog(wxWindow* parent,wxWindowID WXUNUSED(id) )
{
	//(*Initialize(CommandDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer14;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(391,253));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	nameTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(170,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(nameTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Program"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer5->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	programTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(135,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer5->Add(programTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(25,21), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer5->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer6->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	argumentTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(135,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer6->Add(argumentTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ArgumentHelpButton = new wxButton(Panel1, ID_BUTTON5, _("\?"), wxDefaultPosition, wxSize(25,21), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer6->Add(ArgumentHelpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Favorite"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer12->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
	BoxSizer13->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
	BoxSizer14->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT8"));
	StaticText8->SetForegroundColour(wxColour(255,0,0));
	StaticText8->SetToolTip(_("Create a shortcut key combination for executing the command on the selected connections.\nAvailable combinations are A-Z, 0-9 or F1-F12 combined with Alt,Ctrl and/or Shift.\n\nUse the textbox to input your combination."));
	BoxSizer14->Add(StaticText8, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextShortcut = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer14->Add(TextShortcut, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer14, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	saveButton = new wxButton(Panel1, ID_BUTTON2, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer7->Add(saveButton, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	CommandList = new wxListBox(Panel1, ID_LISTBOX1, wxDefaultPosition, wxSize(195,270), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	BoxSizer9->Add(CommandList, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	editButton = new wxButton(Panel1, ID_BUTTON3, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	editButton->Disable();
	BoxSizer10->Add(editButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RemoveButton = new wxButton(Panel1, ID_BUTTON4, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	RemoveButton->Disable();
	BoxSizer10->Add(RemoveButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxVERTICAL);
	BoxSizer11->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	exampleButton = new wxButton(Panel1, ID_BUTTON6, _("Examples"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer11->Add(exampleButton, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
	closeButton = new wxButton(Panel1, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer11->Add(closeButton, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
	BoxSizer10->Add(BoxSizer11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer10, 0, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommandDialog::OnNameTextChange);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnFileDialogClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnArgumentHelpButton);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnSaveButton);
	Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&CommandDialog::OnCommandListClick);
	Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&CommandDialog::OnListDoubleClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnButtonEdit);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnRemoveButton);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnExamplesButton);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnCloseButton);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&CommandDialog::OnInit);
	//*)

	TextShortcut->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&CommandDialog::HandlePanelKeyDown,0,this);

	reloadCommandList();

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

void CommandDialog::reloadCommandList()
{
    CommandList->Clear();
	std::vector< Command* > commands = Resources::Instance()->getCommandDatabase()->getCommands();

	for ( size_t sId = 0; sId < commands.size(); ++sId ) {
        CommandList->Append( commands[ sId ]->getName() );
	}
    nameTextCtrl->Clear();
    programTextCtrl->Clear();
    argumentTextCtrl->Clear();
    favoriteCheckbox->SetValue( false );
    safetyCheckbox->SetValue( false );
    TextShortcut->Clear();
    RemoveButton->Enable( false );
    editButton->Enable( false );

}

void CommandDialog::OnCloseButton(wxCommandEvent& WXUNUSED(event) )
{
   this->EndModal( 0 );
}

void CommandDialog::OnListDoubleClick(wxCommandEvent& WXUNUSED(event) )
{
    wxString selectedItem = CommandList->GetStringSelection();
    if ( selectedItem != wxT("") ) {
        Command *curCommand = Resources::Instance()->getCommandDatabase()->getCommand( selectedItem );
        if ( curCommand != NULL ) {
            nameTextCtrl->SetValue( curCommand->getName() );
            programTextCtrl->SetValue( curCommand->getProgram() );
            argumentTextCtrl->SetValue( curCommand->getArgument() );
            favoriteCheckbox->SetValue( curCommand->getFavorite() );
            safetyCheckbox->SetValue( curCommand->getSafety() );
            TextShortcut->ChangeValue( quickRDP::Keybinder::ModifierString( curCommand->getShortcutModifier() ) << quickRDP::Keybinder::KeycodeString(curCommand->getShortcutKey() ) );
        }
    }
}

void CommandDialog::OnCommandListClick(wxCommandEvent& WXUNUSED(event) )
{
    wxString selectedItem = CommandList->GetStringSelection();
    if ( selectedItem != wxT("") ) {
        RemoveButton->Enable( true );
        editButton->Enable( true );
    } else {
        RemoveButton->Enable( false );
        editButton->Enable( false );
    }
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
    Resources::Instance()->getCommandDatabase()->saveCommand(
                                                        nameTextCtrl->GetValue(),
                                                        programTextCtrl->GetValue(),
                                                        argumentTextCtrl->GetValue(),
                                                        favoriteCheckbox->GetValue(),
                                                        safetyCheckbox->GetValue(),
                                                        curShortcutMod,
                                                        curShortcutKey );
    reloadCommandList();
}

void CommandDialog::OnRemoveButton(wxCommandEvent& WXUNUSED(event) )
{
    wxString selectedItem = CommandList->GetStringSelection();
    if ( selectedItem != wxT("") ) {
        Resources::Instance()->getCommandDatabase()->deleteCommand( selectedItem );
        reloadCommandList();
    }
}

void CommandDialog::OnInit(wxInitDialogEvent& WXUNUSED(event) )
{
}

void CommandDialog::OnButtonEdit(wxCommandEvent& event)
{
    OnListDoubleClick( event ); /** same action as when we double click **/
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
    ExampleDialog *example = new ExampleDialog( wxT("Arguments sent to the command will be parsed before sent. Some special variables can be used to specialize the command.\n\nExample: A connection with the hostname telnet.example.com and username foobar would expand the argument string \"-telnet %username%@%hostname%\" to \"-telnet foobar@telnet.example.com\".\n\nIf you want to avoid expanding part of the argument if a specific string is empty you can define this using {}.\nExample: A connection without a password would expand the following argument \"-ssh {%username%@}%hostname%{ -pw %password%}\" to this: \"-ssh foobar@ssh.example.com\".\n\nFollowing strings can be used:\n%hostname%\n%connectiontype%\n%username%\n%password%\n%port%"), this );
    example->ShowModal();
    delete example;
}

void CommandDialog::OnFileDialogClick(wxCommandEvent& WXUNUSED(event) )
{
    if ( FileDialog1->ShowModal() == wxID_OK ) {
        programTextCtrl->SetValue( FileDialog1->GetPath() );
    }
}

void CommandDialog::HandlePanelKeyDown(wxKeyEvent& event)
{
    curShortcutMod = 0;
    curShortcutKey = 0;
    TextShortcut->Clear();
    TextShortcut->AppendText( quickRDP::Keybinder::ModifierString( event.GetModifiers() ) + quickRDP::Keybinder::KeycodeString( event.GetKeyCode() ));
    curShortcutMod = event.GetModifiers();
    curShortcutKey = event.GetKeyCode();
}
