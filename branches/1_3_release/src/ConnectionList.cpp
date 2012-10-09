#include "ConnectionList.h"

//(*InternalHeaders(ConnectionList)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "Resources.h"

//(*IdInit(ConnectionList)
const long ConnectionList::ID_LISTCTRL1 = wxNewId();
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
	ListCtrl1->InsertColumn( 0, wxT("Host") );
	ListCtrl1->InsertColumn( 1, wxT("Username") );
	ListCtrl1->InsertColumn( 2, wxT("Connection") );
	ListCtrl1->InsertColumn( 3, wxT("Use console") );
	ListCtrl1->InsertColumn( 4, wxT("Resolution") );
	ListCtrl1->InsertColumn( 5, wxT("Comment") );
	BoxSizer1->Add(ListCtrl1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ConnectionList::OnItemSelected);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&ConnectionList::OnItemDeselected);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ConnectionList::OnItemActivated);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&ConnectionList::OnItemRightClick);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&ConnectionList::OnColumnClick);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_END_DRAG,(wxObjectEventFunction)&ConnectionList::OnColumnEndDrag);
	//*)

	UpdateColumnWidth();
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
        settings->setColumn0Width( ListCtrl1->GetColumnWidth( 0 ) );
        settings->setColumn1Width( ListCtrl1->GetColumnWidth( 1 ) );
        settings->setColumn2Width( ListCtrl1->GetColumnWidth( 2 ) );
        settings->setColumn3Width( ListCtrl1->GetColumnWidth( 3 ) );
        settings->setColumn4Width( ListCtrl1->GetColumnWidth( 4 ) );
        settings->setColumn5Width( ListCtrl1->GetColumnWidth( 5 ) );
        settings->saveSettings();
    }
    mainFrame->UpdateFrameWidthOnAllListConnections();
}

void ConnectionList::UpdateColumnWidth()
{
    /** update our colums width depending on what our settings say. **/
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        ListCtrl1->SetColumnWidth( 0, settings->getColumn0Width() );
        ListCtrl1->SetColumnWidth( 1, settings->getColumn1Width() );
        ListCtrl1->SetColumnWidth( 2, settings->getColumn2Width() );
        ListCtrl1->SetColumnWidth( 3, settings->getColumn3Width() );
        ListCtrl1->SetColumnWidth( 4, settings->getColumn4Width() );
        ListCtrl1->SetColumnWidth( 5, settings->getColumn5Width() );
    }
}
