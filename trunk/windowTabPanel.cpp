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

#include "windowTabPanel.h"

//(*InternalHeaders(windowTabPanel)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(windowTabPanel)
const long windowTabPanel::ID_STATICTEXT1 = wxNewId();
const long windowTabPanel::ID_RADIOBOX1 = wxNewId();
const long windowTabPanel::ID_COMBOBOX2 = wxNewId();
const long windowTabPanel::ID_STATICLINE1 = wxNewId();
const long windowTabPanel::ID_STATICTEXT2 = wxNewId();
const long windowTabPanel::ID_RADIOBUTTON1 = wxNewId();
const long windowTabPanel::ID_RADIOBUTTON2 = wxNewId();
const long windowTabPanel::ID_COMBOBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(windowTabPanel,wxPanel)
	//(*EventTable(windowTabPanel)
	//*)
END_EVENT_TABLE()

windowTabPanel::windowTabPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(windowTabPanel)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer13 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Screen resolution"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer13->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer13->Add(116,20,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer13, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Default resolution"),
		_("Fullscreen"),
		_("Custom resolution")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Label"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_RADIOBOX1"));
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
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(344,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer9 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Colors"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	BoxSizer9->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(116,20,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer9, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Default colors"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	BoxSizer4->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Custom colors"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	BoxSizer5->Add(RadioButton2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(116,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
	ComboBox1->Append(_("\"High Color\" (15 bits)"));
	ComboBox1->SetSelection( ComboBox1->Append(_("\"High Color\" (16 bits)")) );
	ComboBox1->Append(_("\"True Color\" (24 bits)"));
	BoxSizer5->Add(ComboBox1, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer3, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer1->Add(BoxSizer8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&windowTabPanel::OnResoultionClick);
	//*)
}

windowTabPanel::~windowTabPanel()
{
	//(*Destroy(windowTabPanel)
	//*)
}

void windowTabPanel::setOwner( RDPFrame *owner )
{
    this->owner = owner;
}

void windowTabPanel::OnResoultionClick(wxCommandEvent& event)
{
}
