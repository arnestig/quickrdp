/**
    Copyright (C) 2010-2013 QuickRDP - Manages RDP, telnet and SSH connections

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

#include "generalTabPanel.h"
#include "RDPFrame.h"

//(*InternalHeaders(generalTabPanel)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(generalTabPanel)
const long generalTabPanel::ID_STATICTEXT6 = wxNewId();
const long generalTabPanel::ID_STATICTEXT1 = wxNewId();
const long generalTabPanel::ID_CHOICE1 = wxNewId();
const long generalTabPanel::ID_STATICTEXT2 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL2 = wxNewId();
const long generalTabPanel::ID_STATICTEXT10 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL1 = wxNewId();
const long generalTabPanel::ID_STATICTEXT8 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL7 = wxNewId();
const long generalTabPanel::ID_STATICTEXT3 = wxNewId();
const long generalTabPanel::ID_STATICTEXT9 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL3 = wxNewId();
const long generalTabPanel::ID_STATICTEXT7 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL6 = wxNewId();
const long generalTabPanel::ID_STATICTEXT4 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL4 = wxNewId();
const long generalTabPanel::ID_STATICTEXT5 = wxNewId();
const long generalTabPanel::ID_TEXTCTRL5 = wxNewId();
const long generalTabPanel::ID_CHECKBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(generalTabPanel,wxPanel)
	//(*EventTable(generalTabPanel)
	//*)
END_EVENT_TABLE()

generalTabPanel::generalTabPanel(wxWindow* parent,wxWindowID WXUNUSED(id),const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(generalTabPanel)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, wxID_ANY, wxDefaultPosition, wxSize(261,344), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Server and login information"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	BoxSizer9->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer9, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Connection type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer13->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("Remote desktop")) );
	Choice1->Append(_("Telnet"));
	Choice1->Append(_("SSH"));
	Choice1->Append(_("VNC"));
	BoxSizer13->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer13, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Hostname:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(101,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer2->Add(TextCtrl2, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer2->Add(StaticText10, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
	PortText = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(39,21), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(PortText, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Username:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer11->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer11->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer11, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Password:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer5->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT9"));
	StaticText9->SetForegroundColour(wxColour(255,0,0));
	StaticText9->SetToolTip(_("*** SECURITY RISK ***\nPlease note that for now passwords are stored in plain-text in your user\'s home directory. \nIt\'s a security risk since those files are commonly readable by other users on your system! \nUse wisely and on your own risk."));
	BoxSizer5->Add(StaticText9, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxTE_PASSWORD|wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer5->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer10->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer10->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer10, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Domain:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer6->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer6->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Client name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer7->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer7->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer7, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Attach to console"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	BoxSizer4->Add(CheckBox1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);
	
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&generalTabPanel::onConnectionChoice);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&generalTabPanel::onTextUpdates);
	//*)
}

generalTabPanel::~generalTabPanel()
{
	//(*Destroy(generalTabPanel)
	//*)
}

void generalTabPanel::setOwner( RDPFrame *owner )
{
    this->owner = owner;
}

void generalTabPanel::onTextUpdates(wxCommandEvent& WXUNUSED(event) )
{
    owner->checkForChanges();
}

void generalTabPanel::onConnectionChoice(wxCommandEvent& WXUNUSED(event) )
{
    owner->checkForChanges();
    owner->switchConnectionType( static_cast<ConnectionType::ConnectionType> ( Choice1->GetCurrentSelection() ) );
}
