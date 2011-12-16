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

#include "settingsDialog.h"
#include "Resources.h"

//(*InternalHeaders(settingsDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(settingsDialog)
const long settingsDialog::ID_STATICTEXT1 = wxNewId();
const long settingsDialog::ID_TEXTCTRL1 = wxNewId();
const long settingsDialog::ID_BUTTON1 = wxNewId();
const long settingsDialog::ID_STATICTEXT3 = wxNewId();
const long settingsDialog::ID_TEXTCTRL2 = wxNewId();
const long settingsDialog::ID_BUTTON2 = wxNewId();
const long settingsDialog::ID_BUTTON3 = wxNewId();
const long settingsDialog::ID_BUTTON4 = wxNewId();
const long settingsDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(settingsDialog,wxDialog)
	//(*EventTable(settingsDialog)
	//*)
END_EVENT_TABLE()

settingsDialog::settingsDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(settingsDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(373,153));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("PuTTY location"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(200,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->Disable();
	BoxSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Plink location"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(200,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->Disable();
	BoxSizer4->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Ok"), wxDefaultPosition, wxSize(75,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer5->Add(Button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(Panel1, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxSize(75,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer5->Add(Button4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, _("Locate PuTTY"), wxEmptyString, wxEmptyString, _("PuTTY (putty.exe)|putty.exe|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnPuttyBrowseClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnButtonSave);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settingsDialog::OnButtonCancel);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&settingsDialog::OnInit);
	//*)
	TextCtrl1->SetValue( Resources::Instance()->getSettings()->getPuttyExec() );
	TextCtrl2->SetValue( Resources::Instance()->getSettings()->getPlinkExec() );
}

settingsDialog::~settingsDialog()
{
	//(*Destroy(settingsDialog)
	//*)
}


void settingsDialog::OnPuttyBrowseClick(wxCommandEvent& event)
{
    if ( FileDialog1->ShowModal() == wxID_OK ) {
        TextCtrl1->SetValue( FileDialog1->GetPath() );
    }
}

void settingsDialog::OnInit(wxInitDialogEvent& event)
{
}

void settingsDialog::OnButtonSave(wxCommandEvent& event)
{
    Resources::Instance()->getSettings()->setPuttyExec( TextCtrl1->GetValue() );
    Resources::Instance()->getSettings()->setPlinkExec( TextCtrl2->GetValue() );
    Resources::Instance()->getSettings()->saveSettings();
    this->EndModal( 0 );
}

void settingsDialog::OnButtonCancel(wxCommandEvent& event)
{
    this->EndModal( 1 );
}
