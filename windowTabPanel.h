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

#ifndef WINDOWTABPANEL_H
#define WINDOWTABPANEL_H

#include "RDPFrame.h"

//(*Headers(windowTabPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/combobox.h>
//*)

class windowTabPanel: public wxPanel
{
	public:

		windowTabPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~windowTabPanel();

		//(*Declarations(windowTabPanel)
		wxRadioButton* RadioButton1;
		wxStaticText* StaticText2;
		wxRadioButton* RadioButton2;
		wxStaticText* StaticText1;
		wxStaticLine* StaticLine1;
		wxComboBox* ComboBox1;
		wxRadioBox* RadioBox1;
		wxComboBox* ComboBox2;
		//*)

		void setOwner( RDPFrame *owner );

	protected:

		//(*Identifiers(windowTabPanel)
		static const long ID_STATICTEXT1;
		static const long ID_RADIOBOX1;
		static const long ID_COMBOBOX2;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT2;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_COMBOBOX1;
		//*)

	private:

		//(*Handlers(windowTabPanel)
		void OnResoultionClick(wxCommandEvent& event);
		//*)

		RDPFrame *owner;

		DECLARE_EVENT_TABLE()
};

#endif
