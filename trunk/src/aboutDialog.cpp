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

#include "aboutDialog.h"
#include "Resources.h"

#include <wx/hyperlink.h>
//(*InternalHeaders(aboutDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(aboutDialog)
const long aboutDialog::ID_STATICBITMAP1 = wxNewId();
const long aboutDialog::ID_STATICTEXT1 = wxNewId();
const long aboutDialog::ID_STATICTEXT8 = wxNewId();
const long aboutDialog::ID_STATICTEXT2 = wxNewId();
const long aboutDialog::ID_STATICTEXT3 = wxNewId();
const long aboutDialog::ID_STATICTEXT4 = wxNewId();
const long aboutDialog::ID_STATICTEXT5 = wxNewId();
const long aboutDialog::ID_STATICTEXT7 = wxNewId();
const long aboutDialog::ID_STATICTEXT6 = wxNewId();
const long aboutDialog::ID_PANEL1 = wxNewId();
//*)

const long aboutDialog::ID_HYPERLINK1 = wxNewId();
const long aboutDialog::ID_HYPERLINK2 = wxNewId();

BEGIN_EVENT_TABLE(aboutDialog,wxDialog)
	//(*EventTable(aboutDialog)
	//*)
END_EVENT_TABLE()

aboutDialog::aboutDialog(wxWindow* parent,wxWindowID WXUNUSED(id),const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(aboutDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,306));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(256,256), 0, _T("ID_STATICBITMAP1"));
	BoxSizer4->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("QuickRDP"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(41,41,41));
	wxFont StaticText1Font(18,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer7->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	VersionText = new wxStaticText(Panel1, ID_STATICTEXT8, _("Version"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer7->Add(VersionText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer7, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer3->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Manages RDP, telnet and SSH connections"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Copyright © 2010 - 2012 Tobias Eliasson"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Licence: GNU GPLv3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer6->Add(StaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Text"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText5->Hide();
	Hyperlink1 = new wxHyperlinkCtrl(Panel1, ID_HYPERLINK1, _("http://www.gnu.org/licenses/gpl.html"), _("http://www.gnu.org/licenses/gpl.html"),wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_CENTRE, _T("ID_HYPERLINK1"));
		BoxSizer6->Add(Hyperlink1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
	BoxSizer3->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("quickRDP project page"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer5->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("http://sourceforge.net/projects/quickrdp"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText6->Hide();
	Hyperlink2 = new wxHyperlinkCtrl(Panel1, ID_HYPERLINK2, _("http://sourceforge.net/projects/quickrdp"), _("http://sourceforge.net/projects/quickrdp"),wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_CENTRE, _T("ID_HYPERLINK2"));
		BoxSizer5->Add(Hyperlink2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);
	
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&aboutDialog::OnCloseButton);
	//*)
	StaticBitmap1->SetBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("preferences-desktop-remote-desktop-256x256.png") ) );
}

aboutDialog::~aboutDialog()
{
	//(*Destroy(aboutDialog)
	//*)
}


void aboutDialog::OnCloseButton(wxCommandEvent& WXUNUSED(event) )
{
    EndModal( 0 );
}
