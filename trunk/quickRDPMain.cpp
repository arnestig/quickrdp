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

#include "quickRDPMain.h"
#include "RDPFrame.h"
#include "RDPDatabase.h"
#include "Configuration.h"
#include "aboutDialog.h"

#include <wx/msgdlg.h>
#include <memory>

//(*InternalHeaders(quickRDPFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(quickRDPFrame)
const long quickRDPFrame::ID_BITMAPBUTTON1 = wxNewId();
const long quickRDPFrame::ID_BITMAPBUTTON4 = wxNewId();
const long quickRDPFrame::ID_BITMAPBUTTON2 = wxNewId();
const long quickRDPFrame::ID_BITMAPBUTTON3 = wxNewId();
const long quickRDPFrame::ID_LISTCTRL1 = wxNewId();
const long quickRDPFrame::ID_PANEL1 = wxNewId();
const long quickRDPFrame::idMenuQuit = wxNewId();
const long quickRDPFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(quickRDPFrame,wxFrame)
    //(*EventTable(quickRDPFrame)
    //*)
END_EVENT_TABLE()

std::auto_ptr<RDPDatabase> rdpDatabase;

quickRDPFrame::quickRDPFrame(wxWindow* parent,wxWindowID id)
{
    rdpDatabase = std::auto_ptr<RDPDatabase> ( new RDPDatabase() );
    //(*Initialize(quickRDPFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, id, _("quickRDP"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(172,202));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("data/preferences-desktop-remote-desktop.png"))));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(182,217), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("data/document-new.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetDefault();
    BitmapButton1->SetToolTip(_("New connection"));
    BoxSizer3->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("data/network-workgroup.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->SetBitmapDisabled(wxBitmap(wxImage(_T("data/network-workgroup-disabled.png"))));
    BitmapButton4->Disable();
    BitmapButton4->SetToolTip(_("Duplicate connection"));
    BoxSizer3->Add(BitmapButton4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("data/edit-delete.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->SetBitmapDisabled(wxBitmap(wxImage(_T("data/edit-delete-disabled.png"))));
    BitmapButton2->Disable();
    BitmapButton2->SetToolTip(_("Delete connection"));
    BoxSizer3->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("data/preferences-other.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->SetBitmapDisabled(wxBitmap(wxImage(_T("data/preferences-other-disabled.png"))));
    BitmapButton3->Disable();
    BitmapButton3->SetToolTip(_("View properties"));
    BoxSizer3->Add(BitmapButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(566,278), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL1"));
    ListCtrl1->InsertColumn( 0, wxT("Host") );
    ListCtrl1->InsertColumn( 1, wxT("Username") );
    ListCtrl1->InsertColumn( 2, wxT("Use console") );
    ListCtrl1->InsertColumn( 3, wxT("Resolution") );
    BoxSizer2->Add(ListCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnNewButtonClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDuplicateButtonClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDeleteButtonClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnEditButtonClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemDeselect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemActivated);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnAbout);
    //*)
    loadRDPFromDatabase();
}

quickRDPFrame::~quickRDPFrame()
{
    //(*Destroy(quickRDPFrame)
    //*)
}

void quickRDPFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void quickRDPFrame::OnAbout(wxCommandEvent& event)
{
    aboutDialog *about = new aboutDialog( this, 0 );
    about->ShowModal();
    delete about;
}

void quickRDPFrame::OnListCtrl1ItemSelect(wxListEvent& event)
{
    BitmapButton2->Enable();
    BitmapButton3->Enable();
    BitmapButton4->Enable();
}

void quickRDPFrame::OnListCtrl1ItemDeselect(wxListEvent& event)
{
    BitmapButton2->Disable();
    BitmapButton3->Disable();
    BitmapButton4->Disable();
}

void quickRDPFrame::OnNewButtonClick(wxCommandEvent& event)
{
    const char hex[] = "ABCDEF0123456789";
    wxString filename;
    srand( time( NULL ) );
    for ( size_t index = 0; index < 32; index++ ) {
        filename.Append( wxString( &hex[ rand() % 16 ] , wxConvUTF8, 1 ) );
    }

    RDPFrame *newFrame = new RDPFrame( this, 0 );
    newFrame->loadRDPConnection( rdpDatabase->addRDPConnection( filename ) );
    newFrame->ShowModal();
    loadRDPFromDatabase();
    delete newFrame;
    if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
        BitmapButton2->Disable();
        BitmapButton3->Disable();
        BitmapButton4->Disable();
    }
}

void quickRDPFrame::OnDeleteButtonClick(wxCommandEvent& event)
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        rdpDatabase->deleteRDPConnectionById( itemIndex );
        loadRDPFromDatabase();
        if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}

void quickRDPFrame::OnEditButtonClick(wxCommandEvent& event)
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPFrame *newFrame = new RDPFrame( this, 0 );
        newFrame->loadRDPConnection( rdpDatabase->getRDPConnectionById( itemIndex ) );
        newFrame->ShowModal();
        loadRDPFromDatabase();
        delete newFrame;
        if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}

void quickRDPFrame::loadRDPFromDatabase()
{
    clearListCtrl();

    std::vector<RDPConnection*> database = rdpDatabase->getDatabase();

    for ( size_t index = 0; index < database.size(); index++ ) {
        RDPConnection* curRDP = database[ index ];
        wxListItem item;
        item.SetId( index );
        ListCtrl1->InsertItem( item );
        wxString username;
        if ( curRDP->getDomain().Len() > 0 ) {
            username.Append( curRDP->getDomain() + wxT("\\") );
        }
        username.Append( curRDP->getUsername() );
        ListCtrl1->SetItem( index, 0, curRDP->getHostname() );
        ListCtrl1->SetItem( index, 1, username );

        if ( curRDP->getConsole() == wxT("1") ) {
            ListCtrl1->SetItem( index, 2, wxT("Yes") );
        } else {
            ListCtrl1->SetItem( index, 2, wxT("No" ) );
        }

        if ( curRDP->getScreenMode() == wxT("2") ) {
            ListCtrl1->SetItem( index, 3, wxT("Fullscreen") );
        } else if ( curRDP->getDesktopHeight() == wxT("0") && curRDP->getDesktopWidth() == wxT("0") ) {
            ListCtrl1->SetItem( index, 3, wxT("Default") );
        } else {
            ListCtrl1->SetItem( index, 3, curRDP->getDesktopWidth() + wxT(" x ") + curRDP->getDesktopHeight() );
        }
    }

    ListCtrl1->SetColumnWidth( 0, wxLIST_AUTOSIZE );
    ListCtrl1->SetColumnWidth( 1, wxLIST_AUTOSIZE );
    ListCtrl1->SetColumnWidth( 3, wxLIST_AUTOSIZE );
}

void quickRDPFrame::clearListCtrl()
{
    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("Host") );
    ListCtrl1->InsertColumn( 1, wxT("Username") );
    ListCtrl1->InsertColumn( 2, wxT("Use console") );
    ListCtrl1->InsertColumn( 3, wxT("Resolution") );
}

void quickRDPFrame::OnListCtrl1ItemActivated(wxListEvent& event)
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        rdpDatabase->getRDPConnectionById( itemIndex )->connect();
    }
}

void quickRDPFrame::OnDuplicateButtonClick(wxCommandEvent& event)
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        /** HÄR SKALL VI KOPIERA EN ANSLUTNING.... **/


        /**RDPFrame *newFrame = new RDPFrame( this, 0 );
        newFrame->loadRDPConnection( rdpDatabase->getRDPConnectionById( itemIndex ) );
        newFrame->ShowModal();**/
        loadRDPFromDatabase();
//        delete newFrame;
        if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}
