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

#ifndef RESOURCESTABPANEL_H
#define RESOURCESTABPANEL_H

#include "RDPFrame.h"

//(*Headers(resourcesTabPanel)
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
//*)

class resourcesTabPanel: public wxPanel
{
	public:

		resourcesTabPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~resourcesTabPanel();

		//(*Declarations(resourcesTabPanel)
		wxCheckBox* CheckBox1;
		wxStaticLine* StaticLine1;
		wxRadioBox* RadioBox1;
		//*)

		void setOwner( RDPFrame *owner );

	protected:

		//(*Identifiers(resourcesTabPanel)
		static const long ID_CHECKBOX1;
		static const long ID_STATICLINE1;
		static const long ID_RADIOBOX1;
		//*)

	private:

		//(*Handlers(resourcesTabPanel)
		void OnSoundClick(wxCommandEvent& event);
		void OnDiskMappingClick(wxCommandEvent& event);
		//*)

		RDPFrame *owner;

		DECLARE_EVENT_TABLE()
};

#endif
