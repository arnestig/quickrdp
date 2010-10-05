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
#include <wx/settings.h>
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
const long quickRDPFrame::ID_TEXTCTRL1 = wxNewId();
const long quickRDPFrame::ID_LISTCTRL1 = wxNewId();
const long quickRDPFrame::ID_PANEL1 = wxNewId();
const long quickRDPFrame::idMenuQuit = wxNewId();
const long quickRDPFrame::idMenuAbout = wxNewId();
const long quickRDPFrame::ID_POPUPMENUPROPERTIES = wxNewId();
const long quickRDPFrame::ID_POPUPMENUCONSOLE = wxNewId();
const long quickRDPFrame::ID_MENUDEFAULT = wxNewId();
const long quickRDPFrame::ID_MENUFULLSCREEN = wxNewId();
const long quickRDPFrame::ID_MENUITEM5 = wxNewId();
const long quickRDPFrame::ID_MENUITEM6 = wxNewId();
const long quickRDPFrame::ID_MENUITEM7 = wxNewId();
const long quickRDPFrame::ID_MENUITEM8 = wxNewId();
const long quickRDPFrame::ID_MENUITEM9 = wxNewId();
const long quickRDPFrame::ID_MENUITEM10 = wxNewId();
const long quickRDPFrame::ID_MENUITEM4 = wxNewId();
const long quickRDPFrame::ID_MENUITEM1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(quickRDPFrame,wxFrame)
    //(*EventTable(quickRDPFrame)
    //*)
END_EVENT_TABLE()

std::auto_ptr<RDPDatabase> rdpDatabase;
std::vector<RDPConnection*> ListCtrlRDPRelation;

quickRDPFrame::quickRDPFrame(wxWindow* parent,wxWindowID id)
{
    rdpDatabase = std::auto_ptr<RDPDatabase> ( new RDPDatabase() );
    //(*Initialize(quickRDPFrame)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
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
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("data/document-new.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetToolTip(_("New connection"));
    BoxSizer5->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("data/network-workgroup.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->SetBitmapDisabled(wxBitmap(wxImage(_T("data/network-workgroup-disabled.png"))));
    BitmapButton4->Disable();
    BitmapButton4->SetToolTip(_("Duplicate connection"));
    BoxSizer5->Add(BitmapButton4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("data/edit-delete.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->SetBitmapDisabled(wxBitmap(wxImage(_T("data/edit-delete-disabled.png"))));
    BitmapButton2->Disable();
    BitmapButton2->SetToolTip(_("Delete connection"));
    BoxSizer5->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("data/preferences-other.png"))), wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->SetBitmapDisabled(wxBitmap(wxImage(_T("data/preferences-other-disabled.png"))));
    BitmapButton3->Disable();
    BitmapButton3->SetToolTip(_("View properties"));
    BoxSizer5->Add(BitmapButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Search"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(172,27), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    StaticBoxSizer1->Add(TextCtrl1, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    BoxSizer4->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(566,278), wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
    ListCtrl1->InsertColumn( 0, wxT("Host") );
    ListCtrl1->InsertColumn( 1, wxT("Username") );
    ListCtrl1->InsertColumn( 2, wxT("Use console") );
    ListCtrl1->InsertColumn( 3, wxT("Resolution") );
    ListCtrl1->InsertColumn( 4, wxT("Comment") );
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
    MenuItem3 = new wxMenuItem((&PopupMenu1), ID_POPUPMENUPROPERTIES, _("Properties"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem3);
    PopupMenu1.AppendSeparator();
    MenuItem4 = new wxMenuItem((&PopupMenu1), ID_POPUPMENUCONSOLE, _("Attach to console"), wxEmptyString, wxITEM_CHECK);
    PopupMenu1.Append(MenuItem4);
    MenuItem5 = new wxMenu();
    MenuItem6 = new wxMenuItem(MenuItem5, ID_MENUDEFAULT, _("Default"), wxEmptyString, wxITEM_CHECK);
    MenuItem5->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(MenuItem5, ID_MENUFULLSCREEN, _("Fullscreen"), wxEmptyString, wxITEM_CHECK);
    MenuItem5->Append(MenuItem7);
    MenuItem8 = new wxMenu();
    MenuItem9 = new wxMenuItem(MenuItem8, ID_MENUITEM5, _("640 x 480"), wxEmptyString, wxITEM_CHECK);
    MenuItem8->Append(MenuItem9);
    MenuItem10 = new wxMenuItem(MenuItem8, ID_MENUITEM6, _("800 x 600"), wxEmptyString, wxITEM_CHECK);
    MenuItem8->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(MenuItem8, ID_MENUITEM7, _("1024 x 768"), wxEmptyString, wxITEM_CHECK);
    MenuItem8->Append(MenuItem11);
    MenuItem12 = new wxMenuItem(MenuItem8, ID_MENUITEM8, _("1152 x 864"), wxEmptyString, wxITEM_CHECK);
    MenuItem8->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(MenuItem8, ID_MENUITEM9, _("1280 x 960"), wxEmptyString, wxITEM_CHECK);
    MenuItem8->Append(MenuItem13);
    MenuItem14 = new wxMenuItem(MenuItem8, ID_MENUITEM10, _("1400 x 1050"), wxEmptyString, wxITEM_CHECK);
    MenuItem8->Append(MenuItem14);
    MenuItem5->Append(ID_MENUITEM4, _("Custom"), MenuItem8, wxEmptyString);
    PopupMenu1.Append(ID_MENUITEM1, _("Resolution"), MenuItem5, wxEmptyString);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnNewButtonClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDuplicateButtonClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDeleteButtonClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnEditButtonClick);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&quickRDPFrame::OnSearchTextEnter);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&quickRDPFrame::OnSearchTextEnter);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemDeselect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemActivated);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemRClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ColumnClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnAbout);
    Connect(ID_POPUPMENUPROPERTIES,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem3Selected);
    Connect(ID_POPUPMENUCONSOLE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem4Selected);
    Connect(ID_MENUDEFAULT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItemDefaultClick);
    Connect(ID_MENUFULLSCREEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItemFullscreenClick);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem640);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem800);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem1024);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem1152);
    Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem1280);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem1400);
    //*)
    TextCtrl1->Connect(ID_TEXTCTRL1,wxEVT_LEFT_DOWN,(wxObjectEventFunction)&quickRDPFrame::OnTextCtrlClick,0,this);

    last_column_click = 0;

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
        rdpDatabase->deleteRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
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
        newFrame->loadRDPConnection( rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] ) );
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
    ListCtrlRDPRelation.clear();
    long itemIndexCounter = 0;

    for ( size_t index = 0; index < database.size(); index++ ) {
        RDPConnection* curRDP = database[ index ];
        // if we have a filter in place, we search the RDPConnection and checks if any value matches our pattern. if it doesn't, we hop to the next item in the database.
        if ( curRDP->doesRDPHasString( TextCtrl1->GetValue() ) == true || TextCtrl1->GetValue() == wxT("Search ...") ) {
            ListCtrlRDPRelation.push_back( curRDP );
            wxListItem item;
            item.SetId( index );
            ListCtrl1->InsertItem( item );
            wxString username;
            if ( curRDP->getDomain().Len() > 0 ) {
                username.Append( curRDP->getDomain() + wxT("\\") );
            }
            username.Append( curRDP->getUsername() );
            ListCtrl1->SetItem( itemIndexCounter, 0, curRDP->getHostname() );
            ListCtrl1->SetItem( itemIndexCounter, 1, username );

            if ( curRDP->getConsole() == wxT("1") ) {
                ListCtrl1->SetItem( itemIndexCounter, 2, wxT("Yes") );
            } else {
                ListCtrl1->SetItem( itemIndexCounter, 2, wxT("No" ) );
            }

            if ( curRDP->getScreenMode() == wxT("2") ) {
                ListCtrl1->SetItem( itemIndexCounter, 3, wxT("Fullscreen") );
            } else if ( curRDP->getDesktopHeight() == wxT("0") && curRDP->getDesktopWidth() == wxT("0") ) {
                ListCtrl1->SetItem( itemIndexCounter, 3, wxT("Default") );
            } else {
                ListCtrl1->SetItem( itemIndexCounter, 3, curRDP->getDesktopWidth() + wxT(" x ") + curRDP->getDesktopHeight() );
            }

            ListCtrl1->SetItem( itemIndexCounter, 4, curRDP->getComment() );
            itemIndexCounter++;
        }
    }

    if ( ListCtrl1->GetItemCount() > 0 ) {
        ListCtrl1->SetColumnWidth( 0, wxLIST_AUTOSIZE );
        ListCtrl1->SetColumnWidth( 1, wxLIST_AUTOSIZE );
        ListCtrl1->SetColumnWidth( 2, 100 );
        ListCtrl1->SetColumnWidth( 3, wxLIST_AUTOSIZE );
        ListCtrl1->SetColumnWidth( 4, wxLIST_AUTOSIZE );
    } else {
        ListCtrl1->SetColumnWidth( 0, 80 );
        ListCtrl1->SetColumnWidth( 1, 123 );
        ListCtrl1->SetColumnWidth( 2, 100 );
        ListCtrl1->SetColumnWidth( 3, 82 );
        ListCtrl1->SetColumnWidth( 4, 107 );
    }
}

void quickRDPFrame::clearListCtrl()
{
    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("Host") );
    ListCtrl1->InsertColumn( 1, wxT("Username") );
    ListCtrl1->InsertColumn( 2, wxT("Use console") );
    ListCtrl1->InsertColumn( 3, wxT("Resolution") );
    ListCtrl1->InsertColumn( 4, wxT("Comment") );
}

void quickRDPFrame::OnListCtrl1ItemActivated(wxListEvent& event)
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->connect();
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

        const char hex[] = "ABCDEF0123456789";
        wxString filename;
        srand( time( NULL ) );
        for ( size_t index = 0; index < 32; index++ ) {
            filename.Append( wxString( &hex[ rand() % 16 ] , wxConvUTF8, 1 ) );
        }
        rdpDatabase->duplicateRDPConnection( filename, rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] ) );

        loadRDPFromDatabase();
        if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}

void quickRDPFrame::OnSearchTextEnter(wxCommandEvent& event)
{
    loadRDPFromDatabase();
}

void quickRDPFrame::clearPopupMenuChoices()
{
    MenuItem4->Check( false );
    MenuItem6->Check( false );
    MenuItem7->Check( false );
    MenuItem9->Check( false );
    MenuItem10->Check( false );
    MenuItem11->Check( false );
    MenuItem12->Check( false );
    MenuItem13->Check( false );
    MenuItem14->Check( false );
}

void quickRDPFrame::OnListCtrl1ItemRClick(wxListEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }

        clearPopupMenuChoices();

        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );

        if ( curRDP->getConsole() == wxT("1") )
        {
            MenuItem4->Check( true );
        }

        if ( curRDP->getScreenMode() == wxT("2") ) {
            MenuItem7->Check( true );
        } else if ( curRDP->getScreenMode() == wxT("1") && curRDP->getDesktopHeight() == wxT("0") && curRDP->getDesktopWidth() == wxT("0") ) {
            MenuItem6->Check( true );
        } else {
            wxString resolutionString = curRDP->getDesktopWidth() + wxT(" x ") + curRDP->getDesktopHeight();
            if ( resolutionString == wxT("640 x 480") ) { MenuItem9->Check( true ); }
            if ( resolutionString == wxT("800 x 600") ) { MenuItem10->Check( true ); }
            if ( resolutionString == wxT("1024 x 768") ) { MenuItem11->Check( true ); }
            if ( resolutionString == wxT("1152 x 864") ) { MenuItem12->Check( true ); }
            if ( resolutionString == wxT("1280 x 960") ) { MenuItem13->Check( true ); }
            if ( resolutionString == wxT("1400 x 1050") ) { MenuItem14->Check( true ); }
        }
    }

    PopupMenu(&PopupMenu1 );
}

void quickRDPFrame::OnMenuItem3Selected(wxCommandEvent& event)
{
    // popup properties choice
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }

        RDPFrame *newFrame = new RDPFrame( this, 0 );
        newFrame->loadRDPConnection( rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] ) );
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

void quickRDPFrame::OnMenuItem4Selected(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }

        if ( MenuItem4->IsChecked() == true ) {
            rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->setConsole( wxT("1") );
        } else {
            rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->setConsole( wxT("0") );
        }

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnTextCtrlClick(wxCommandEvent& event)
{
    TextCtrl1->SetSelection(-1,-1);
    TextCtrl1->SetFocus();
}

void quickRDPFrame::OnMenuItemDefaultClick(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("0") );
        curRDP->setDesktopHeight( wxT("0") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItemFullscreenClick(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("2") );
        curRDP->setDesktopWidth( wxT("0") );
        curRDP->setDesktopHeight( wxT("0") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem640(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("640") );
        curRDP->setDesktopHeight( wxT("480") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem800(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("800") );
        curRDP->setDesktopHeight( wxT("600") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1024(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("1024") );
        curRDP->setDesktopHeight( wxT("768") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1152(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("1152") );
        curRDP->setDesktopHeight( wxT("864") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1280(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("1280") );
        curRDP->setDesktopHeight( wxT("960") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1400(wxCommandEvent& event)
{
    // checkboxclick for console
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }
        RDPConnection *curRDP = rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] );
        curRDP->setScreenMode( wxT("1") );
        curRDP->setDesktopWidth( wxT("1400") );
        curRDP->setDesktopHeight( wxT("1050") );

        rdpDatabase->getRDPConnectionByPointer( ListCtrlRDPRelation[ itemIndex ] )->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnListCtrl1ColumnClick(wxListEvent& event)
{
    if ( last_column_click == event.GetColumn() ) {
        // change sort order.
        rdpDatabase->setSortOrder( !rdpDatabase->isSortOrderAscending() );
        rdpDatabase->sortById( event.GetColumn() );
    } else {
        last_column_click = event.GetColumn();
        rdpDatabase->setSortOrder( true );
        rdpDatabase->sortById( event.GetColumn() );
    }
    loadRDPFromDatabase();
}