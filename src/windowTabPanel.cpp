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

#include "windowTabPanel.h"

//(*InternalHeaders(windowTabPanel)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(windowTabPanel)
const long windowTabPanel::ID_RADIOBOX1 = wxNewId();
const long windowTabPanel::ID_COMBOBOX2 = wxNewId();
const long windowTabPanel::ID_STATICLINE1 = wxNewId();
const long windowTabPanel::ID_RADIOBOX2 = wxNewId();
const long windowTabPanel::ID_COMBOBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(windowTabPanel,wxPanel)
	//(*EventTable(windowTabPanel)
	//*)
END_EVENT_TABLE()

windowTabPanel::windowTabPanel(wxWindow* parent,wxWindowID WXUNUSED(id),const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(windowTabPanel)
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Default resolution"),
		_("Fullscreen"),
		_("Custom resolution")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Screen resolution"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer7->Add(RadioBox1, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(116,23), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX2"));
	ComboBox2->Append(_("640 x 480"));
	ComboBox2->SetSelection( ComboBox2->Append(_("800 x 600")) );
	ComboBox2->Append(_("1024 x 768"));
	ComboBox2->Append(_("1152 x 864"));
	ComboBox2->Append(_("1280 x 960"));
	ComboBox2->Append(_("1400 x 1050"));
	wxFont ComboBox2Font(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	ComboBox2->SetFont(ComboBox2Font);
	BoxSizer7->Add(ComboBox2, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(400,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_2[2] =
	{
		_("Default colors"),
		_("Custom colors")
	};
	RadioBox2 = new wxRadioBox(this, ID_RADIOBOX2, _("Colors"), wxDefaultPosition, wxSize(143,68), 2, __wxRadioBoxChoices_2, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_RADIOBOX2"));
	BoxSizer3->Add(RadioBox2, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(176,23), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
	ComboBox1->Append(_("\"High Color\" (15 bits)"));
	ComboBox1->SetSelection( ComboBox1->Append(_("\"High Color\" (16 bits)")) );
	ComboBox1->Append(_("\"True Color\" (24 bits)"));
	BoxSizer3->Add(ComboBox1, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer3, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer1->Add(BoxSizer8, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&windowTabPanel::OnResoultionClick);
	Connect(ID_COMBOBOX2,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&windowTabPanel::OnResoultionClick);
	Connect(ID_RADIOBOX2,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&windowTabPanel::OnColorsClick);
	Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&windowTabPanel::OnColorsClick);
	//*)
}

windowTabPanel::~windowTabPanel()
{
	//(*Destroy(windowTabPanel)
	//*)
}

void windowTabPanel::MarkComboBoxes()
{
    if ( RadioBox1->GetStringSelection() == wxT("Custom resolution") ) {
        ComboBox2->Enable();
    } else {
        ComboBox2->Disable();
    }

    if ( RadioBox2->GetStringSelection() == wxT("Custom colors") ) {
        ComboBox1->Enable();
    } else {
        ComboBox1->Disable();
    }
}

void windowTabPanel::setOwner( RDPFrame *owner )
{
    this->owner = owner;
}

void windowTabPanel::OnResoultionClick(wxCommandEvent& WXUNUSED(event) )
{
    MarkComboBoxes();
    owner->checkForChanges();
}

void windowTabPanel::OnColorsClick(wxCommandEvent& WXUNUSED(event) )
{
    MarkComboBoxes();
    owner->checkForChanges();
}
