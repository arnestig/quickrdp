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

#include "QuickRDPTextCtrl.h"

IMPLEMENT_DYNAMIC_CLASS(QuickRDPTextCtrl, wxTextCtrl)

BEGIN_EVENT_TABLE(QuickRDPTextCtrl, wxTextCtrl)
    EVT_CHAR(QuickRDPTextCtrl::OnChar)
END_EVENT_TABLE()

bool QuickRDPTextCtrl::isValidInput( int keycode )
{
	for ( std::vector< std::pair< int, int > >::iterator it = validKeyCodes.begin(); it != validKeyCodes.end(); ++it ) {
		if ( (*it).first <= keycode && (*it).second >= keycode ) {
			return true;
		}
	}
	return false;
}

void QuickRDPTextCtrl::OnChar(wxKeyEvent &event)
{
    int keycode = event.GetKeyCode();
    /** First we will allow backspace and DEL, left arrow and right arrow, TAB no matter what **/
    if ( keycode == 8 || keycode == 127 || keycode == 314 || keycode == 316 || keycode == 13 || keycode == 9 ) {
        event.Skip();
    } else if ( GetStringSelection().IsEmpty() == false ) { /** we also want to allow replace text when something is selected **/
        event.Skip();
    } else if ( nextTextCtrl != NULL && nextTextCtrlKey == keycode ) { /** next text ctrl key pressed? **/
        nextTextCtrl->SetSelection( -1, -1 );
        nextTextCtrl->SetFocus();
    } else if ( nextTextCtrl != NULL && GetValue().Length()+1 == maxLength ) { /** max length input received? **/
		if ( isValidInput( keycode ) == true ) {
			event.Skip();
			nextTextCtrl->SetSelection( -1, -1 );
			nextTextCtrl->SetFocus();
		}
	} else {
        /** check if input key is a valid key **/
		if ( isValidInput( keycode ) == true ) {
			event.Skip();
		}

        /** if we don't have any restriction on keycodes, we pass the input **/
        if ( validKeyCodes.empty() == true ) {
            event.Skip();
        }
    }
}

void QuickRDPTextCtrl::setMaxLength( int maxLength )
{
    this->maxLength = maxLength;
}

void QuickRDPTextCtrl::setNextTextCtrl( wxTextCtrl *nextTextCtrl, int nextTextCtrlKey  )
{
    this->nextTextCtrl = nextTextCtrl;
    this->nextTextCtrlKey = nextTextCtrlKey;
}

void QuickRDPTextCtrl::addValidKeyCodes( std::pair< int, int > validKeyCodes )
{
    this->validKeyCodes.push_back( validKeyCodes );
}

