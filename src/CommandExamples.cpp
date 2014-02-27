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

#include "CommandExamples.h"
#include "Resources.h"

//(*InternalHeaders(CommandExamples)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CommandExamples)
const long CommandExamples::ID_LISTCTRL1 = wxNewId();
const long CommandExamples::ID_BUTTON1 = wxNewId();
const long CommandExamples::ID_BUTTON2 = wxNewId();
const long CommandExamples::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommandExamples,wxDialog)
	//(*EventTable(CommandExamples)
	//*)
END_EVENT_TABLE()

CommandExamples::CommandExamples(wxWindow* parent,wxWindowID id,const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(CommandExamples)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(461,154), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer2->Add(ListCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ButtonAdd = new wxButton(Panel1, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	ButtonAdd->Disable();
	BoxSizer3->Add(ButtonAdd, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonClose = new wxButton(Panel1, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(ButtonClose, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&CommandExamples::OnListCtrl1ItemSelectDeselect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&CommandExamples::OnListCtrl1ItemSelectDeselect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&CommandExamples::OnListCtrl1ItemActivated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandExamples::AddCommand);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandExamples::OnClose);
	//*)

	loadExampleCommands();
	displayCommands();
}

CommandExamples::~CommandExamples()
{
	//(*Destroy(CommandExamples)
	//*)
	for ( std::map< wxString, Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
		delete (*it).first;
	}
}

void CommandExamples::loadExampleCommands()
{
    /** mount C$ **/
    wxString mount_C_name = wxT("mount C$");
    std::map< int, wxString > mount_C_ConnectionProgram;
    std::map< int, wxString > mount_C_ConnectionArgument;
    mount_C_ConnectionProgram[ -1 ] = wxT("cmd.exe");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    mount_C_ConnectionArgument[ -1 ] = wxT("/C \"net use X: /DELETE & net use X: \\\\%hostname%\\C$ %password% /USER:%username% & explorer X:\"");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool mount_C_favorite = true;
    bool mount_C_safety = false;
    int mount_C_shortcutModifier = 2;
    int mount_C_shortcutKey = 67;
    bool mount_C_useSpecificCommands = false;
    Command *mount_C = new Command( mount_C_name, mount_C_ConnectionProgram, mount_C_ConnectionArgument, mount_C_name, mount_C_favorite, mount_C_safety, mount_C_shortcutModifier, mount_C_shortcutKey, mount_C_useSpecificCommands );
    commands[ wxT("Mounts the share C$ on a Windows controller and opens it in Explorer") ] = mount_C;
}

void CommandExamples::displayCommands()
{
    ListCtrl1->Freeze();
    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("Name") );
    ListCtrl1->InsertColumn( 1, wxT("Description") );
    ListCtrl1->SetColumnWidth( 0, 85 );
    ListCtrl1->SetColumnWidth( 1, 350 );

    long itemIndexCounter = 0;

    for ( std::map< wxString, Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
        wxListItem item;
        item.SetId( itemIndexCounter );
        ListCtrl1->InsertItem( item );
        ListCtrl1->SetItem( itemIndexCounter, 0, (*it).second->getName()  );
        ListCtrl1->SetItem( itemIndexCounter, 1, (*it).first );
        itemIndexCounter++;
    }
    ListCtrl1->Thaw();
}

Command* CommandExamples::getCommandFromList()
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        for ( ;; ) {
            itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
            if ( itemIndex == -1 ) {
                break;
            }
            wxString commandName = ListCtrl1->GetItemText( itemIndex );
            for ( std::map< wxString, Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
                if ( (*it).second->getName() == commandName ) {
                    return (*it).second;
                }
            }
        }
    }
    return NULL;
}

void CommandExamples::AddCommand(wxCommandEvent& WXUNUSED(event) )
{
    Command *commandToAdd = getCommandFromList();
    if ( NULL != commandToAdd ) {
        Resources::Instance()->getCommandDatabase()->saveCommand( commandToAdd );
        EndModal( 1 );
    } else {
        EndModal( 0 );
    }
}

void CommandExamples::OnClose(wxCommandEvent& WXUNUSED(event) )
{
    EndModal( 0 );
}

void CommandExamples::OnListCtrl1ItemSelectDeselect(wxListEvent& WXUNUSED(event) )
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        ButtonAdd->Enable( true );
    } else {
        ButtonAdd->Enable( false );
    }
}

void CommandExamples::OnListCtrl1ItemActivated(wxListEvent& event)
{
    AddCommand( event );
}
