/**
    Copyright (C) 2010-2015 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#ifndef QUICKRDPAPP_H
#define QUICKRDPAPP_H

#include <wx/app.h>
#include "quickRDPMain.h"

class quickRDPApp : public wxApp
{
    public:
        quickRDPApp();
        virtual bool OnInit();
        virtual int FilterEvent( wxEvent& event );
    private:
        quickRDPFrame* Frame;
};

#endif // QUICKRDPAPP_H
