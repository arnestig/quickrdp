/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, telnet and SSH connections

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

#ifndef NETWORKSCANNER_H
#define NETWORKSCANNER_H

//(*Headers(NetworkScanner)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/gauge.h>
//*)

#include "connectionchecker.h"
#include "QuickRDPTextCtrl.h"

class NetworkScanner: public wxDialog
{
	public:

		NetworkScanner(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NetworkScanner();

		//(*Declarations(NetworkScanner)
		wxStaticText* StaticText9;
		wxButton* ButtonAddSelected;
		QuickRDPTextCtrl* OtherPortsText;
		wxListCtrl* ListCtrl1;
		QuickRDPTextCtrl* IPTo2;
		wxButton* ButtonClose;
		wxStaticText* StaticText2;
		wxCheckBox* CheckboxShowAll;
		wxButton* Button1;
		wxStaticText* StaticText6;
		QuickRDPTextCtrl* IPFrom3;
		wxGauge* Gauge1;
		QuickRDPTextCtrl* IPTo3;
		wxStaticText* StaticText8;
		wxCheckBox* RDPCheckBox;
		wxPanel* Panel1;
		QuickRDPTextCtrl* IPFrom4;
		QuickRDPTextCtrl* IPFrom1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* ScanButton;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxCheckBox* SSHCheckBox;
		QuickRDPTextCtrl* IPTo4;
		wxCheckBox* TelnetCheckBox;
		wxStaticLine* StaticLine1;
		QuickRDPTextCtrl* IPTo1;
		QuickRDPTextCtrl* IPFrom2;
		wxStaticText* StaticText4;
		wxCheckBox* VNCCheckBox;
		//*)

	protected:

		//(*Identifiers(NetworkScanner)
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL8;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_STATICTEXT9;
		static const long ID_BUTTON3;
		static const long ID_TEXTCTRL9;
		static const long ID_GAUGE1;
		static const long ID_STATICLINE1;
		static const long ID_LISTCTRL1;
		static const long ID_CHECKBOX5;
		static const long ID_ADD_SELECTED;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

        ConnectionChecker *scanner;
        std::vector< RDPConnection* > targets;
        std::map< int, RDPConnection* > ListCtrlRDPConnectionTable;
        unsigned int targetsAdded;
        wxImageList *imageList;
        //(*Handlers(NetworkScanner)
        void OnScan(wxCommandEvent& event);
        void OnCheckBoxesClick(wxCommandEvent& event);
        void OnButtonAdd(wxCommandEvent& event);
        void OnListCtrlSelect(wxListEvent& event);
        void OnListCtrlItemActivated(wxListEvent& event);
        void OnClose(wxCommandEvent& event);
        void OnQuit(wxCloseEvent& event);
        void OnShowAllConnections(wxCommandEvent& event);
        void OnOtherPortsHelpClick(wxCommandEvent& event);
        //*)
        void onScanResult( wxCommandEvent& event );

        void cleanTargets();
        void populateListCtrl();
        void addTargetToListCtrl( RDPConnection *connection );
        void addNewConnection( RDPConnection *target );
        void redrawListCtrl();
        std::vector< RDPConnection* > getSelectedConnections();
        RDPConnection* getConnectionFromId( long connectionCheckerId );
        std::vector< int > getCustomPortsFromTextCtrl();
        std::vector< wxString > getIPRange( wxString first, wxString last );
        wxString getNextIP( int ipaddress );
        void startScanner();
        void stopScanner();

		DECLARE_EVENT_TABLE()
};

#endif
