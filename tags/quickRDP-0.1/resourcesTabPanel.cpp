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

#include "resourcesTabPanel.h"

//(*InternalHeaders(resourcesTabPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(resourcesTabPanel)
//*)

BEGIN_EVENT_TABLE(resourcesTabPanel,wxPanel)
	//(*EventTable(resourcesTabPanel)
	//*)
END_EVENT_TABLE()

resourcesTabPanel::resourcesTabPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(resourcesTabPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

resourcesTabPanel::~resourcesTabPanel()
{
	//(*Destroy(resourcesTabPanel)
	//*)
}

void resourcesTabPanel::setOwner( RDPFrame *owner )
{
    this->owner = owner;
}
