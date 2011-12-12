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

#include "resourcesTabPanel.h"

//(*InternalHeaders(resourcesTabPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(resourcesTabPanel)
const long resourcesTabPanel::ID_CHECKBOX1 = wxNewId();
const long resourcesTabPanel::ID_STATICLINE1 = wxNewId();
const long resourcesTabPanel::ID_RADIOBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(resourcesTabPanel,wxPanel)
	//(*EventTable(resourcesTabPanel)
	//*)
END_EVENT_TABLE()

resourcesTabPanel::resourcesTabPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(resourcesTabPanel)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, id, wxDefaultPosition, wxSize(183,185), wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Map my disk to the remote computer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	BoxSizer2->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(400,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_1[3] = 
	{
		_("On the local computer"),
		_("On the remote computer"),
		_("No playback")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Sound playback"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer3->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);
	
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&resourcesTabPanel::OnDiskMappingClick);
	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&resourcesTabPanel::OnSoundClick);
	//*)
}

resourcesTabPanel::~resourcesTabPanel()
{
	//(*Destroy(resourcesTabPanel)
	//*)
}

void resourcesTabPanel::setOwner( RDPFrame *owner )
{
    this->owner = owner;
}

void resourcesTabPanel::OnSoundClick(wxCommandEvent& event)
{
    owner->checkForChanges();
}

void resourcesTabPanel::OnDiskMappingClick(wxCommandEvent& event)
{
    owner->checkForChanges();
}
