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

#include "CommandList.h"
#include "Resources.h"
#include "CommandDialog.h"
#include "CommandExamples.h"
#include "QuickrdpFunctions.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(CommandList)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CommandList)
const long CommandList::ID_LISTCTRL1 = wxNewId();
const long CommandList::ID_PANEL1 = wxNewId();
const long CommandList::ID_BUTTON1 = wxNewId();
const long CommandList::ID_BUTTON5 = wxNewId();
const long CommandList::ID_BUTTON4 = wxNewId();
const long CommandList::ID_BUTTON2 = wxNewId();
const long CommandList::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommandList,wxDialog)
	//(*EventTable(CommandList)
	//*)
END_EVENT_TABLE()

CommandList::CommandList(wxWindow* parent,wxWindowID WXUNUSED( id ),const wxPoint& WXUNUSED( pos ),const wxSize& WXUNUSED( size ) )
{
	//(*Initialize(CommandList)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(772,272), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer2->Add(ListCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	buttonNew = new wxButton(this, ID_BUTTON1, _("New"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(buttonNew, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON5, _("Examples"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	buttonEdit = new wxButton(this, ID_BUTTON4, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer3->Add(buttonEdit, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	buttonDelete = new wxButton(this, ID_BUTTON2, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(buttonDelete, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	buttonClose = new wxButton(this, ID_BUTTON3, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(buttonClose, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&CommandList::OnListCtrl1ItemSelectDeselect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&CommandList::OnListCtrl1ItemSelectDeselect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&CommandList::OnListCtrl1ItemActivated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandList::OnbuttonNewClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandList::OnButtonExamples);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandList::OnbuttonEditClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandList::OnbuttonDeleteClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandList::OnbuttonCloseClick);
	//*)

	reloadCommandList();
}

CommandList::~CommandList()
{
	//(*Destroy(CommandList)
	//*)
}

void CommandList::reloadCommandList()
{
    std::vector< Command* > commandDatabase = Resources::Instance()->getCommandDatabase()->getCommands( true ); // force load the command database
    ListCtrl1->Freeze();

    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("Name") );
    ListCtrl1->InsertColumn( 1, wxT("Program") );
    ListCtrl1->InsertColumn( 2, wxT("Argument") );
    ListCtrl1->InsertColumn( 3, wxT("Favorite") );
    ListCtrl1->InsertColumn( 4, wxT("Safety check") );
    ListCtrl1->InsertColumn( 5, wxT("Shortcut") );
    ListCtrl1->SetColumnWidth( 0, 85 );
    ListCtrl1->SetColumnWidth( 1, 240 );
    ListCtrl1->SetColumnWidth( 2, 240 );
    ListCtrl1->SetColumnWidth( 3, 60 );
    ListCtrl1->SetColumnWidth( 4, 60 );
    ListCtrl1->SetColumnWidth( 5, 80 );

    long itemIndexCounter = 0;

    for ( size_t index = 0; index < commandDatabase.size(); index++ ) {
        Command* curCommand = commandDatabase[ index ];
        int columnCounter = 0;
        wxListItem item;
        item.SetId( index );
        ListCtrl1->InsertItem( item );
        ListCtrl1->SetItem( itemIndexCounter, columnCounter++, curCommand->getName() );

        /** special handling of program and argument strings based if we have any specific command for them **/
        std::map< int, wxString > programMap = curCommand->getProgram();
        std::map< int, wxString > argumentMap = curCommand->getArgument();
        wxString program, argument;
        if ( curCommand->getUseSpecificCommands() == true ) {
            if ( programMap[ static_cast< int >( ConnectionType::RDP ) ].empty() == false ) { program.Append( wxT(", RDP: ") + programMap[ static_cast< int >( ConnectionType::RDP ) ] ); }
            if ( programMap[ static_cast< int >( ConnectionType::SSH) ].empty() == false ) { program.Append( wxT(", SSH: ") + programMap[ static_cast< int >( ConnectionType::SSH ) ] ); }
            if ( programMap[ static_cast< int >( ConnectionType::TELNET ) ].empty() == false ) { program.Append( wxT(", Telnet: ") + programMap[ static_cast< int >( ConnectionType::TELNET ) ] ); }
            if ( programMap[ static_cast< int >( ConnectionType::VNC ) ].empty() == false ) { program.Append( wxT(", VNC: ") + programMap[ static_cast< int >( ConnectionType::VNC ) ] ); }
            if ( program.SubString( 0, 1 ) == wxT(", ") ) {
                program.Remove( 0, 2 );
            }

            if ( argumentMap[ static_cast< int >( ConnectionType::RDP ) ].empty() == false ) { argument.Append( wxT(", RDP: ") + argumentMap[ static_cast< int >( ConnectionType::RDP ) ] ); }
            if ( argumentMap[ static_cast< int >( ConnectionType::SSH) ].empty() == false ) { argument.Append( wxT(", SSH: ") + argumentMap[ static_cast< int >( ConnectionType::SSH ) ] ); }
            if ( argumentMap[ static_cast< int >( ConnectionType::TELNET ) ].empty() == false ) { argument.Append( wxT(", Telnet: ") + argumentMap[ static_cast< int >( ConnectionType::TELNET ) ] ); }
            if ( argumentMap[ static_cast< int >( ConnectionType::VNC ) ].empty() == false ) { argument.Append( wxT(", VNC: ") + argumentMap[ static_cast< int >( ConnectionType::VNC ) ] ); }
            if ( argument.SubString( 0, 1 ) == wxT(", ") ) {
                argument.Remove( 0, 2 );
            }
        } else {
            program = programMap[ -1 ];
            argument = argumentMap[ - 1 ];
        }

        ListCtrl1->SetItem( itemIndexCounter, columnCounter++, program );
        ListCtrl1->SetItem( itemIndexCounter, columnCounter++, argument );
        ListCtrl1->SetItem( itemIndexCounter, columnCounter++, boolToText( curCommand->getFavorite() ) );
        ListCtrl1->SetItem( itemIndexCounter, columnCounter++, boolToText( curCommand->getSafety() ) );
        ListCtrl1->SetItem( itemIndexCounter, columnCounter++, quickRDP::Shortcuts::ModifierString( curCommand->getShortcutModifier() ) << quickRDP::Shortcuts::KeycodeString( curCommand->getShortcutKey() ) );
        itemIndexCounter++;
    }
    ListCtrl1->Thaw();
    wxListEvent evt;
    OnListCtrl1ItemSelectDeselect( evt );
}

wxString CommandList::boolToText( bool value )
{
    if ( value == true ) {
        return wxT("Yes");
    } else {
        return wxT("No");
    }
}

void CommandList::OnbuttonCloseClick(wxCommandEvent& WXUNUSED( event ) )
{
    EndModal( 0 );
}

void CommandList::OnbuttonNewClick(wxCommandEvent& WXUNUSED( event ) )
{
    CommandDialog *commandDlg = new CommandDialog( this, 0 );
    if ( commandDlg->ShowModal() == 1 ) {
        reloadCommandList();
    }
    delete commandDlg;
}

void CommandList::OnbuttonEditClick(wxCommandEvent& WXUNUSED( event ) )
{
    int selectedIndex = getSelectedCommand();
    if ( selectedIndex != -1 ) {
        CommandDialog *commandDlg = new CommandDialog( this, 0 );
        Command* curCommand = Resources::Instance()->getCommandDatabase()->getCommands()[ selectedIndex ];
        commandDlg->LoadCommand( curCommand );
        if ( commandDlg->ShowModal() == 1 ) {
            reloadCommandList();
        }
        delete commandDlg;
    }
}

void CommandList::OnbuttonDeleteClick(wxCommandEvent& WXUNUSED( event ) )
{
    int selectedIndex = getSelectedCommand();
    if ( selectedIndex != -1 ) {
        Command* curCommand = Resources::Instance()->getCommandDatabase()->getCommands()[ selectedIndex ];
        if ( wxMessageBox( wxT("Are you sure you want to delete the command '") + curCommand->getName() + wxT("' ?"), wxT("Delete command?"), wxOK | wxCANCEL ) == wxOK ) {
            Resources::Instance()->getCommandDatabase()->deleteCommand( curCommand->getName() );
            reloadCommandList();
        }
    }
}

int CommandList::getSelectedCommand()
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        for ( ;; ) {
            itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
            if ( itemIndex == -1 ) {
                break;
            }
            return itemIndex;
        }
    }
    return -1;
}

void CommandList::OnListCtrl1ItemActivated(wxListEvent& WXUNUSED( event ) )
{
    wxCommandEvent evt;
    OnbuttonEditClick( evt );
}

void CommandList::OnListCtrl1ItemSelectDeselect(wxListEvent& WXUNUSED( event ) )
{
    if ( getSelectedCommand() == -1 ) {
        buttonDelete->Enable( false );
        buttonEdit->Enable( false );
    } else {
        buttonDelete->Enable( true );
        buttonEdit->Enable( true );
    }
}

void CommandList::OnButtonExamples(wxCommandEvent& WXUNUSED(event) )
{
    CommandExamples *commandExampleDlg = new CommandExamples( this, 0 );
    if ( commandExampleDlg->ShowModal() == 1 ) {
        reloadCommandList();
    }
    delete commandExampleDlg;
}
