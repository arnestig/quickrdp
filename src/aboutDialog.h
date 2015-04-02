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

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <wx/hyperlink.h>

//(*Headers(aboutDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class aboutDialog: public wxDialog
{
	public:

		aboutDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~aboutDialog();

		//(*Declarations(aboutDialog)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxStaticBitmap* StaticBitmap1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxStaticText* VersionText;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* StaticText4;
		//*)
		wxHyperlinkCtrl* Hyperlink1;
		wxHyperlinkCtrl* Hyperlink2;
		wxString gccVersion;
		wxString wxWidgetsVersion;
		wxString libcurlVersion;

	protected:

		//(*Identifiers(aboutDialog)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)
		static const long ID_HYPERLINK1;
		static const long ID_HYPERLINK2;

	private:

		//(*Handlers(aboutDialog)
		void OnCloseButton(wxCommandEvent& event);
		void OnShowBuildInformation(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
