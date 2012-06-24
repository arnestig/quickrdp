/**
    Copyright (C) 2010-2012 QuickRDP - Manages RDP, telnet and SSH connections

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

#ifndef __QUICKRDP_BITMAPBUTTON__
#define __QUICKRDP_BITMAPBUTTON__

#include <wx/bmpbuttn.h>

/** We need this Bitmap Button to override the TAB focus on the buttons.
    We don't want it in our main frame where we only want to cycle between the search text and connection list **/

class QuickRDPBitmapButton : public wxBitmapButton
{
    public:
    QuickRDPBitmapButton() {}

    QuickRDPBitmapButton(wxWindow *parent,
                   wxWindowID id,
                   const wxBitmap& bitmap,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxValidator& validator = wxDefaultValidator,
                   const wxString& name = wxButtonNameStr)
    {
        Create( parent, id, bitmap, pos, size, style, validator, name );
    }

    virtual bool AcceptsFocusFromKeyboard() const {
        return false;
    }
};

#endif
