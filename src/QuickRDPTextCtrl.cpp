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

#include "QuickRDPTextCtrl.h"

IMPLEMENT_DYNAMIC_CLASS(QuickRDPTextCtrl, wxTextCtrl)

BEGIN_EVENT_TABLE(QuickRDPTextCtrl, wxTextCtrl)
    EVT_CHAR(QuickRDPTextCtrl::OnChar)
END_EVENT_TABLE()

void QuickRDPTextCtrl::OnChar(wxKeyEvent &event)
{
    int keycode = event.GetKeyCode();
    /** check if we should hop to our next specified textCtrl. **/
    if ( nextTextCtrl != NULL && nextTextCtrlKey == keycode ) {
        nextTextCtrl->SetSelection( -1, -1 );
        nextTextCtrl->SetFocus();
    } else {
        /** check if input key is a valid key **/
        for ( std::vector< std::pair< int, int > >::iterator it = validKeyCodes.begin(); it != validKeyCodes.end(); ++it ) {
            if ( (*it).first <= keycode && (*it).second >= keycode ) {
                event.Skip();
            }
        }

        /** if we don't have any restriction on keycodes, we pass the input **/
        if ( validKeyCodes.empty() == true ) {
            event.Skip();
        }
    }

    /** we will also allow backspace and DEL, left arrow and right arrow, TAB no matter what **/
    if ( keycode == 8 || keycode == 127 || keycode == 314 || keycode == 316 || keycode == 13 || keycode == 9 ) {
        event.Skip();
    }
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
