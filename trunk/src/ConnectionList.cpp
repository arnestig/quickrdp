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

#include "ConnectionList.h"

//(*InternalHeaders(ConnectionList)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/msgdlg.h>

#include "Resources.h"

//(*IdInit(ConnectionList)
const long ConnectionList::ID_LISTCTRL1 = wxNewId();
const long ConnectionList::ID_COLUMN_HOSTNAME = wxNewId();
const long ConnectionList::ID_COLUMN_PORT = wxNewId();
const long ConnectionList::ID_COLUMN_USERNAME = wxNewId();
const long ConnectionList::ID_COLUMN_CONNECTIONTYPE = wxNewId();
const long ConnectionList::ID_COLUMN_USECONSOLE = wxNewId();
const long ConnectionList::ID_COLUMN_RESOLUTION = wxNewId();
const long ConnectionList::ID_COLUMN_COMMENT = wxNewId();
const long ConnectionList::ID_COLUMN_CLIENTNAME = wxNewId();
//*)

BEGIN_EVENT_TABLE(ConnectionList,wxPanel)
	//(*EventTable(ConnectionList)
	//*)
END_EVENT_TABLE()

ConnectionList::ConnectionList(wxWindow* parent, quickRDPFrame *mainFrame, wxWindowID id )
    :   mainFrame( mainFrame )
{
	//(*Initialize(ConnectionList)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer1->Add(ListCtrl1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_HOSTNAME, _("Hostname"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem1);
	MenuItem1->Enable(false);
	MenuItem2 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_PORT, _("Port"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem2);
	MenuItem3 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_USERNAME, _("Username"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem3);
	MenuItem4 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_CONNECTIONTYPE, _("Connection"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem4);
	MenuItem5 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_USECONSOLE, _("Use console"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem5);
	MenuItem6 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_RESOLUTION, _("Resolution"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem6);
	MenuItem7 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_COMMENT, _("Comment"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem7);
	MenuItem8 = new wxMenuItem((&ColumnListChooserMenu), ID_COLUMN_CLIENTNAME, _("Client name"), wxEmptyString, wxITEM_CHECK);
	ColumnListChooserMenu.Append(MenuItem8);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ConnectionList::OnItemSelected);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&ConnectionList::OnItemDeselected);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ConnectionList::OnItemActivated);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&ConnectionList::OnItemRightClick);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&ConnectionList::OnColumnClick);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_RIGHT_CLICK,(wxObjectEventFunction)&ConnectionList::OnColumnRightClick);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_END_DRAG,(wxObjectEventFunction)&ConnectionList::OnColumnEndDrag);
	Connect(ID_COLUMN_HOSTNAME,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_PORT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_USERNAME,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_CONNECTIONTYPE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_USECONSOLE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_RESOLUTION,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_COMMENT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	Connect(ID_COLUMN_CLIENTNAME,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ConnectionList::OnColumnListChooserMenuClick);
	//*)

    //addColumns();
}

ConnectionList::~ConnectionList()
{
	//(*Destroy(ConnectionList)
	//*)
}

wxListCtrl* ConnectionList::getConnectionList()
{
    return ListCtrl1;
}

void ConnectionList::OnColumnClick(wxListEvent& event)
{
    mainFrame->OnColumnClick( event );
}

void ConnectionList::OnItemRightClick(wxListEvent& event)
{
    mainFrame->OnItemRightClick( event );
}

void ConnectionList::OnItemActivated(wxListEvent& event)
{
    mainFrame->OnItemActivated( event );
}

void ConnectionList::OnItemSelected(wxListEvent& event)
{
    mainFrame->OnItemSelected( event );
}

void ConnectionList::OnItemDeselected(wxListEvent& event)
{
    mainFrame->OnItemDeselected( event );
}

void ConnectionList::OnColumnEndDrag(wxListEvent& WXUNUSED(event) )
{
    /** We've moved the size on some of the columns.
    Save this setting so we get the correct size on other panels **/
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        int columns = settings->getConnectionListColumns();
        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap = settings->getConnectionListColumMap();
        std::vector< int > newWidths;
        int columnCounter = 0;
        for ( size_t colId = 0; colId < connectionListColumnMap.size(); ++colId ) {
            bool hasColumn = ( columns & connectionListColumnMap[ colId ].second );
            if ( hasColumn == true ) {
                newWidths.push_back( ListCtrl1->GetColumnWidth( columnCounter++ ) );
            } else {
                newWidths.push_back( settings->getConnectionListColumnWidth( colId ) );
            }
        }
        settings->setConnectionListColumnWidths( newWidths );
    }
    mainFrame->UpdateFrameWidthOnAllListConnections();
}

void ConnectionList::UpdateColumnWidth()
{
    /** update our colums width depending on what our settings say. **/
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        int columns = settings->getConnectionListColumns();
        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap = settings->getConnectionListColumMap();
        int columnCounter = 0;
        for ( size_t colId = 0; colId < connectionListColumnMap.size(); ++colId ) {
            bool hasColumn = ( columns & connectionListColumnMap[ colId ].second );
            if ( hasColumn == true ) {
                ListCtrl1->SetColumnWidth( columnCounter++, settings->getConnectionListColumnWidth( colId ) );
            }
        }
    }
}

void ConnectionList::OnColumnRightClick(wxListEvent& WXUNUSED(event))
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        int columns = settings->getConnectionListColumns();
        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap = settings->getConnectionListColumMap();
        for ( size_t colId = 0; colId < connectionListColumnMap.size(); ++colId ) {
            bool check = ( columns & connectionListColumnMap[ colId ].second );
            wxMenuItem* curMenuItem = ColumnListChooserMenu.FindItemByPosition( colId );
            if ( curMenuItem != NULL ) {
                curMenuItem->Check( check );
            }
        }
        PopupMenu( &ColumnListChooserMenu );
    }
}

void ConnectionList::OnColumnListChooserMenuClick(wxCommandEvent& event)
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        wxString columnName = ColumnListChooserMenu.GetLabel( event.GetId() );
        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap = settings->getConnectionListColumMap();
        for ( std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > >::const_iterator it = connectionListColumnMap.begin(); it != connectionListColumnMap.end(); ++it ) {
            if ( (*it).first == columnName ) {
                int columns = settings->getConnectionListColumns();
                columns ^= (*it).second;
                settings->setConnectionListColumns( columns );
            }
        }
        mainFrame->loadRDPFromDatabase();
    }
}

void ConnectionList::addColumns()
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        ListCtrl1->ClearAll();
        int columns = settings->getConnectionListColumns();
        std::vector< std::pair< wxString, ConnectionListColumn::ConnectionListColumn > > connectionListColumnMap = settings->getConnectionListColumMap();
        for ( size_t colId = 0; colId < connectionListColumnMap.size(); ++colId ) {
            bool addColumn = ( columns & connectionListColumnMap[ colId ].second );
            if ( addColumn == true ) {
                ListCtrl1->InsertColumn( ListCtrl1->GetColumnCount(), connectionListColumnMap[ colId ].first );
            }
        }
    }
    UpdateColumnWidth();
}
