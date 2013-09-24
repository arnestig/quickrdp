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

#ifndef NETCALC_H
#define NETCALC_H

#include "QuickRDPTextCtrl.h"

//(*Headers(IPCalculator)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class IPCalculator: public wxDialog
{
	public:

		IPCalculator(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~IPCalculator();

		//(*Declarations(IPCalculator)
		wxStaticText* StaticText2;
		QuickRDPTextCtrl* IPAddressText;
		wxTextCtrl* TextOutput;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxButton* ButtonCalc;
		QuickRDPTextCtrl* NetmaskText;
		//*)

	protected:

		//(*Identifiers(IPCalculator)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(IPCalculator)
		void OnButtonCalcClick(wxCommandEvent& event);
		void OnNetmaskCIDRText(wxCommandEvent& event);
		//*)
        unsigned char convertNetmaskToCIDR( std::vector< unsigned char > netmask );
        std::vector< unsigned char > convertCIDRToNetmask( unsigned char cidr );
        std::vector< unsigned char > parseIP();
        std::pair< std::vector< unsigned char >, unsigned char > parseNetmaskAndCIDR();
        bool isValueCIDR( wxString value );
        bool isValueNetmask( wxString value );
        bool isValidIPAddress( wxString value );
        bool isValidNetmaskValue( short value );

		DECLARE_EVENT_TABLE()
};

#endif
