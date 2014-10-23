/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#include "IPCalculator.h"

//(*InternalHeaders(IPCalculator)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(IPCalculator)
const long IPCalculator::ID_STATICTEXT1 = wxNewId();
const long IPCalculator::ID_TEXTCTRL1 = wxNewId();
const long IPCalculator::ID_STATICTEXT2 = wxNewId();
const long IPCalculator::ID_TEXTCTRL2 = wxNewId();
const long IPCalculator::ID_BUTTON1 = wxNewId();
const long IPCalculator::ID_TEXTCTRL3 = wxNewId();
const long IPCalculator::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(IPCalculator,wxDialog)
	//(*EventTable(IPCalculator)
	//*)
END_EVENT_TABLE()

IPCalculator::IPCalculator(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(IPCalculator)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("IP-address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
	IPAddressText = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(120,25), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer3->Add(IPAddressText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(BoxSizer3, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Netmask or CIDR"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NetmaskText = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(120,25), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(NetmaskText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(BoxSizer4, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	ButtonCalc = new wxButton(Panel1, ID_BUTTON1, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	ButtonCalc->Disable();
	BoxSizer5->Add(ButtonCalc, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer6->Add(BoxSizer5, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer2->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	TextOutput = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(315,102), wxTE_NO_VSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextOutput->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	BoxSizer7->Add(TextOutput, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer7, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&IPCalculator::OnNetmaskCIDRText);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&IPCalculator::OnButtonCalcClick);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&IPCalculator::OnNetmaskCIDRText);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&IPCalculator::OnButtonCalcClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&IPCalculator::OnButtonCalcClick);
	//*)

	NetmaskText->addValidKeyCodes( std::make_pair( 48, 57 ) );
	NetmaskText->addValidKeyCodes( std::make_pair( 46, 46 ) );
	NetmaskText->SetMaxLength( 15 );

	IPAddressText->addValidKeyCodes( std::make_pair( 48, 57 ) );
	IPAddressText->addValidKeyCodes( std::make_pair( 46, 46 ) );
	IPAddressText->SetMaxLength( 15 );
}

IPCalculator::~IPCalculator()
{
	//(*Destroy(IPCalculator)
	//*)
}

unsigned char IPCalculator::convertNetmaskToCIDR( std::vector< unsigned char > netmask )
{
    unsigned char cidr = 0;
    unsigned char tmp_netmask[ 4 ] = { netmask[ 0 ], netmask[ 1 ], netmask[ 2 ], netmask[ 3 ] };
    for ( int index = 0; index < 4; index++ ) {
        while( tmp_netmask[ index ] > 0 ) {
            tmp_netmask[ index ] <<= 1;
            cidr++;
        }
    }
    return cidr;
}

std::vector< unsigned char > IPCalculator::convertCIDRToNetmask( unsigned char cidr )
{
    std::vector< unsigned char > mask;
    mask.push_back( ~(0x000000ff >> cidr) );
    mask.push_back( ~(0x0000ffff >> cidr) );
    mask.push_back( ~(0x00ffffff >> cidr) );
    mask.push_back( ~(0xffffffff >> cidr) );
    return mask;
}

std::vector< unsigned char > IPCalculator::parseIP()
{
    std::vector< unsigned char > ip_subset;
    std::string ip_address = std::string( IPAddressText->GetValue().mb_str() );

    for ( int index = 0; index < 4; index++ ) {
        int ip_dot_location = ip_address.find_first_of( "." );
        ip_subset.push_back( atoi( ip_address.substr( 0, ip_dot_location ).c_str() ) );
        ip_address = ip_address.substr( ip_dot_location + 1 );
    }
    return ip_subset;
}

std::pair< std::vector< unsigned char >, unsigned char > IPCalculator::parseNetmaskAndCIDR()
{
    std::vector< unsigned char > netmask;
    unsigned char CIDR;

    if ( isValueCIDR( NetmaskText->GetValue() ) == true ) {
        netmask = convertCIDRToNetmask( wxAtoi( NetmaskText->GetValue() ) );
        CIDR = convertNetmaskToCIDR( netmask );
    } else {
        std::string netmask_cidr = std::string( NetmaskText->GetValue().mb_str() );
        for ( int index = 0; index < 4; index++ ) {
            int netmask_dot_location = netmask_cidr.find_first_of( "." );
            netmask.push_back( atoi( netmask_cidr.substr( 0, netmask_dot_location ).c_str() ) );
            netmask_cidr = netmask_cidr.substr( netmask_dot_location + 1 );
        }
        CIDR = convertNetmaskToCIDR( netmask );
    }

    return std::make_pair( netmask, CIDR );
}

void IPCalculator::OnButtonCalcClick(wxCommandEvent& WXUNUSED( event ) )
{
    std::vector< unsigned char > ip_address = parseIP();
    std::pair< std::vector< unsigned char >, unsigned char > netmaskAndCIDR = parseNetmaskAndCIDR();
    std::vector< unsigned char > netmask = netmaskAndCIDR.first;
    unsigned char cidr = netmaskAndCIDR.second;
    unsigned char network_first[ 4 ];
    unsigned char network_last[ 4 ];

    TextOutput->Clear();

    for ( int index = 0; index < 4; index++ ) {
        network_first[ index ] = ip_address[ index ] & netmask[ index ];
        network_last[ index ] = ip_address[ index ] | ~(netmask[ index ]);
    }
    unsigned int number_of_hosts = pow( 2,(32-cidr) ) - 2;

    TextOutput->AppendText( wxString::Format( wxT("IP-address:\t%d.%d.%d.%d\n"), ip_address[ 0 ], ip_address[ 1 ], ip_address[ 2 ], ip_address[ 3 ] ) );
    TextOutput->AppendText( wxString::Format( wxT("Network:\t\t%d.%d.%d.%d/%d (%d hosts)\n"), network_first[ 0 ], network_first[ 1 ], network_first[ 2 ], network_first[ 3 ], cidr, number_of_hosts ) );
    TextOutput->AppendText( wxString::Format( wxT("Netmask:\t\t%d.%d.%d.%d\n"), netmask[ 0 ], netmask[ 1 ], netmask[ 2 ], netmask[ 3 ] ) );
    TextOutput->AppendText( wxString::Format( wxT("First address:\t%d.%d.%d.%d\n"), network_first[ 0 ], network_first[ 1 ], network_first[ 2 ], network_first[ 3 ] + 1 ) );
    TextOutput->AppendText( wxString::Format( wxT("Last address:\t%d.%d.%d.%d\n"), network_last[ 0 ], network_last[ 1 ], network_last[ 2 ], network_last[ 3 ] - 1 ) );
    TextOutput->AppendText( wxString::Format( wxT("Broadcast:\t%d.%d.%d.%d"), network_last[ 0 ], network_last[ 1 ], network_last[ 2 ], network_last[ 3 ] ) );
}

bool IPCalculator::isValidNetmaskValue( short value )
{
    switch( value ) {
        case 0:
        case 128:
        case 192:
        case 224:
        case 240:
        case 248:
        case 252:
        case 254:
        case 255:
            return true;
        break;
        default:
            return false;
        break;
    }
}

bool IPCalculator::isValueCIDR( wxString value )
{
    int length = value.Length();
    if ( length > 0 && length < 3 ) {
        int value = wxAtoi( NetmaskText->GetValue() );
        if ( value > 0 && value < 33 ) {
            return true;
        }
    }

    return false;
}

bool IPCalculator::isValidIPAddress( wxString value )
{
    int length = value.Length();
    short ip_value[] = { -1, -1, -1, -1 };
    if ( length > 6 && length < 16 ) {
        std::string ipaddress = std::string( IPAddressText->GetValue().mb_str() );
        for ( int index = 0; index < 4; index++ ) {
            int ip_dot_location = ipaddress.find_first_of( "." );
            if ( ip_dot_location != -1 || index == 3 ) {
                if ( ipaddress.substr( 0, ip_dot_location ).length() > 0 ) {
                    ip_value[ index ] = atoi( ipaddress.substr( 0, ip_dot_location ).c_str() );
                }
            }
            ipaddress = ipaddress.substr( ip_dot_location + 1 );
        }
    }

    for ( int index = 0; index < 4; index++ ) {
        if ( ip_value[ index ] < 0 || ip_value[ index ] > 255 ) {
            return false;
        }
    }

    return true;
}

bool IPCalculator::isValueNetmask( wxString value )
{
    int length = value.Length();
    short netmask_value[] = { -1, -1, -1, -1 };
    if ( length > 6 && length < 16 ) {
        std::string netmask_cidr = std::string( NetmaskText->GetValue().mb_str() );
        for ( int index = 0; index < 4; index++ ) {
            int netmask_dot_location = netmask_cidr.find_first_of( "." );
            if ( netmask_dot_location != -1 || index == 3 ) {
                if ( netmask_cidr.substr( 0, netmask_dot_location ).length() > 0 ) {
                    netmask_value[ index ] = atoi( netmask_cidr.substr( 0, netmask_dot_location ).c_str() );
                }
            }
            netmask_cidr = netmask_cidr.substr( netmask_dot_location + 1 );
        }
    }

    for ( int index = 0; index < 4; index++ ) {
        if ( isValidNetmaskValue( netmask_value[ index ] ) == false ) {
            return false;
        }
    }

    return true;
}

void IPCalculator::OnNetmaskCIDRText(wxCommandEvent& WXUNUSED( event ) )
{
    if ( ( isValueCIDR( NetmaskText->GetValue() ) == true || isValueNetmask( NetmaskText->GetValue() ) == true ) && isValidIPAddress( IPAddressText->GetValue() ) == true ) {
        ButtonCalc->Enable();
    } else {
        ButtonCalc->Disable();
    }
}
