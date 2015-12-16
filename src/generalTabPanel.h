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

#ifndef GENERALTABPANEL_H
#define GENERALTABPANEL_H

//(*Headers(generalTabPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
//*)

class RDPFrame;

class generalTabPanel: public wxPanel
{
	public:

		generalTabPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~generalTabPanel();

		//(*Declarations(generalTabPanel)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl4;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxTextCtrl* TextCtrl6;
		wxStaticText* StaticText8;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxCheckBox* CheckBox1;
		wxTextCtrl* PortText;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl5;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		wxChoice* Choice1;
		//*)
		void setOwner( RDPFrame *owner );

	protected:

		//(*Identifiers(generalTabPanel)
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_CHECKBOX1;
		//*)

	private:

		//(*Handlers(generalTabPanel)
		void onTextUpdates(wxCommandEvent& event);
		void onConnectionChoice(wxCommandEvent& event);
		void OnTextEnter(wxCommandEvent& event);
		//*)
        RDPFrame *owner;
		DECLARE_EVENT_TABLE()
};

#endif
