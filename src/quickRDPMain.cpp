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

#include "quickRDPMain.h"
#include "RDPFrame.h"
#include "RDPDatabase.h"
#include "aboutDialog.h"
#include "settingsDialog.h"
#include "NetworkScanner.h"
#include "IPCalculator.h"
#include "QuickrdpFunctions.h"
#include "Resources.h"
#include "version.h"
#include "VersionChecker.h"
#include "ExampleDialog.h"
#include <wx/msgdlg.h>
#include <wx/imaglist.h>
#include <wx/image.h>
#include <memory>
#include <time.h>
#include "ConnectionList.h"
#include "CommandList.h"

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
const long quickRDPFrame::ID_NOTEBOOK1 = wxNewId();
const long quickRDPFrame::ID_PANEL1 = wxNewId();
const long quickRDPFrame::idMenuNetworkScanner = wxNewId();
const long quickRDPFrame::idIPCalculator = wxNewId();
const long quickRDPFrame::idMenuCommands = wxNewId();
const long quickRDPFrame::idMenuPreferences = wxNewId();
const long quickRDPFrame::ID_MENUITEM2 = wxNewId();
const long quickRDPFrame::ID_MENUITEM3 = wxNewId();
const long quickRDPFrame::POPUPMENUCONNECT = wxNewId();
const long quickRDPFrame::ID_POPUPMENUCONNECTWHENREADY = wxNewId();
const long quickRDPFrame::ID_POPUPMENUPROPERTIES = wxNewId();
const long quickRDPFrame::ID_POPUPMENU_DUPLICATE = wxNewId();
const long quickRDPFrame::ID_POPUPMENU_DELETE = wxNewId();
const long quickRDPFrame::ID_POPUPMENUMANUALCC = wxNewId();
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
const long quickRDPFrame::ID_STATUSBAR1 = wxNewId();
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
    Menu4 = new wxMenu();
    MenuItem24 = new wxMenuItem(Menu4, idMenuNetworkScanner, _("&Network scanner"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem24);
    MenuItem26 = new wxMenuItem(Menu4, idIPCalculator, _("&IP Calculator"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem26);
    MenuBar1->Append(Menu4, _("&Tools"));
    Menu3 = new wxMenu();
    MenuItem22 = new wxMenuItem(Menu3, idMenuCommands, _("&Commands"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem22);
    Menu3->AppendSeparator();
    MenuItem15 = new wxMenuItem(Menu3, idMenuPreferences, _("&Preferences"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem15);
    MenuBar1->Append(Menu3, _("&Settings"));
    Menu2 = new wxMenu();
    MenuItem18 = new wxMenuItem(Menu2, ID_MENUITEM2, _("&Report a bug"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem18);
    Menu2->AppendSeparator();
    MenuItem23 = new wxMenuItem(Menu2, ID_MENUITEM3, _("&Search for updates"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem23);
    Menu2->AppendSeparator();
    MenuItem2 = new wxMenuItem(Menu2, wxID_ABOUT, _("&About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("&Help"));
    SetMenuBar(MenuBar1);
    MenuItem17 = new wxMenuItem((&PopupMenu1), POPUPMENUCONNECT, _("Connect"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem17);
    MenuItem25 = new wxMenuItem((&PopupMenu1), ID_POPUPMENUCONNECTWHENREADY, _("Connect when ready"), wxEmptyString, wxITEM_CHECK);
    PopupMenu1.Append(MenuItem25);
    MenuItem3 = new wxMenuItem((&PopupMenu1), ID_POPUPMENUPROPERTIES, _("Properties"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem3);
    MenuItem20 = new wxMenuItem((&PopupMenu1), ID_POPUPMENU_DUPLICATE, _("Duplicate"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem20);
    MenuItem21 = new wxMenuItem((&PopupMenu1), ID_POPUPMENU_DELETE, _("Delete\tDEL"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem21);
    MenuItem16 = new wxMenuItem((&PopupMenu1), ID_POPUPMENUMANUALCC, _("Connection check"), wxEmptyString, wxITEM_NORMAL);
    PopupMenu1.Append(MenuItem16);
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
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { 1, -50 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnNewButtonClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDuplicateButtonClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnDeleteButtonClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&quickRDPFrame::OnEditButtonBitmapClick);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&quickRDPFrame::OnTextCtrlInput);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&quickRDPFrame::OnSearchTextEnter);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&quickRDPFrame::OnNotebook1PageChanged);
    Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnQuit);
    Connect(idMenuNetworkScanner,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuNetworkScanner);
    Connect(idIPCalculator,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnIPCalculator);
    Connect(idMenuCommands,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuCommands);
    Connect(idMenuPreferences,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPreferences);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnReportBugClick);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuSearchForUpdates);
    Connect(wxID_ABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnAbout);
    Connect(POPUPMENUCONNECT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItemConnect);
    Connect(ID_POPUPMENUCONNECTWHENREADY,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItemConnectWhenReady);
    Connect(ID_POPUPMENUPROPERTIES,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnMenuItem3Selected);
    Connect(ID_POPUPMENU_DUPLICATE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPopupMenuDuplicate);
    Connect(ID_POPUPMENU_DELETE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPopupMenuDelete);
    Connect(ID_POPUPMENUMANUALCC,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&quickRDPFrame::OnPopupMenuManualCC);
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

    /** init our image list **/
    imageList = new wxImageList( 16,16, true );
    #if defined(__UNIX__)
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionerror.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionok.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionunk.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionchecker.xpm") ) );
    #else
        imageList->Add( wxICON( connectionerror ) );
        imageList->Add( wxICON( connectionok ) );
        imageList->Add( wxICON( connectionunk ) );
        imageList->Add( wxICON( connectionchecker ) );
    #endif

    loadConnectionTabs(); // Load our saved connection tabs. Will at least add one connection tab if we would have no connection tabs saved in our settings file.

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
}

quickRDPFrame::~quickRDPFrame()
{
    //(*Destroy(quickRDPFrame)
    //*)
    saveConnectionTabs();
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

    if ( ( currentVersion.empty() == false ) && ( currentVersion > oldVersion ) ) {
        checkForVersionChangesAndNotifyUser( oldVersion );
        loadRDPFromDatabase();
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
    about->gccVersion= Version::getgccVersion();
    about->libcurlVersion = Version::getlibcurlVersion();
    about->wxWidgetsVersion = Version::getwxWidgetsVersion();
    showDialog( about );
    delete about;
}

void quickRDPFrame::OnNewButtonClick(wxCommandEvent& WXUNUSED(event) )
{
    wxString filename = quickRDP::Generators::generateHex( 8 );

    RDPFrame *newFrame = new RDPFrame( this, 0 );
    newFrame->loadRDPConnection( Resources::Instance()->getConnectionDatabase()->addRDPConnection( filename ) );
    if ( showDialog( newFrame ) != wxCANCEL ) {
        loadRDPFromDatabase(); /** only reload database if we saved anything.. (clicked save in this dialog ) **/
    }
    delete newFrame;
    if ( getConnectionList()->GetSelectedItemCount() <= 0 ) {
        BitmapButton2->Disable();
        BitmapButton3->Disable();
        BitmapButton4->Disable();
    }
}

void quickRDPFrame::OnDeleteButtonClick(wxCommandEvent& WXUNUSED(event) )
{
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() );

    if ( wxMessageBox( wxT("Are you sure you want to delete the selected connection(s)?"), wxT("Delete connection(s)?"), wxOK | wxCANCEL ) == wxOK ) {
        for ( std::vector< RDPConnection* >::iterator it = connections.begin(); it != connections.end(); ++it ) {
            Resources::Instance()->getConnectionDatabase()->deleteRDPConnectionByPointer( (*it) );
        }
        loadRDPFromDatabase();
        if ( getConnectionList()->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}

void quickRDPFrame::OnEditButtonClick(wxCommandEvent& WXUNUSED(event) , RDPConnection *editConnection)
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
    if ( editConnection != NULL ) { /** if we're using an connection as an argument (default is NULL) then we will use this connection instead of what's selected in our ListCtrl **/
        curCon = editConnection;
    }

    if ( curCon != NULL ) {
        RDPFrame *newFrame = new RDPFrame( this, 0 );
        newFrame->loadRDPConnection( curCon );
        if ( showDialog( newFrame ) != wxCANCEL ) {
            loadRDPFromDatabase(); /** only reload database if we changed anything.. (clicked save in this dialog ) **/
        }
        delete newFrame;
        if ( getConnectionList()->GetSelectedItemCount() <= 0 ) {
            BitmapButton2->Disable();
            BitmapButton3->Disable();
            BitmapButton4->Disable();
        }
    }
}

void quickRDPFrame::loadRDPFromDatabase()
{
    Resources::Instance()->getConnectionDatabase()->clearRDPListCtrl();
    Settings *settings = Resources::Instance()->getSettings();
    wxListCtrl *listCtrl = getConnectionList();
    listCtrl->Freeze();
    clearListCtrl();

    std::vector< RDPConnection* > database;
    wxString searchString = Notebook1->GetPageText( Notebook1->GetSelection() );
    if ( searchString.IsEmpty() == true ) {
        database = Resources::Instance()->getConnectionDatabase()->getDatabase();
    } else {
        database = Resources::Instance()->getConnectionDatabase()->getDatabaseWithFilter( searchString );
    }
    long itemIndexCounter = 0;
    bool use_grey_color = false;

    // Freeze our listCtrl until we've added all connections.

    for ( size_t index = 0; index < database.size(); index++ ) {
        RDPConnection* curRDP = database[ index ];
        Resources::Instance()->getConnectionDatabase()->addRDPToListCtrl( curRDP );
        int columnCounter = 0;
        wxListItem item;
        item.SetId( index );
        if ( curRDP->getConnectWhenReady() == true ) {
            listCtrl->InsertItem( item, 3 );
        } else {
            listCtrl->InsertItem( item, curRDP->getConnectionStatus() );
        }

        listCtrl->SetItem( itemIndexCounter, columnCounter, curRDP->getHostname() );
        wxColour itembgcolour;
        if ( use_grey_color == true && settings->getGreyListBackground() == true ) {
            itembgcolour = wxColour( 240, 240, 240 );
            use_grey_color = false;
        } else {
            itembgcolour = wxColour( 255, 255, 255 );
            use_grey_color = true;
        }
        listCtrl->SetItemBackgroundColour( item, itembgcolour );

        if ( settings->isConnectionListColumnActive( wxT("Port") ) == true ) {
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, wxString::Format( wxT("%i"), curRDP->getPort() ) );
        }

        if ( settings->isConnectionListColumnActive( wxT("Username") ) == true ) {
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, curRDP->getDomainUsernameString() );
        }

        if ( settings->isConnectionListColumnActive( wxT("Connection") ) == true ) {
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, ConnectionType::getConnectionTypeName( curRDP->getConnectionType() ) );
        }

        if ( settings->isConnectionListColumnActive( wxT("Use console") ) == true ) {
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, curRDP->getConsoleString() );
        }

        if ( settings->isConnectionListColumnActive( wxT("Resolution") ) == true ) {
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, curRDP->getResolutionString() );
        }
        if ( settings->isConnectionListColumnActive( wxT("Comment") ) == true ) {
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, curRDP->getComment() );
        }

        if ( settings->isConnectionListColumnActive( wxT("Client name") ) == true ) {
            wxString value = wxT("");
            if ( curRDP->getConnectionType() == ConnectionType::RDP ) {
                value = curRDP->getClientHostname();
            }
            listCtrl->SetItem( itemIndexCounter, ++columnCounter, value );
        }
        itemIndexCounter++;
    }
    updateStatusBar();
    listCtrl->Thaw();
}

void quickRDPFrame::clearListCtrl()
{
    ConnectionList* connectionListPanel = static_cast<ConnectionList*>( Notebook1->GetCurrentPage() );
    if ( connectionListPanel != NULL ) {
        connectionListPanel->addColumns();
    }
}

void quickRDPFrame::OnDuplicateButtonClick(wxCommandEvent& event)
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
    if ( curCon != NULL ) {
        wxString filename = quickRDP::Generators::generateHex( 8 );
        RDPConnection *myNewCon = Resources::Instance()->getConnectionDatabase()->duplicateRDPConnection( filename, curCon );
        OnEditButtonClick( event, myNewCon );
        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnSearchTextEnter(wxCommandEvent& WXUNUSED(event) )
{
    /** first delselect all items in the list control... **/
    long item = -1;
    for (;;) {
        item = getConnectionList()->GetNextItem( item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( item == -1 ) {
            break;
        }
        getConnectionList()->SetItemState( item, 0, wxLIST_STATE_SELECTED );
    }

    /** now select our top one **/
    if ( getConnectionList()->GetItemCount() > 0 ) {
        getConnectionList()->SetItemState(getConnectionList()->GetTopItem(),wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
        getConnectionList()->SetFocus();
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

void quickRDPFrame::OnMenuItem3Selected(wxCommandEvent& event )
{
    /** Popup menu for Properties of a connection **/
    OnEditButtonClick( event );
}

void quickRDPFrame::OnMenuItem4Selected(wxCommandEvent& WXUNUSED(event) )
{
    /** Function for "Attach to console" popup menu item. **/
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
    if ( curCon != NULL ) {
        long itemIndex = -1;
        itemIndex = getConnectionList()->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 ) {
            return;
        }

        if ( MenuItem4->IsChecked() == true ) {
            curCon->setConsole( wxT("1") );
        } else {
            curCon->setConsole( wxT("0") );
        }

        curCon->saveFile();

        if ( getConnectionList()->GetSelectedItemCount() <= 0 ) {
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
    if ( curCon != NULL ) {
        curCon->setScreenMode( wxT("1") );
        curCon->setDesktopWidth( wxT("1400") );
        curCon->setDesktopHeight( wxT("1050") );

        curCon->saveFile();

        loadRDPFromDatabase();
    }
}

void quickRDPFrame::OnPreferences(wxCommandEvent& WXUNUSED(event) )
{
    settingsDialog *settings = new settingsDialog( this, 0 );
    showDialog( settings );
    delete settings;
    updatePopupmenuShortcuts();
    loadRDPFromDatabase();
}

void quickRDPFrame::OnCommandSelected(wxCommandEvent& event)
{
    bool doneSafetyCheck = false;
    wxMenuItem *usedMenuItem = PopupMenu1.FindItem( event.GetId() );
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() );
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
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() );
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
        settings->saveSettings();
    }
}

void quickRDPFrame::loadFrameSettings()
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        /** frames size **/
        SetSize( wxDefaultCoord, wxDefaultCoord, settings->getMainFrameWidth(), settings->getMainFrameHeight() );
    }
}

void quickRDPFrame::saveConnectionTabs()
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        std::vector< wxString > curConnectionTabs;
        for ( size_t tab = 0; tab < Notebook1->GetPageCount(); ++tab ) {
            curConnectionTabs.push_back( Notebook1->GetPageText( tab ) );
        }
        settings->setConnectionTabs( curConnectionTabs );
        settings->setConnectionTabSelected( Notebook1->GetSelection() );
        settings->saveSettings();
    }
}

void quickRDPFrame::loadConnectionTabs()
{
    Settings* settings = Resources::Instance()->getSettings();
    if ( settings != NULL ) {
        std::vector< wxString > curConnectionTabs = settings->getConnectionTabs();
        if ( curConnectionTabs.empty() == false ) {
            for ( std::vector< wxString >::const_iterator it = curConnectionTabs.begin(); it != curConnectionTabs.end(); ++it ) {
                addConnectionTab( (*it) );
            }
        } else {
            addConnectionTab( wxT("") );
        }
        Notebook1->SetSelection( settings->getConnectionTabSelected() );
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
    CommandList *commandList = new CommandList( this, 0 );
    showDialog( commandList );
    delete commandList;

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
            wxString strline;
            while ( getline(rfile,inputData) ) {
                wxString input( inputData.c_str(), wxConvUTF8 );
                strline.append( input + wxT("\n") );
            }

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
    wxCommandEvent ourEvent;
    Settings *settings = Resources::Instance()->getSettings();
    int keyCode = event.GetKeyCode();
    int keyModifier = event.GetModifiers();

    if ( wantGlobalHotkeys() == true ) {
        /** check if we are tabbing between controls **/
        if ( keyCode == WXK_TAB && keyModifier == wxMOD_NONE ) {
            if ( wxWindow::FindFocus()->GetId() == ID_TEXTCTRL1 ) {
                getConnectionList()->SetFocus();
            } else {
                TextCtrl1->SetFocus();
            }
            return true;
        } else if ( keyCode == settings->getNewConnectionShortcut().first && keyModifier == settings->getNewConnectionShortcut().second ) {
            OnNewButtonClick( ourEvent );
            return true;
        } else if ( keyCode == settings->getCommandDialogShortcut().first && keyModifier == settings->getCommandDialogShortcut().second ) {
            OnMenuCommands( ourEvent );
            return true;
        } else if ( keyCode == settings->getNewTabShortcut().first && keyModifier == settings->getNewTabShortcut().second ) {
            addConnectionTab( wxT("") );
            return true;
        } else if ( keyCode == settings->getCloseTabShortcut().first && keyModifier == settings->getCloseTabShortcut().second ) {
            if ( Notebook1->GetPageCount() > 1 ) {
                Notebook1->RemovePage( Notebook1->GetSelection() );
            } else {
                Notebook1->SetPageText( Notebook1->GetSelection(), wxT("") );
                TextCtrl1->SetValue( wxT("") );
            }
            return true;

        /** Okay, now we only check our connection only shortcuts.. (ListCtrl is in focus) **/
        } else if ( wxWindow::FindFocus()->GetName() == wxT("ID_LISTCTRL1") ) {
            /** first we look for commands that have this specific keycombination and try to execute it **/
            std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() );
            Command* curCommand = Resources::Instance()->getCommandDatabase()->getCommandWithShortcut( keyModifier, keyCode );
            if ( curCommand != NULL ) {
                for ( size_t con = 0; con < connections.size(); ++con ) {
                    if ( connections[ con ] != NULL ) {
                        curCommand->execute( connections[ con ] );
                    }
                }
                return true;
            } else {
                /** no command found, then we look for connection specific shortcuts... **/
                if ( keyCode == settings->getDupConnectionShortcut().first && keyModifier == settings->getDupConnectionShortcut().second ) {
                    OnDuplicateButtonClick( ourEvent );
                    return true;
                } else if ( keyCode == settings->getPropConnectionShortcut().first && keyModifier == settings->getPropConnectionShortcut().second ) {
                    OnEditButtonClick( ourEvent );
                    return true;
                } else if ( keyCode == settings->getSelectAllConnectionsShortcut().first && keyModifier == settings->getSelectAllConnectionsShortcut().second ) {
                    SelectAllConnections();
                    return true;
                } else if ( keyCode == settings->getManualCCShortcut().first && keyModifier == settings->getManualCCShortcut().second ) {
                    manuallyDoConnectionCheck( connections );
                    return true;
                } else if ( keyCode == settings->getConnectWhenReadyShortcut().first && keyModifier == settings->getConnectWhenReadyShortcut().second ) {
                    OnMenuItemConnectWhenReady( ourEvent );
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

int quickRDPFrame::showDialog( wxDialog* dialog )
{
    globalhotkeys = false;
    int retval = dialog->ShowModal();
    globalhotkeys = true;
    return retval;
}

void quickRDPFrame::checkForVersionChangesAndNotifyUser( wxString oldVersion )
{
    std::vector< std::pair< wxString, wxString > > newsQueue;
    wxString newsOutput;
    /** all logic here is strictly static for now.. we'll see how we handle this in the future (perhaps there won't be too many of these drastic changes).. **/

    Settings *settings = Resources::Instance()->getSettings();
    /** Since 1.2.1 we implemented global hotkeys.. Users may want to remove these.
    but we should allow new users upgrading to 1.2.1 to have the default old ones.
    Setting them here if we're starting 1.2.1 for the first time now. **/
    if ( oldVersion < wxT("1.2.1") ) {
        settings->setDupConnectionShortcut( std::make_pair( 68, wxMOD_CONTROL ) ); /** Ctrl+D **/
        settings->setPropConnectionShortcut( std::make_pair( 80, wxMOD_CONTROL ) ); /** Ctrl+P **/
    }

    /** with the new connection checker in 2.0 we want to enable automatic checks it by default.. by setting it here **/
    if ( oldVersion < wxT("2.0") ) {
        settings->setCCAutomaticCheck( 1 );
        settings->setNewTabShortcut( std::make_pair( 84, wxMOD_CONTROL ) );
        settings->setCloseTabShortcut( std::make_pair( 87, wxMOD_CONTROL ) );
        newsQueue.push_back( std::make_pair( wxT("2.0"), wxT("Open new connection tabs with Ctrl+T and close the current one with Ctrl+W. Go into Settings -> Preferences if you like to change these keybindings.") ) );
    }

    if ( oldVersion < wxT("2.1") ) {
        settings->setSelectAllConnectionsShortcut( std::make_pair( 65, wxMOD_CONTROL ) );
        settings->setGreyListBackground( true );
        newsQueue.push_back( std::make_pair( wxT("2.1"), wxT("Enables selecting all connections with Ctrl+A. This can be changed as all other keybindings in the Settings menu." ) ) );
        newsQueue.push_back( std::make_pair( wxT("2.1"), wxT("Choose what columns should be visible in the connection list by right-clicking on the column panel.") ) );
        newsQueue.push_back( std::make_pair( wxT("2.1"), wxT("Light-grey background color in the connection list to help tracing the different connections. Can be turned off in Settings -> Preferences -> Layout.") ) );
        newsQueue.push_back( std::make_pair( wxT("2.1"), wxT("Network scanner added. Go to Tools -> Network Scanner to scan networks and add discovered connections.") ) );
    }

    if ( oldVersion < wxT("2.1.1") ) {
        newsQueue.push_back( std::make_pair( wxT("2.2"), wxT("Selecting 'Connect when ready' on a connection will connect to it once the Connection checker reports the connection as up. Right-click a connection to enable this." ) ) );
        /** because of some bug with the column sizes we will reset the column setting sizes here now. Also set which are displayed as default. **/
        settings->setConnectionListColumns( ConnectionListColumn::COMMENT|ConnectionListColumn::CONNECTIONTYPE|ConnectionListColumn::HOSTNAME|ConnectionListColumn::USERNAME );
        std::vector< int > columnWidths;
        columnWidths.resize( 8, 80 );
        settings->setConnectionListColumnWidths( columnWidths );
    }

    wxString lastVersion = wxT("");
    for ( std::vector< std::pair< wxString, wxString > >::reverse_iterator it = newsQueue.rbegin(); it != newsQueue.rend(); ++it ) {
        if ( (*it).first != lastVersion ) {
            if ( lastVersion != wxT("") ) {
                newsOutput << wxT("\n");
            }
            newsOutput << wxT("QuickRDP ") << (*it).first << wxT("\n");
            lastVersion = (*it).first;
        }
        newsOutput << wxT(" - ") << (*it).second << wxT("\n");
    }

    if ( newsQueue.empty() == false ) {
        ExampleDialog *newsDialog = new ExampleDialog( newsOutput, this );
        newsDialog->ShowModal();
        delete newsDialog;
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
    int status = event.GetInt();
    long connectionId = event.GetExtraLong();
    long itemIndex = rdpDatabase->getListCtrlIndexFromId( connectionId );
    RDPConnection *rdpConnection = rdpDatabase->getRDPFromConnectionID( connectionId );
    if ( rdpConnection != NULL ) {
        // update connection list status and images.
        if ( itemIndex != -1 ) {
            /** if we're using this connection in connect when ready, we want our special icon drawn for connect when ready **/
            if ( rdpConnection->getConnectWhenReady() == true && status == 0 ) {
                getConnectionList()->SetItemImage( itemIndex, 3 );
            /** else just draw the current connection status **/
            } else {
                rdpConnection->setConnectionStatus( status );
                getConnectionList()->SetItemImage( itemIndex, status );
            }
        }

        /** check if the connection has "connect when ready". if it does and is online, we connect to it **/
        if ( rdpConnection->getConnectWhenReady() == true && status == 1 ) {
            rdpConnection->setConnectWhenReady( false );
            rdpConnection->connect();
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
        propConMenu->SetText( wxT("Properties\t") + quickRDP::Shortcuts::ModifierString( settings->getPropConnectionShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getPropConnectionShortcut().first ) );
    }

    wxMenuItem *dupConMenu = PopupMenu1.FindItem( ID_POPUPMENU_DUPLICATE );
    if ( dupConMenu != NULL ) {
        dupConMenu->SetText( wxT("Duplicate\t") + quickRDP::Shortcuts::ModifierString( settings->getDupConnectionShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getDupConnectionShortcut().first ) );
    }

    wxMenuItem *manualCCMenu = PopupMenu1.FindItem( ID_POPUPMENUMANUALCC );
    if ( manualCCMenu != NULL ) {
        manualCCMenu->SetText( wxT("Connection check\t") + quickRDP::Shortcuts::ModifierString( settings->getManualCCShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getManualCCShortcut().first ) );
    }

    wxMenuItem *connectWhenReadyMenu = PopupMenu1.FindItem( ID_POPUPMENUCONNECTWHENREADY );
    if ( connectWhenReadyMenu != NULL ) {
        connectWhenReadyMenu->SetText( wxT("Connect when ready\t") + quickRDP::Shortcuts::ModifierString( settings->getConnectWhenReadyShortcut().second ) + quickRDP::Shortcuts::KeycodeString( settings->getConnectWhenReadyShortcut().first )  );
    }
}

void quickRDPFrame::updateConnectionCheckerStatus()
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( settings->getCCAutomaticCheck() == 1 ) {
        time_t seconds;
        seconds = time (NULL);
        std::vector< RDPConnection* > connectionList;
        /** when we grab our RDP database (by searches and so on) we want to load new connections to our connection checker **/
        for ( long id = getConnectionList()->GetTopItem(); id < getConnectionList()->GetCountPerPage() + getConnectionList()->GetTopItem()+1; ++id  ) {
            RDPConnection *rdpConnection = Resources::Instance()->getConnectionDatabase()->getRDPFromListCtrl( id );
            if ( rdpConnection != NULL ) {
                /** make sure we update only targets who needs to be updated **/
                if ( ( seconds - rdpConnection->getLastChecked() > settings->getCCUpdateInterval() ) && rdpConnection->isConnectionCheckerRunning() == false ) {
                    connectionList.push_back( rdpConnection );
                }
            }
        }

        /** also check for connections outside of the connection list which may have the need for "connect when ready" **/
        std::vector< RDPConnection* > rdpDatabase = Resources::Instance()->getConnectionDatabase()->getDatabase();
        seconds = time (NULL);
        for ( std::vector< RDPConnection* >::const_iterator it = rdpDatabase.begin(); it != rdpDatabase.end(); ++it ) {
            if ( ( seconds - (*it)->getLastChecked() > settings->getCCUpdateInterval() ) && (*it)->isConnectionCheckerRunning() == false && (*it)->getConnectWhenReady() == true  ) {
                connectionList.push_back( (*it) );
            }
        }

        ConnectionChecker *connectionChecker = Resources::Instance()->getConnectionChecker();
        connectionChecker->addTargets( connectionList );
    }
}

void quickRDPFrame::manuallyDoConnectionCheck( std::vector< RDPConnection* > connections )
{
    ConnectionChecker *connectionChecker = Resources::Instance()->getConnectionChecker();
    std::vector< RDPConnection* > connectionList;
    for ( std::vector< RDPConnection* >::iterator it = connections.begin(); it != connections.end(); ++it ) {
        connectionList.push_back( (*it) );
    }
    connectionChecker->addTargets( connectionList );
}

void quickRDPFrame::OnNotebook1PageChanged(wxNotebookEvent& WXUNUSED(event) )
{
    loadRDPFromDatabase();
    TextCtrl1->ChangeValue( Notebook1->GetPageText( Notebook1->GetSelection() ) );
    getConnectionList()->SetFocus();
}

void quickRDPFrame::OnPopupMenuManualCC(wxCommandEvent& WXUNUSED(event) )
{
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() );
    manuallyDoConnectionCheck( connections );
}

wxListCtrl* quickRDPFrame::getConnectionList()
{
    return static_cast<ConnectionList*>( Notebook1->GetCurrentPage() )->getConnectionList();
}

void quickRDPFrame::OnColumnClick(wxListEvent& event)
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

void quickRDPFrame::OnItemRightClick(wxListEvent& WXUNUSED(event) )
{
    RDPConnection *curCon = quickRDP::Connections::getSelectedConnection( getConnectionList() );
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
        /** set connect when ready status **/
        MenuItem25->Check( curCon->getConnectWhenReady() );
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
            commandName << wxT("\t") << quickRDP::Shortcuts::ModifierString( commandDb[ cId ]->getShortcutModifier() ) << quickRDP::Shortcuts::KeycodeString( commandDb[ cId ]->getShortcutKey() );
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
        wxMenuItem *separator = PopupMenu1.InsertSeparator( favoriteCommandMenuItems.size() + 4 );
        favoriteCommandMenuItems.push_back( separator );
    }


    /** and append our command submenu as well **/
    if ( commandMenu->GetMenuItemCount() <= 0 ) {
        wxMenuItem *newCommandMenuItem = new wxMenuItem( commandMenu, wxID_ANY, wxT("-- no commands in database --") );
        newCommandMenuItem->Enable( false );
        commandMenu->Append( newCommandMenuItem );
    }

    PopupMenu( &PopupMenu1 );
}

void quickRDPFrame::OnItemActivated(wxListEvent& WXUNUSED(event) )
{
    execute_connections();
}

void quickRDPFrame::addConnectionTab( wxString tabTitle )
{
    ConnectionList *newPanel = NULL;
    #if defined(__unix__)
        newPanel = new ConnectionList(Notebook1, this, wxID_ANY );
        newPanel->getConnectionList()->SetImageList( imageList, wxIMAGE_LIST_SMALL );
    #else
        if ( Notebook1->GetPageCount() == 0 ) {
            wxPanel *originalFirstPanel = new ConnectionList(Notebook1, this, wxID_ANY );
            Notebook1->AddPage(originalFirstPanel, tabTitle, true ); /** an event will be generated which will cause loadRDPFromDatabase() to be called. **/
            getConnectionList()->SetImageList( imageList, wxIMAGE_LIST_SMALL );
        } else {
            newPanel = static_cast<ConnectionList*> ( Notebook1->GetCurrentPage() );
        }
    #endif

    if ( newPanel != NULL ) {
        Notebook1->AddPage(newPanel, tabTitle, true );
    }
}

void quickRDPFrame::SelectAllConnections()
{
    wxListCtrl *curConnectionList = getConnectionList();
    if ( curConnectionList != NULL ) {
        /** Select all items in the connection list **/
        long item = -1;
        for (;;) {
            item = curConnectionList->GetNextItem( item, wxLIST_NEXT_ALL, wxLIST_STATE_DONTCARE );
            if ( item == -1 ) {
                break;
            }
            curConnectionList->SetItemState( item, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
        }
    }
}

void quickRDPFrame::OnItemSelected(wxListEvent& WXUNUSED(event) )
{
    BitmapButton2->Enable();
    BitmapButton3->Enable();
    BitmapButton4->Enable();

    /** Update our status page with information about current selected connections **/
    updateStatusBar();
}

void quickRDPFrame::OnItemDeselected(wxListEvent& WXUNUSED(event) )
{
    BitmapButton2->Disable();
    BitmapButton3->Disable();
    BitmapButton4->Disable();
    /** Update our status page with information about current selected connections **/
    updateStatusBar();
}

void quickRDPFrame::UpdateFrameWidthOnAllListConnections()
{
    /** This call is to allow updating the column width on all our active ConnectionLists.
        Note: This is only for Linux. On Windows we only keep one ConnectionList panel alive anyway... **/
    #if defined(__unix__)
        for ( size_t pageId = 0; pageId < Notebook1->GetPageCount(); ++pageId ) {
            ConnectionList* connectionList = static_cast<ConnectionList*>( Notebook1->GetPage( pageId ) );
            if ( connectionList != NULL ) {
                connectionList->UpdateColumnWidth();
            }
        }
    #endif
}

void quickRDPFrame::OnEditButtonBitmapClick(wxCommandEvent& event)
{
    OnEditButtonClick( event );
}

void quickRDPFrame::updateStatusBar()
{
    int totalConnections = getConnectionList()->GetItemCount();
    int selectedConnections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() ).size();
    StatusBar1->SetStatusText( wxString::Format( wxT(" %d/%d"), selectedConnections, totalConnections ), 1 );
}

void quickRDPFrame::OnMenuNetworkScanner(wxCommandEvent& WXUNUSED( event ) )
{
    NetworkScanner *scanner = new NetworkScanner( this, 0 );
    unsigned int targetsAdded = showDialog( scanner );
    if ( targetsAdded > 0 ) {
        loadRDPFromDatabase();
    }
    delete scanner;
}

void quickRDPFrame::OnMenuItemConnectWhenReady(wxCommandEvent& WXUNUSED( event ) )
{
    std::vector< RDPConnection* > connections = quickRDP::Connections::getAllSelectedConnections( getConnectionList() );
    for ( std::vector< RDPConnection* >::iterator it = connections.begin(); it != connections.end(); ++it ) {
        (*it)->setConnectWhenReady( !(*it)->getConnectWhenReady() );
    }
    manuallyDoConnectionCheck( connections );
}

void quickRDPFrame::OnIPCalculator(wxCommandEvent& WXUNUSED( event ) )
{
    IPCalculator *IPCalc= new IPCalculator( this, 0 );
    showDialog( IPCalc );
    delete IPCalc;
}
