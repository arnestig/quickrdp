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

#include "perlDialog.h"
#include "Resources.h"
#include <vector>

//(*InternalHeaders(perlDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(perlDialog)
const long perlDialog::ID_LISTCTRL1 = wxNewId();
const long perlDialog::ID_PANEL1 = wxNewId();
const long perlDialog::ID_STATICTEXT1 = wxNewId();
const long perlDialog::ID_TEXTCTRL2 = wxNewId();
const long perlDialog::ID_BUTTON1 = wxNewId();
const long perlDialog::ID_BUTTON3 = wxNewId();
const long perlDialog::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(perlDialog,wxDialog)
	//(*EventTable(perlDialog)
	//*)
END_EVENT_TABLE()

perlDialog::perlDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(perlDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxPoint(100,100));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(274,347), wxLC_REPORT|wxLC_NO_HEADER|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer2->Add(ListCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	scriptNameText = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(131,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer3->Add(scriptNameText, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	newButton = new wxButton(this, ID_BUTTON1, _("New"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	newButton->Disable();
	BoxSizer5->Add(newButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	deleteButton = new wxButton(this, ID_BUTTON3, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	deleteButton->Disable();
	BoxSizer5->Add(deleteButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	editButton = new wxButton(this, ID_BUTTON4, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer5->Add(editButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	cancelButton = new wxButton(this, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer4->Add(cancelButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&perlDialog::OnScriptListActivated);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&perlDialog::OnTextNameInput);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&perlDialog::OnNewScriptButton);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&perlDialog::OnButtonDelete);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&perlDialog::OnCancelClick);
	//*)

    reloadScriptList();
}

perlDialog::~perlDialog()
{
	//(*Destroy(perlDialog)
	//*)
}

void perlDialog::reloadScriptList()
{
	ListCtrl1->ClearAll();
	std::vector< wxString > scripts = Resources::Instance()->getPerlDatabase()->getScripts();
    ListCtrl1->InsertColumn(0, wxT(""));

	for ( size_t sId = 0; sId < scripts.size(); ++sId ) {
        wxListItem item;
        item.SetId( sId );
        ListCtrl1->InsertItem( item );
        ListCtrl1->SetItem( sId, 0, scripts[ sId ] );
	}
}

void perlDialog::OnTextNameInput(wxCommandEvent& event)
{
    if ( scriptNameText->IsEmpty() == true ) {
        newButton->Enable( false );
    } else {
        newButton->Enable( true );
    }
}

void perlDialog::OnScriptListActivated(wxListEvent& event)
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        /** HERE WE WILL ALSO LAUNCH THE EDITOR **/ //codeTextCtrl->SetText( Resources::Instance()->getPerlDatabase()->getScriptContent( ListCtrl1->GetItemText( itemIndex ) ) );
        scriptNameText->SetValue( ListCtrl1->GetItemText( itemIndex ) );
    }
}

void perlDialog::OnButtonDelete(wxCommandEvent& event)
{
    if ( scriptNameText->IsEmpty() == false ) {
        if ( wxMessageBox( wxT("Are you sure you want to delete ") + scriptNameText->GetValue() + wxT("?"), wxT("Confirm action"), wxYES_NO ) == wxYES ) {
            Resources::Instance()->getPerlDatabase()->deleteScript( scriptNameText->GetValue() );
            reloadScriptList();
        }
    }
}

void perlDialog::OnNewScriptButton(wxCommandEvent& event)
{
    /** set default text to our perl script. **/
    /**codeTextCtrl->SetText(wxT("#!/usr/bin/perl -w\r\n\r\n# Arguments sent from QuickRDP to the perl interpreter:\r\n# $ARGV[0]     -   Hostname / IP-address\r\n# $ARGV[1]     -   Connection (RDP,SSH,TELNET)\r\n# $ARGV[2]     -   Username (if any, otherwise \"NO_USER\")\r\n# $ARGV[3]     -   Password (if any, otherwise \"NO_PASS\")\r\n\r\n"));
    TextCtrl2->Clear(); **/
    /// HERE WE WILL LAUNCH THE EXTERNAL COMMAND!
    reloadScriptList();
}

void perlDialog::OnCancelClick(wxCommandEvent& event)
{
    EndModal( 0 );
}
