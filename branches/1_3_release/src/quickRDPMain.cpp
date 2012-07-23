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

#include "quickRDPMain.h"
#include "RDPFrame.h"
#include "RDPDatabase.h"
#include "aboutDialog.h"
#include "settingsDialog.h"
#include "QuickrdpFunctions.h"
#include "Resources.h"
#include "CommandDialog.h"
#include "version.h"
#include "VersionChecker.h"
#include "ExampleDialog.h"
#include <wx/msgdlg.h>
#include <wx/imaglist.h>
#include <wx/image.h>
#include <memory>
#include <time.h>

//(*InternalHeaders(quickRDPFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(quickRDPFrame)
const long quickRDPFrame::ID_BITMAPBUTTON1 = wxNewId();
const long quickRDPFrame::ID_BITMAPBUTTON4 = wxNewId();
const long quickRDPFrame::ID_BITMAPBUTTON2 = wxNewId();
const long quickRDPFrame::ID_BITMAPBUTTON3 = wxNewId();
const long quickRDPFrame::ID_STATICTEXT1 = wxNewId();
const long quickRDPFrame::ID_TEXTCTRL1 = wxNewId();
const long quickRDPFrame::ID_LISTCTRL1 = wxNewId();
const long quickRDPFrame::ID_PANEL2 = wxNewId();
const long quickRDPFrame::ID_NOTEBOOK1 = wxNewId();
const long quickRDPFrame::ID_PANEL1 = wxNewId();
const long quickRDPFrame::idMenuCommands = wxNewId();
const long quickRDPFrame::idMenuPreferences = wxNewId();
const long quickRDPFrame::ID_MENUITEM2 = wxNewId();
const long quickRDPFrame::ID_MENUITEM3 = wxNewId();
const long quickRDPFrame::POPUPMENUCONNECT = wxNewId();
const long quickRDPFrame::ID_POPUPMENUPROPERTIES = wxNewId();
const long quickRDPFrame::ID_POPUPMENU_DUPLICATE = wxNewId();
const long quickRDPFrame::ID_POPUPMENU_DELETE = wxNewId();
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
const long quickRDPFrame::POPUPMENURDP = wxNewId();
//*)

BEGIN_EVENT_TABLE(quickRDPFrame,wxFrame)
    //(*EventTable(quickRDPFrame)
    //*)
    EVT_COMMAND(wxID_ANY, wxEVT_VERSION_CHECK_DONE, quickRDPFrame::onVersionCheckExecuted)
    EVT_COMMAND(wxID_ANY, wxEVT_AUTOMATIC_VERSION_CHECK_DONE, quickRDPFrame::onAutomaticVersionCheckExecuted)
    EVT_COMMAND(wxID_ANY, wxEVT_CONNECTION_CHECK_STATUS_UPDATE, quickRDPFrame::onConnectionCheckerUpdate)
    EVT_COMMAND(wxID_ANY, wxEVT_CONNECTION_CHECK_SEND_DATA, quickRDPFrame::onConnectionCheckerWantData)
END_EVENT_TABLE()

quickRDPFrame::quickRDPFrame(wxWindow* parent,wxWindowID WXUNUSED(id) )
{
    //(*Initialize(quickRDPFrame)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("quickRDP"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(172,202));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(182,217), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new QuickRDPBitmapButton(Panel1, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetToolTip(_("New connection"));
    BoxSizer5->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new QuickRDPBitmapButton(Panel1, ID_BITMAPBUTTON4, wxNullBitmap, wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->Disable();
    BitmapButton4->SetToolTip(_("Duplicate connection"));
    BoxSizer5->Add(BitmapButton4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new QuickRDPBitmapButton(Panel1, ID_BITMAPBUTTON2, wxNullBitmap, wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->Disable();
    BitmapButton2->SetToolTip(_("Delete connection"));
    BoxSizer5->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new QuickRDPBitmapButton(Panel1, ID_BITMAPBUTTON3, wxNullBitmap, wxDefaultPosition, wxSize(64,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->Disable();
    BitmapButton3->SetToolTip(_("View properties"));
    BoxSizer5->Add(BitmapButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer7->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VersionNotifyText = new wxStaticText(Panel1, ID_STATICTEXT1, _("New version available!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    VersionNotifyText->SetForegroundColour(wxColour(255,0,0));
    wxFont VersionNotifyTextFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !VersionNotifyTextFont.Ok() ) VersionNotifyTextFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    VersionNotifyTextFont.SetWeight(wxBOLD);
    VersionNotifyTextFont.SetUnderlined(true);
    VersionNotifyText->SetFont(VersionNotifyTextFont);
    BoxSizer7->Add(VersionNotifyText, 0, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 1, wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Search"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(172,27), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    StaticBoxSizer1->Add(TextCtrl1, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    BoxSizer4->Add(StaticBoxSizer1, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer4, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    BoxSizer3->Add(BoxSizer6, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("ID_NOTEBOOK1"));
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxWANTS_CHARS, _T("ID_PANEL2"));
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    ListCtrl1 = new wxListCtrl(Panel2, ID_LISTCTRL1, wxDefaultPosition, wxSize(566,278), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    ListCtrl1->InsertColumn( 0, wxT("Host") );
    ListCtrl1->InsertColumn( 1, wxT("Username") );
    ListCtrl1->InsertColumn( 2, wxT("Use console") );
    ListCtrl1->InsertColumn( 3, wxT("Resolution") );
    ListCtrl1->InsertColumn( 4, wxT("Comment") );
    BoxSizer8->Add(ListCtrl1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel2->SetSizer(BoxSizer8);
    BoxSizer8->Fit(Panel2);
    BoxSizer8->SetSizeHints(Panel2);
    Notebook1->AddPage(Panel2, wxEmptyString, false);
    BoxSizer2->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, wxID_EXIT, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem22 = new wxMenuItem(Menu3, idMenuCommands, _("Commands"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem22);
    Menu3->AppendSeparator();
    MenuItem15 = new wxMenuItem(Menu3, idMenuPreferences, _("Preferences"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem15);
    MenuBar1->Append(Menu3, _("&Settings"));
    Menu2 = new wxMenu();
    MenuItem18 = new wxMenuItem(Menu2, ID_MENUITEM2, _("Report a bug"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem18);
    Menu2->AppendSeparator();
    MenuItem23 = new wxMenuItem(Menu2, ID_MENUITEM3, _("Search for updates"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem23);
    Menu2->AppendSeparator();
    MenuItem2 = new wxMenuItem(Menu2, wxID_ABOUT, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    MenuItem17 = new wxMenuItem((&PopupMenu1), POPUPMENUCONNECT, _("Connect"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem17);
    MenuItem3 = new wxMenuItem((&PopupMenu1), ID_POPUPMENUPROPERTIES, _("Properties"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem3);
    MenuItem20 = new wxMenuItem((&PopupMenu1), ID_POPUPMENU_DUPLICATE, _("Duplicate"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem20);
    MenuItem21 = new wxMenuItem((&PopupMenu1), ID_POPUPMENU_DELETE, _("Delete\tDEL"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem21);
    PopupMenu1.AppendSeparator();
    MenuItem19 = new wxMenu();
    MenuItem4 = new wxMenuItem(MenuItem19, ID_POPUPMENUCONSOLE, _("Attach to console"), wxEmptyString, wxITEM_CHECK);
    MenuItem19->Append(MenuItem4);
    MenuItem19->AppendSeparator();
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
    MenuItem19->Append(ID_MENUITEM1, _("Resolution"), MenuItem5, wxEmptyString);
    PopupMenu1.Append(POPUPMENURDP, _("RDP"), MenuItem19, wxEmptyString);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnNewButtonClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDuplicateButtonClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDeleteButtonClick);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&quickRDPFrame::OnTextCtrlInput);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&quickRDPFrame::OnSearchTextEnter);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemDeselect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemActivated);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ItemRClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&quickRDPFrame::OnListCtrl1ColumnClick);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&quickRDPFrame::OnNotebook1PageChanged);
    Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnQuit);
    Connect(idMenuCommands,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuCommands);
    Connect(idMenuPreferences,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPreferences);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnReportBugClick);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuSearchForUpdates);
    Connect(wxID_ABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnAbout);
    Connect(POPUPMENUCONNECT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItemConnect);
    Connect(ID_POPUPMENUPROPERTIES,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem3Selected);
    Connect(ID_POPUPMENU_DUPLICATE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPopupMenuDuplicate);
    Connect(ID_POPUPMENU_DELETE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPopupMenuDelete);
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
    VersionNotifyText->Connect(ID_STATICTEXT1,wxEVT_LEFT_DOWN,(wxObjectEventFunction)&quickRDPFrame::OnNewVersionTextClick,0,this);

    commandMenu = new wxMenu();
    PopupMenu1.AppendSubMenu( commandMenu, wxT("Commands") );

    SetTitle( Version::getShortVersion() );

    /** set our button images **/
    BitmapButton1->SetBitmapLabel( wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("document-new.png") ) ) );
    BitmapButton2->SetBitmapLabel( wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("edit-delete.png") ) ) );
    BitmapButton2->SetBitmapDisabled(wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("edit-delete-disabled.png"))));
    BitmapButton3->SetBitmapLabel( wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("preferences-other.png") ) ) );
    BitmapButton3->SetBitmapDisabled(wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("preferences-other-disabled.png"))));
    BitmapButton4->SetBitmapLabel( wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("network-workgroup.png") ) ) );
    BitmapButton4->SetBitmapDisabled(wxBitmap( wxImage( Resources::Instance()->getSettings()->getDataPath() + wxT("network-workgroup-disabled.png"))));

    last_column_click = 0;

    loadRDPFromDatabase();
    loadFrameSettings();
    if ( wxFileExists( Resources::Instance()->getSettings()->getDataPath() + wxT("ChangeLog") ) ) {
        const long newMenuId = wxNewId();
        wxMenuItem *changelogDialogItem = new wxMenuItem( Menu2, newMenuId, wxT("View changelog"), wxT("View the changelog to see recent changes introduced to QuickRDP"), wxITEM_NORMAL);
        Menu2->Insert( 2, changelogDialogItem );
        Connect( newMenuId, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&quickRDPFrame::OnChangelogClick );
    }
    globalhotkeys = true;


    VersionNotifyText->Hide();

    updatePopupmenuShortcuts();

    /** init our image list **/
    imageList = new wxImageList( 16,16, true );
    #if defined(__UNIX__)
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionerror.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionok.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionunk.xpm") ) );
    #else
        imageList->Add( wxICON( connectionerror ) );
        imageList->Add( wxICON( connectionok ) );
        imageList->Add( wxICON( connectionunk ) );
    #endif
    ListCtrl1->SetImageList( imageList, wxIMAGE_LIST_SMALL );
}

quickRDPFrame::~quickRDPFrame()
{
    //(*Destroy(quickRDPFrame)
    //*)
    saveFrameSettings();
    delete imageList;
    Resources::DestroyInstance();
}

void quickRDPFrame::init()
{
    /** run stuff we can't run in our constructor here.. **/


    /** run a check of our current version and the saved version in the settings file..
        if these two differ then we check if we should notify our user of any dramatic changes.. **/
    wxString currentVersion = Version::getNumericVersion();
    wxString oldVersion = Resources::Instance()->getSettings()->getVersion();

    if ( ( currentVersion.empty() == false && oldVersion.empty() == false ) && ( currentVersion > oldVersion ) ) {
        checkForVersionChangesAndNotifyUser( oldVersion );
    }
}

void quickRDPFrame::OnQuit(wxCommandEvent& WXUNUSED(event) )
{
    Close();
}

void quickRDPFrame::OnAbout(wxCommandEvent& WXUNUSED(event) )
{
    aboutDialog *about = new aboutDialog( this, 0 );
    about->VersionText->SetLabel( Version::getLongVersion() );
    showDialog( about );
    delete about;
}

void quickRDPFrame::OnListCtrl1ItemSelect(wxListEvent& WXUNUSED(event) )
{
    BitmapButton2->Enable();
    BitmapButton3->Enable();
    BitmapButton4->Enable();
}

void quickRDPFrame::OnListCtrl1ItemDeselect(wxListEvent& WXUNUSED(event) )
{
    BitmapButton2->Disable();
    BitmapButton3->Disable();
    BitmapButton4->Disable();
}

void quickRDPFrame::OnNewButtonClick(wxCommandEvent& WXUNUSED(event) )
{
    wxString filename = quickRDP::FileParser::generateFilename();

    RDPFrame *newFrame = new RDPFrame( this, 0 );
    newFrame->loadRDPConnection( Resources::Instance()->getConnectionDatabase()->addRDPConnection( filename ) );
    showDialog( newFrame );
    loadRDPFromDatabase();
    delete newFrame;
    if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
        BitmapButton2->Disable();
        BitmapButton3->Disable();
        BitmapButton4->Disable();
    }
}

void quickRDPFrame::OnDeleteButtonClick(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );

    if ( curCon != NULL ) {
        if ( wxMessageBox( wxT("Are you sure you want to delete this connection?"), wxT("Delete this connection?"), wxOK | wxCANCEL ) == wxOK ) {
            Resources::Instance()->getConnectionDatabase()->deleteRDPConnectionByPointer( curCon );
            loadRDPFromDatabase();
            if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
                BitmapButton2->Disable();
                BitmapButton3->Disable();
                BitmapButton4->Disable();
            }
        }
    }
}

void quickRDPFrame::OnEditButtonClick(wxCommandEvent& WXUNUSED(event) , RDPConnection *editConnection)
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( editConnection != NULL ) { /** if we're using an connection as an argument (default is NULL) then we will use this connection instead of what's selected in our ListCtrl **/
        curCon = editConnection;
    }

    if ( curCon != NULL ) {
        RDPFrame *newFrame = new RDPFrame( this, 0 );
        newFrame->loadRDPConnection( curCon );
        showDialog( newFrame );
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
    Resources::Instance()->getConnectionDatabase()->clearRDPListCtrl();

    std::vector<RDPConnection*> database = Resources::Instance()->getConnectionDatabase()->getDatabase();
    long itemIndexCounter = 0;

    for ( size_t index = 0; index < database.size(); index++ ) {
        RDPConnection* curRDP = database[ index ];
        // if we have a filter in place, we search the RDPConnection and checks if any value matches our pattern. if it doesn't, we hop to the next item in the database.
        if ( curRDP->doesRDPHasString( Notebook1->GetPageText( Notebook1->GetSelection() ) ) == true ) {
            Resources::Instance()->getConnectionDatabase()->addRDPToListCtrl( curRDP );
            wxListItem item;
            item.SetId( index );
            ListCtrl1->InsertItem( item, curRDP->getConnectionStatus() );
            wxString username;
            if ( curRDP->getDomain().Len() > 0 && curRDP->getConnectionType() == ConnectionType::RDP ) {
                username.Append( curRDP->getDomain() + wxT("\\") );
            }
            username.Append( curRDP->getUsername() );
            ListCtrl1->SetItem( itemIndexCounter, 0, curRDP->getHostname() );
            ListCtrl1->SetItem( itemIndexCounter, 1, username );

            ListCtrl1->SetItem( itemIndexCounter, 2, ConnectionType::getConnectionTypeName( curRDP->getConnectionType() ) );

            if ( curRDP->getConsole() == wxT("1") ) {
                ListCtrl1->SetItem( itemIndexCounter, 3, wxT("Yes") );
            } else {
                ListCtrl1->SetItem( itemIndexCounter, 3, wxT("No" ) );
            }

            if ( curRDP->getScreenMode() == wxT("2") ) {
                ListCtrl1->SetItem( itemIndexCounter, 4, wxT("Fullscreen") );
            } else if ( curRDP->getDesktopHeight() == wxT("0") && curRDP->getDesktopWidth() == wxT("0") ) {
                ListCtrl1->SetItem( itemIndexCounter, 4, wxT("Default") );
            } else {
                ListCtrl1->SetItem( itemIndexCounter, 4, curRDP->getDesktopWidth() + wxT(" x ") + curRDP->getDesktopHeight() );
            }

            ListCtrl1->SetItem( itemIndexCounter, 5, curRDP->getComment() );
            itemIndexCounter++;
        }
    }

    /** also update the connection status of the visible items in listctrl **/
    /** also skipping it here.. updateConnectionCheckerStatus(); **/
}

void quickRDPFrame::clearListCtrl()
{
    /** save the column with that we use before clearing the list **/
    int columnWidth[6];
    for ( int colId = 0; colId < 6; ++colId ) {
        columnWidth[ colId ] = ListCtrl1->GetColumnWidth( colId );
    }

    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("Host") );
    ListCtrl1->InsertColumn( 1, wxT("Username") );
    ListCtrl1->InsertColumn( 2, wxT("Connection") );
    ListCtrl1->InsertColumn( 3, wxT("Use console") );
    ListCtrl1->InsertColumn( 4, wxT("Resolution") );
    ListCtrl1->InsertColumn( 5, wxT("Comment") );

    /** restore the column width **/
    for ( int colId = 0; colId < 6; ++colId ) {
        ListCtrl1->SetColumnWidth( colId, columnWidth[ colId ] );
    }

}

void quickRDPFrame::OnListCtrl1ItemActivated(wxListEvent& WXUNUSED(event) )
{
    execute_connections();
}

void quickRDPFrame::OnDuplicateButtonClick(wxCommandEvent& event)
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        wxString filename = quickRDP::FileParser::generateFilename();
        RDPConnection *myNewCon = Resources::Instance()->getConnectionDatabase()->duplicateRDPConnection( filename, curCon );
        OnEditButtonClick( event, myNewCon );
    }
}

void quickRDPFrame::OnSearchTextEnter(wxCommandEvent& WXUNUSED(event) )
{
    /** first delselect all items in the list control... **/
    long item = -1;
    for (;;) {
        item = ListCtrl1->GetNextItem( item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( item == -1 ) {
            break;
        }
        ListCtrl1->SetItemState( item, 0, wxLIST_STATE_SELECTED );
    }

    /** now select our top one **/
    if ( ListCtrl1->GetItemCount() > 0 ) {
        ListCtrl1->SetItemState(ListCtrl1->GetTopItem(),wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
        ListCtrl1->SetFocus();
    }
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

void quickRDPFrame::OnListCtrl1ItemRClick(wxListEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    /** prepare our RDP menu with checkboxes for console mode and resolutions **/
    if ( curCon != NULL ) {
        clearPopupMenuChoices();
        if ( curCon->getConsole() == wxT("1") )
        {
            MenuItem4->Check( true );
        }

        if ( curCon->getScreenMode() == wxT("2") ) {
            MenuItem7->Check( true );
        } else if ( curCon->getScreenMode() == wxT("1") && curCon->getDesktopHeight() == wxT("0") && curCon->getDesktopWidth() == wxT("0") ) {
            MenuItem6->Check( true );
        } else {
            wxString resolutionString = curCon->getDesktopWidth() + wxT(" x ") + curCon->getDesktopHeight();
            if ( resolutionString == wxT("640 x 480") ) { MenuItem9->Check( true ); }
            if ( resolutionString == wxT("800 x 600") ) { MenuItem10->Check( true ); }
            if ( resolutionString == wxT("1024 x 768") ) { MenuItem11->Check( true ); }
            if ( resolutionString == wxT("1152 x 864") ) { MenuItem12->Check( true ); }
            if ( resolutionString == wxT("1280 x 960") ) { MenuItem13->Check( true ); }
            if ( resolutionString == wxT("1400 x 1050") ) { MenuItem14->Check( true ); }
        }
    }

    /** prepare our command part of the popup menu before we display it. **/
    // erase all items in the submenu.
    wxMenuItemList commandMenuList = commandMenu->GetMenuItems();
    for ( wxMenuItemList::iterator it = commandMenuList.begin(); it != commandMenuList.end(); ++it ) {
        commandMenu->Destroy( (*it)->GetId() );
    }
    /** also clear and destroy all items in the favorite command menu vector **/
    for ( std::vector< wxMenuItem* >::iterator it = favoriteCommandMenuItems.begin(); it != favoriteCommandMenuItems.end(); ++it ) {
        PopupMenu1.Destroy( (*it)->GetId() );
    }
    favoriteCommandMenuItems.clear();

    // add all commands to the menu from the command database
    std::vector< Command* > commandDb = Resources::Instance()->getCommandDatabase()->getCommands();
    for ( size_t cId = 0; cId < commandDb.size(); ++cId ) {
        const long newCommandId = wxNewId();
        Connect( newCommandId, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&quickRDPFrame::OnCommandSelected );
        wxString commandName = commandDb[ cId ]->getName();
        if ( commandDb[ cId ]->getShortcutKey() > 0 ) {
            commandName << wxT("\t") << quickRDP::Keybinder::ModifierString( commandDb[ cId ]->getShortcutModifier() ) << quickRDP::Keybinder::KeycodeString( commandDb[ cId ]->getShortcutKey() );
        }
        wxMenuItem *newCommandMenuItem = new wxMenuItem( commandMenu, newCommandId, commandName, wxEmptyString, wxITEM_NORMAL );

        /** if we have favorite commands, insert them before the "RDP" submenu **/
        if ( commandDb[ cId ]->getFavorite() == true ) {
            PopupMenu1.Insert( 5, newCommandMenuItem );
            /** we also need to add the reference to all favorite commands we create so that we can destroy them once we reload the popup menu **/
            favoriteCommandMenuItems.push_back( newCommandMenuItem );
        } else { /** otherwise just add them to the command submenu **/
            commandMenu->Append( newCommandMenuItem );
        }
    }

    /** insert a seperator if we added any favorite commands **/
    if ( favoriteCommandMenuItems.size() > 0 ) {
        wxMenuItem *separator = PopupMenu1.InsertSeparator( favoriteCommandMenuItems.size() + 5 );
        favoriteCommandMenuItems.push_back( separator );
    }


    /** and append our command submenu as well **/
    if ( commandMenu->GetMenuItemCount() <= 0 ) {
        wxMenuItem *newCommandMenuItem = new wxMenuItem( commandMenu, wxID_ANY, wxT("-- no commands in database --") );
        newCommandMenuItem->Enable( false );
        commandMenu->Append( newCommandMenuItem );
    }

    PopupMenu(&PopupMenu1 );
}

void quickRDPFrame::OnMenuItem3Selected(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    // popup properties choice
    if ( curCon != NULL ) {
        RDPFrame *newFrame = new RDPFrame( this, 0 );
        newFrame->loadRDPConnection( curCon );
        showDialog( newFrame );

        loadRDPFromDatabase();
        delete newFrame;
        if ( ListCtrl1->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}

void quickRDPFrame::OnMenuItem4Selected(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        long itemIndex = -1;
        itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }

        if ( MenuItem4->IsChecked() == true ) {
            curCon->setConsole( wxT("1") );
        } else {
            curCon->setConsole( wxT("0") );
        }

        curCon->saveFile();

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
    /** clicking in the box will select all text unless all text was already selected **/
    if ( TextCtrl1->GetStringSelection().empty() == true ) {
        TextCtrl1->SetSelection(-1,-1);
        TextCtrl1->SetFocus();
    } else {
        event.Skip();
    }
}

void quickRDPFrame::OnMenuItemDefaultClick(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("0") );
        curCon->setDesktopHeight( wxT("0") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItemFullscreenClick(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("2") );
        curCon->setDesktopWidth( wxT("0") );
        curCon->setDesktopHeight( wxT("0") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem640(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("640") );
        curCon->setDesktopHeight( wxT("480") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem800(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("800") );
        curCon->setDesktopHeight( wxT("600") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1024(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("1024") );
        curCon->setDesktopHeight( wxT("768") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1152(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("1152") );
        curCon->setDesktopHeight( wxT("864") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1280(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("1280") );
        curCon->setDesktopHeight( wxT("960") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnMenuItem1400(wxCommandEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( ListCtrl1 );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("1400") );
        curCon->setDesktopHeight( wxT("1050") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnListCtrl1ColumnClick(wxListEvent& event)
{
    RDPDatabase *rdpDatabase = Resources::Instance()->getConnectionDatabase();
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

void quickRDPFrame::OnPreferences(wxCommandEvent& WXUNUSED(event) )
{
    settingsDialog *settings = new settingsDialog( this, 0 );
    showDialog( settings );
    delete settings;
    updatePopupmenuShortcuts();
}

void quickRDPFrame::OnCommandSelected(wxCommandEvent& event)
{
    bool doneSafetyCheck = false;
    wxMenuItem *usedMenuItem = PopupMenu1.FindItem( event.GetId() );
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( ListCtrl1 );
    for ( size_t con = 0; con < connections.size(); ++con ) {
        Command* executeCommand = Resources::Instance()->getCommandDatabase()->getCommand( usedMenuItem->GetLabel() );
        if ( executeCommand != NULL ) {
            if ( executeCommand->getSafety() == true && doneSafetyCheck == false ) {
                if ( wxMessageBox( wxT("Do you want to run the command ") + executeCommand->getName() + wxT("?"), wxT("Run command?"), wxOK | wxCANCEL ) != wxOK ) {
                    break;
                } else {
                    doneSafetyCheck = true;
                }
            }
        }

        if ( executeCommand != NULL && connections[ con ] != NULL ) {
            executeCommand->execute( connections[ con ] );
        } else {
            wxMessageBox( wxT("Command or connection not found!"), wxT("Error"), wxICON_ERROR );
        }
    }
}

void quickRDPFrame::OnMenuItemConnect(wxCommandEvent& WXUNUSED(event) )
{
    execute_connections();
}

void quickRDPFrame::execute_connections()
{
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( ListCtrl1 );
    for ( size_t con = 0; con < connections.size(); ++con ) {
        if ( connections[ con ] != NULL ) {
            connections[ con ]->connect();
        }
    }
}

void quickRDPFrame::saveFrameSettings()
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        settings->setMainFrameHeight( GetSize().GetHeight() );
        settings->setMainFrameWidth( GetSize().GetWidth() );
        settings->setColumn0Width( ListCtrl1->GetColumnWidth( 0 ) );
        settings->setColumn1Width( ListCtrl1->GetColumnWidth( 1 ) );
        settings->setColumn2Width( ListCtrl1->GetColumnWidth( 2 ) );
        settings->setColumn3Width( ListCtrl1->GetColumnWidth( 3 ) );
        settings->setColumn4Width( ListCtrl1->GetColumnWidth( 4 ) );
        settings->setColumn5Width( ListCtrl1->GetColumnWidth( 5 ) );
        settings->saveSettings();
    }
}

void quickRDPFrame::loadFrameSettings()
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        /** frames size **/
        SetSize( wxDefaultCoord, wxDefaultCoord, settings->getMainFrameWidth(), settings->getMainFrameHeight() );

        /** column widths **/
        ListCtrl1->SetColumnWidth( 0, settings->getColumn0Width() );
        ListCtrl1->SetColumnWidth( 1, settings->getColumn1Width() );
        ListCtrl1->SetColumnWidth( 2, settings->getColumn2Width() );
        ListCtrl1->SetColumnWidth( 3, settings->getColumn3Width() );
        ListCtrl1->SetColumnWidth( 4, settings->getColumn4Width() );
        ListCtrl1->SetColumnWidth( 5, settings->getColumn5Width() );
    }
}

void quickRDPFrame::OnPopupMenuDuplicate(wxCommandEvent& event)
{
    OnDuplicateButtonClick( event );
}

void quickRDPFrame::OnPopupMenuDelete(wxCommandEvent& event)
{
    OnDeleteButtonClick( event );
}

void quickRDPFrame::OnMenuCommands(wxCommandEvent& WXUNUSED(event) )
{
    CommandDialog *commandDlg = new CommandDialog( this, 0 );
    showDialog( commandDlg );
    delete commandDlg;
}

void quickRDPFrame::OnReportBugClick(wxCommandEvent& WXUNUSED(event) )
{
    wxLaunchDefaultBrowser( wxT("http://www.0x134.net/redmine/projects/quickrdp/issues/new") );
}

void quickRDPFrame::OnMenuSearchForUpdates(wxCommandEvent& WXUNUSED(event) )
{
    VersionChecker *versionCheck = new VersionChecker( this, "http://sourceforge.net/projects/quickrdp/files/quickRDP/", false );
    if ( versionCheck->Create() != wxTHREAD_NO_ERROR ) {
        delete versionCheck;
        versionCheck = NULL;
        wxMessageBox( wxT("Error while creating HTTP thread!") );
    } else {
        if ( versionCheck->Run() != wxTHREAD_NO_ERROR ) {
            delete versionCheck;
            versionCheck = NULL;
            wxMessageBox( wxT("Error while running HTTP thread!") );
        }
    }
}

void quickRDPFrame::onVersionCheckExecuted( wxCommandEvent &event )
{
    /** event handler for when we're checking for a new version manually **/
    if ( event.GetInt() == 1 ) {
        if ( wxMessageBox( wxT("Version ") + event.GetString() + wxT(" is available for download. Do you want to download it now?"), wxT("New version available"), wxYES_NO ) == wxYES ) {
            wxLaunchDefaultBrowser( wxT("http://sourceforge.net/projects/quickrdp/files/quickRDP/") );
        }
    } else {
        wxMessageBox( wxT("You already got the latest version of QuickRDP.") );
    }
}

void quickRDPFrame::onAutomaticVersionCheckExecuted( wxCommandEvent &event )
{
    /** event handler for when we're checking for a new version automatically (during startup) **/
    if ( event.GetInt() == 1 ) {
        VersionNotifyText->Show( true );
        VersionNotifyText->SetToolTip( wxT("Version ") + event.GetString() + wxT(" is available for download.") );
    }
}

void quickRDPFrame::OnChangelogClick( wxCommandEvent& WXUNUSED(event)  )
{
    wxString filename = Resources::Instance()->getSettings()->getDataPath() + wxT("ChangeLog");
    if ( wxFileExists( filename ) == true ) {
        std::ifstream rfile;

        rfile.open( filename.mb_str(), std::ios::in|std::ios::binary );

        rfile.seekg (0, std::ios::end);
        int length = rfile.tellg();
        rfile.seekg (0, std::ios::beg);

        std::string inputData;

        if (length > 0) {
            char *buffer;
            buffer = new char [length];
            wxString strline;
            while ( getline(rfile,inputData) ) {
                wxString input( inputData.c_str(), wxConvUTF8 );
                strline.append( input + wxT("\n") );
            }
            delete[] buffer;

            ExampleDialog *changelogDlg = new ExampleDialog( strline, this );
            showDialog( changelogDlg );
            delete changelogDlg;
        }
    }
}

bool quickRDPFrame::handleShortcutKeys( wxKeyEvent &event )
{
    /** TODO: We need to remake this shortcut handling.
        Best way I see it is that we have a shortcut handler in our resource singleton.
        Iterate through that first.
        After it is done and we're still in this function then we can go ahead and loop through
        all the command's shortcuts as well.
    **/

    if ( wantGlobalHotkeys() == true ) {
        /** check if we matches any of our "non-connection" shortcuts **/
        if ( event.GetKeyCode() == 84 &&  event.GetModifiers() == wxMOD_CONTROL ) {
            Notebook1->AddPage(Panel2, wxT(""), true );
            return true;
        } else if ( event.GetKeyCode() == 87 && event.GetModifiers() == wxMOD_CONTROL ) {
            if ( Notebook1->GetPageCount() > 1 ) {
                Notebook1->RemovePage( Notebook1->GetSelection() );
            }
            return true;
        } else if ( event.GetKeyCode() == WXK_TAB && event.GetModifiers() == wxMOD_NONE ) {
            if ( wxWindow::FindFocus()->GetId() == ID_TEXTCTRL1 ) {
                ListCtrl1->SetFocus();
            } else {
                TextCtrl1->SetFocus();
            }
            return true;
        /** Okay, now we only check our connection only shortcuts.. (ListCtrl is in focus) **/
        } else if ( wxWindow::FindFocus()->GetId() == ID_LISTCTRL1 ) {
            /** first we look for commands that have this specific keycombination and try to execute it **/
            std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( ListCtrl1 );
            Command* curCommand = Resources::Instance()->getCommandDatabase()->getCommandWithShortcut( event.GetModifiers(), event.GetKeyCode() );
            if ( curCommand != NULL ) {
                for ( size_t con = 0; con < connections.size(); ++con ) {
                    if ( connections[ con ] != NULL ) {
                        curCommand->execute( connections[ con ] );
                    }
                }
                return true;
            } else {
                /** no comand found, then we look for global shortcuts... **/
                wxCommandEvent ourEvent;
                Settings *settings = Resources::Instance()->getSettings();
                int keyCode = event.GetKeyCode();
                int keyModifier = event.GetModifiers();

                if ( keyCode == settings->getNewConnectionShortcut().first && keyModifier == settings->getNewConnectionShortcut().second ) {
                    OnNewButtonClick( ourEvent );
                    return true;
                } else if ( keyCode == settings->getDupConnectionShortcut().first && keyModifier == settings->getDupConnectionShortcut().second ) {
                    OnDuplicateButtonClick( ourEvent );
                    return true;
                } else if ( keyCode == settings->getPropConnectionShortcut().first && keyModifier == settings->getPropConnectionShortcut().second ) {
                    OnEditButtonClick( ourEvent );
                    return true;
                } else if ( keyCode == settings->getCommandDialogShortcut().first && keyModifier == settings->getCommandDialogShortcut().second ) {
                    OnMenuCommands( ourEvent );
                    return true;
                } else if ( keyCode == settings->getManualCCShortcut().first && keyModifier == settings->getManualCCShortcut().second ) {
                    manuallyDoConnectionCheck( connections );
                    return true;
                } else if ( keyCode == 127 ) {
                    OnDeleteButtonClick( ourEvent );
                    return true;
                }
            }
        }
    }
    return false;
}

bool quickRDPFrame::wantGlobalHotkeys() const
{
    return globalhotkeys;
}

void quickRDPFrame::showDialog( wxDialog* dialog )
{
    globalhotkeys = false;
    dialog->ShowModal();
    globalhotkeys = true;
}

void quickRDPFrame::checkForVersionChangesAndNotifyUser( wxString oldVersion )
{
    /** all logic here is strictly static for now.. we'll see how we handle this in the future (perhaps there won't be too many of these drastic changes).. **/

    Settings *settings = Resources::Instance()->getSettings();
    /** Since 1.2.1 we implemented global hotkeys.. Users may want to remove these.
    but we should allow new users upgrading to 1.2.1 to have the default old ones.
    Setting them here if we're starting 1.2.1 for the first time now. **/
    if ( oldVersion < wxT("1.2.1") ) {
        settings->setDupConnectionShortcut( std::make_pair( 68, wxMOD_CONTROL ) ); /** Ctrl+D **/
        settings->setPropConnectionShortcut( std::make_pair( 80, wxMOD_CONTROL ) ); /** Ctrl+P **/
    }

    /** with the new connection checker in 1.3 we want to enable automatic checks it by default.. by setting it here **/
    if ( oldVersion < wxT("1.3") ) {
        settings->setCCAutomaticCheck( 1 );
        settings->setNewTabShortcut( std::make_pair( 84, wxMOD_CONTROL ) );
        settings->setCloseTabShortcut( std::make_pair( 87, wxMOD_CONTROL ) );
        wxMessageBox( wxT("Starting in QuickRDP 1.3 you can now open new connection tabs with Ctrl+T and close the current one with Ctrl+W. Go into options if you like to change these keybindings."), wxT("New features in 1.3"), wxICON_INFORMATION );
    }

    /** save our settings just in case the application fails to do so at a later stage..
    we don't want the user to get these messages twice. **/
    settings->saveSettings();
}

void quickRDPFrame::OnTextCtrlInput(wxCommandEvent& WXUNUSED(event) )
{
    Notebook1->SetPageText( Notebook1->GetSelection(), TextCtrl1->GetValue() );
    loadRDPFromDatabase();
}

void quickRDPFrame::checkForNewAvailableVersion( )
{
    VersionChecker *versionCheck = new VersionChecker( this, "http://sourceforge.net/projects/quickrdp/files/quickRDP/" );
    if ( versionCheck->Create() != wxTHREAD_NO_ERROR ) {
        delete versionCheck;
        versionCheck = NULL;
        wxMessageBox( wxT("Error while creating HTTP thread!") );
    } else {
        if ( versionCheck->Run() != wxTHREAD_NO_ERROR ) {
            delete versionCheck;
            versionCheck = NULL;
            wxMessageBox( wxT("Error while running HTTP thread!") );
        }
    }
}

void quickRDPFrame::OnNewVersionTextClick(wxCommandEvent& WXUNUSED(event) )
{
    wxLaunchDefaultBrowser( wxT("http://sourceforge.net/projects/quickrdp/files/quickRDP/") );
}

void quickRDPFrame::onConnectionCheckerUpdate( wxCommandEvent& event )
{
    /** Handles the events that comes from the connection checker thread.
    These events contains information about what status different connections has.
    Here we will just update our wxListCtrl and also the RDPConnection's connection status.
    **/

    RDPDatabase *rdpDatabase = Resources::Instance()->getConnectionDatabase();
    long itemIndex = rdpDatabase->getListCtrlIndexFromFilename( event.GetString() );

    if ( itemIndex != -1 ) {
        RDPConnection *rdpConnection = rdpDatabase->getRDPFromListCtrl( itemIndex );
        if ( rdpConnection != NULL ) {
            time_t seconds;
            seconds = time (NULL);
            rdpConnection->setLastChecked( seconds );
            if ( rdpConnection->getConnectionStatus() != event.GetInt() ) {
                rdpConnection->setConnectionStatus( event.GetInt() );
                ListCtrl1->SetItemImage( itemIndex, event.GetInt() );
            }
        }
    }
}

void quickRDPFrame::onConnectionCheckerWantData( wxCommandEvent& WXUNUSED(event) )
{
    updateConnectionCheckerStatus();
}

void quickRDPFrame::updatePopupmenuShortcuts()
{
    Settings *settings = Resources::Instance()->getSettings();
    wxMenuItem *propConMenu = PopupMenu1.FindItem( ID_POPUPMENUPROPERTIES );
    if ( propConMenu != NULL ) {
        propConMenu->SetText( wxT("Properties\t") + quickRDP::Keybinder::ModifierString( settings->getPropConnectionShortcut().second ) + quickRDP::Keybinder::KeycodeString( settings->getPropConnectionShortcut().first ) );
    }

    wxMenuItem *dupConMenu = PopupMenu1.FindItem( ID_POPUPMENU_DUPLICATE );
    if ( dupConMenu != NULL ) {
        dupConMenu->SetText( wxT("Duplicate\t") + quickRDP::Keybinder::ModifierString( settings->getDupConnectionShortcut().second ) + quickRDP::Keybinder::KeycodeString( settings->getDupConnectionShortcut().first ) );
    }
}

void quickRDPFrame::updateConnectionCheckerStatus()
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( settings->getCCAutomaticCheck() == 1 ) {
        time_t seconds;
        seconds = time (NULL);
        RDPConnection *rdpConnection = NULL;
        ConnectionChecker *connectionChecker = Resources::Instance()->getConnectionChecker();
        /** when we grab our RDP database (by searches and so on) we want to load new connections to our connection checker **/
        for ( long id = ListCtrl1->GetTopItem(); id < ListCtrl1->GetCountPerPage() + ListCtrl1->GetTopItem()+1; ++id  ) {
            rdpConnection = Resources::Instance()->getConnectionDatabase()->getRDPFromListCtrl( id );
            if ( rdpConnection != NULL && connectionChecker != NULL ) {
                /** make sure we update only targets who needs to be updated **/
                if ( seconds - rdpConnection->getLastChecked() > settings->getCCUpdateInterval() ) {
                    connectionChecker->addTargets( rdpConnection->getHostname(), rdpConnection->getPort(), rdpConnection->getFilename() );
                }
            }
        }
    }
}

void quickRDPFrame::manuallyDoConnectionCheck( std::vector< RDPConnection* > connections )
{
    ConnectionChecker *connectionChecker = Resources::Instance()->getConnectionChecker();
    if ( connectionChecker != NULL ) {
        for ( std::vector< RDPConnection* >::const_iterator it = connections.begin(); it != connections.end(); ++it ) {
            connectionChecker->addTargets( (*it)->getHostname(), (*it)->getPort(), (*it)->getFilename() );
        }
    }
}

void quickRDPFrame::OnNotebook1PageChanged(wxNotebookEvent& WXUNUSED(event) )
{
    loadRDPFromDatabase();
    TextCtrl1->ChangeValue( Notebook1->GetPageText( Notebook1->GetSelection() ) );
    ListCtrl1->SetFocus();
}