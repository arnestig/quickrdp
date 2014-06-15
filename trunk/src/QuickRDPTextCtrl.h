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

#ifndef __QUICKRDP_TEXTCTRL__
#define __QUICKRDP_TEXTCTRL__

#include <wx/textctrl.h>
#include <vector>

/** We need this TextCtrl to fix the input validator in a good way. **/

class QuickRDPTextCtrl : public wxTextCtrl
{
    DECLARE_DYNAMIC_CLASS(QuickRDPTextCtrl)
    DECLARE_EVENT_TABLE()

    public:
        QuickRDPTextCtrl()
            :   nextTextCtrl( NULL ),
                nextTextCtrlKey( 0 )
        {}

        QuickRDPTextCtrl(wxWindow *parent,
                       wxWindowID id,
                       const wxString& value = wxEmptyString,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = 0,
                       const wxValidator& validator = wxDefaultValidator,
                       const wxString& name = wxTextCtrlNameStr)
            :   nextTextCtrl( NULL ),
                nextTextCtrlKey( 0 )
        {
            Create(parent, id, value, pos, size, style, validator, name);
            nextTextCtrl = NULL;
            nextTextCtrlKey = 0;
        }

        void OnChar( wxKeyEvent &event );
        void setNextTextCtrl( wxTextCtrl *nextTextCtrl, int nextTextCtrlKey );
        void addValidKeyCodes( std::pair< int, int > validKeyCodes );

    private:
        wxTextCtrl *nextTextCtrl;
        int nextTextCtrlKey;
        std::vector< std::pair< int, int > > validKeyCodes;
};

#endif
