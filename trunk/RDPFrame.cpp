/**
    Copyright (C) 2010 quickRDP - Remote desktop organizer

    Written by Tobias Eliasson <arnestig@users.sourceforge.net>.

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

#include "RDPFrame.h"
#include "RDPDatabase.h"

#include <memory>

//(*InternalHeaders(RDPFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(RDPFrame)
const long RDPFrame::ID_NOTEBOOK1 = wxNewId();
const long RDPFrame::ID_BUTTON1 = wxNewId();
const long RDPFrame::ID_BUTTON2 = wxNewId();
const long RDPFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RDPFrame,wxDialog)
	//(*EventTable(RDPFrame)
	//*)
END_EVENT_TABLE()

extern std::auto_ptr<RDPDatabase> rdpDatabase;

RDPFrame::RDPFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	//(*Initialize(RDPFrame)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxSize(361,368), 0, _T("ID_NOTEBOOK1"));
	BoxSizer2->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->Disable();
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RDPFrame::onSaveClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RDPFrame::onCloseClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&RDPFrame::OnClose);
	//*)
	generalTab = new generalTabPanel( Notebook1, wxID_ANY );
	windowTab = new windowTabPanel( Notebook1, wxID_ANY );
	resourcesTab = new resourcesTabPanel( Notebook1, wxID_ANY );
	Notebook1->AddPage( generalTab, wxT("General") );
    Notebook1->AddPage( windowTab, wxT("Window") );
    Notebook1->AddPage( resourcesTab, wxT("Resources") );
    generalTab->setOwner( this );
    windowTab->setOwner( this );
    resourcesTab->setOwner( this );
}

RDPFrame::~RDPFrame()
{
	//(*Destroy(RDPFrame)
	//*)
}

void RDPFrame::loadRDPConnection( RDPConnection* rdpConnection )
{
    this->rdpConnection = rdpConnection;

    generalTab->TextCtrl2->ChangeValue( rdpConnection->getHostname() ); // hostname
    generalTab->TextCtrl7->ChangeValue( rdpConnection->getUsername() ); // user
    generalTab->TextCtrl3->ChangeValue( rdpConnection->getPassword() ); // pass
    generalTab->TextCtrl4->ChangeValue( rdpConnection->getDomain() ); // domain
    generalTab->TextCtrl6->ChangeValue( rdpConnection->getComment() ); // comment
    generalTab->TextCtrl5->ChangeValue( rdpConnection->getClientHostname() ); // client hostname
}

void RDPFrame::checkForChanges()
{
    bool hasChangedSomething = false;
    if ( generalTab->TextCtrl2->GetValue().Cmp( rdpConnection->getHostname() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl7->GetValue().Cmp( rdpConnection->getUsername() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl3->GetValue().Cmp( rdpConnection->getPassword() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl4->GetValue().Cmp( rdpConnection->getDomain() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl6->GetValue().Cmp( rdpConnection->getComment() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl5->GetValue().Cmp( rdpConnection->getClientHostname() ) != 0 ) { hasChangedSomething = true; }

    if ( generalTab->TextCtrl2->IsEmpty() == true ) {
        Button1->Disable();
        return;
    }

    if ( hasChangedSomething == false ) {
        Button1->Disable();
    } else {
        Button1->Enable();
    }
}

void RDPFrame::onCloseClick(wxCommandEvent& event)
{
    Close();
}

void RDPFrame::onSaveClick(wxCommandEvent& event)
{
    rdpConnection->setHostname( generalTab->TextCtrl2->GetValue() );
    rdpConnection->setUsername( generalTab->TextCtrl7->GetValue() );
    rdpConnection->setPassword( generalTab->TextCtrl3->GetValue() );
    rdpConnection->setDomain( generalTab->TextCtrl4->GetValue() );
    rdpConnection->setComment( generalTab->TextCtrl6->GetValue() );
    rdpConnection->setClientHostname( generalTab->TextCtrl5->GetValue() );

    rdpConnection->saveFile();
    Button1->Disable();
    Button2->SetFocus();
    Close();
}

void RDPFrame::OnClose(wxCloseEvent& event)
{
    if ( rdpConnection->getHostname().IsEmpty() == true ) {
        rdpDatabase->deleteRDPConnectionByPointer( rdpConnection );
    }
    Destroy();
}
