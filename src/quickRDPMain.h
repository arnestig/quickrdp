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

#ifndef QUICKRDPMAIN_H
#define QUICKRDPMAIN_H

#include "QuickRDPBitmapButton.h"
#include "RDPDatabase.h"
#include <memory>
#include <wx/dialog.h>
#include <wx/listctrl.h>

//(*Headers(quickRDPFrame)
#include <wx/bmpbuttn.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class quickRDPFrame: public wxFrame
{
    public:

        quickRDPFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~quickRDPFrame();
        bool handleShortcutKeys( wxKeyEvent &event );
        void checkForNewAvailableVersion();
        void updatePopupmenuShortcuts();
        void UpdateFrameWidthOnAllListConnections();
        void updateStatusBar();
        void init();

        /** events and functions related to the list control **/
        void OnColumnClick(wxListEvent& event);
		void OnItemRightClick(wxListEvent& event);
		void OnItemActivated(wxListEvent& event);
		void OnItemSelected(wxListEvent& event);
		void OnItemDeselected(wxListEvent& event);
        void loadRDPFromDatabase();
        void SelectAllConnections();

    private:

        //(*Handlers(quickRDPFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNewButtonClick(wxCommandEvent& event);
        void OnDeleteButtonClick(wxCommandEvent& event);
        void OnDuplicateButtonClick(wxCommandEvent& event);
        void OnSearchTextEnter(wxCommandEvent& event);
        void OnMenuItem3Selected(wxCommandEvent& event);
        void OnMenuItem4Selected(wxCommandEvent& event);
        void OnMenuItemDefaultClick(wxCommandEvent& event);
        void OnMenuItemFullscreenClick(wxCommandEvent& event);
        void OnMenuItem640(wxCommandEvent& event);
        void OnMenuItem800(wxCommandEvent& event);
        void OnMenuItem1024(wxCommandEvent& event);
        void OnMenuItem1152(wxCommandEvent& event);
        void OnMenuItem1280(wxCommandEvent& event);
        void OnMenuItem1400(wxCommandEvent& event);
        void OnPreferences(wxCommandEvent& event);
        void OnMenuItemConnect(wxCommandEvent& event);
        void OnPopupMenuDuplicate(wxCommandEvent& event);
        void OnPopupMenuDelete(wxCommandEvent& event);
        void OnMenuCommands(wxCommandEvent& event);
        void OnReportBugClick(wxCommandEvent& event);
        void OnMenuSearchForUpdates(wxCommandEvent& event);
        void OnTextCtrlInput(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void OnPopupMenuManualCC(wxCommandEvent& event);
        void OnEditButtonBitmapClick(wxCommandEvent& event);
        void OnMenuNetworkScanner(wxCommandEvent& event);
        void OnMenuItemConnectWhenReady(wxCommandEvent& event);
        void OnIPCalculator(wxCommandEvent& event);
        //*)
        void OnTextCtrlClick(wxCommandEvent& event);
        void OnNewVersionTextClick(wxCommandEvent& event);
        void OnCommandSelected(wxCommandEvent& event);
        void onVersionCheckExecuted( wxCommandEvent &evt );
        void onAutomaticVersionCheckExecuted( wxCommandEvent &evt );
        void OnEditButtonClick(wxCommandEvent& event, RDPConnection *editConnection = NULL);
        void OnChangelogClick( wxCommandEvent& event );
        void onConnectionCheckerUpdate( wxCommandEvent& event );
        void onConnectionCheckerWantData( wxCommandEvent& event );
        void onConnectionCheckerDone( wxCommandEvent& event );
        wxListCtrl* getConnectionList();

        //(*Identifiers(quickRDPFrame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        static const long idMenuNetworkScanner;
        static const long idIPCalculator;
        static const long idMenuCommands;
        static const long idMenuPreferences;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long POPUPMENUCONNECT;
        static const long ID_POPUPMENUCONNECTWHENREADY;
        static const long ID_POPUPMENUPROPERTIES;
        static const long ID_POPUPMENU_DUPLICATE;
        static const long ID_POPUPMENU_DELETE;
        static const long ID_POPUPMENUMANUALCC;
        static const long ID_POPUPMENUCONSOLE;
        static const long ID_MENUDEFAULT;
        static const long ID_MENUFULLSCREEN;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM1;
        static const long POPUPMENURDP;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(quickRDPFrame)
        wxMenuItem* MenuItem23;
        wxMenu* MenuItem19;
        wxStaticText* VersionNotifyText;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem16;
        wxMenuItem* MenuItem12;
        wxMenuItem* MenuItem25;
        wxMenu* Menu3;
        wxMenuItem* MenuItem20;
        wxMenuItem* MenuItem24;
        wxMenuItem* MenuItem15;
        wxMenuItem* MenuItem21;
        wxMenuItem* MenuItem17;
        wxMenuItem* MenuItem3;
        QuickRDPBitmapButton* BitmapButton2;
        wxMenuItem* MenuItem9;
        wxMenu* Menu4;
        wxMenu* MenuItem5;
        wxMenuItem* MenuItem11;
        QuickRDPBitmapButton* BitmapButton1;
        wxMenuItem* MenuItem22;
        QuickRDPBitmapButton* BitmapButton4;
        wxTextCtrl* TextCtrl1;
        wxMenu ColumnMenu;
        wxMenuItem* MenuItem10;
        wxNotebook* Notebook1;
        wxMenuItem* MenuItem18;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem4;
        wxMenu PopupMenu1;
        wxMenuItem* MenuItem26;
        wxMenuItem* MenuItem13;
        wxMenu* MenuItem8;
        QuickRDPBitmapButton* BitmapButton3;
        wxMenuItem* MenuItem14;
        //*)

        wxPanel *connectionListPanel;
        wxMenu *commandMenu;
        std::vector< wxMenuItem* > favoriteCommandMenuItems;
        wxImageList *imageList;

        wxString last_column_click;
        bool globalhotkeys;

        void clearListCtrl();
        void clearPopupMenuChoices();
        void execute_connections();
        void addConnectionTab( wxString tabTitle );

        void saveConnectionTabs();
        void loadConnectionTabs();
        void saveFrameSettings();
        void loadFrameSettings();
        int showDialog( wxDialog* dialog );
        bool wantGlobalHotkeys() const;
        void checkForVersionChangesAndNotifyUser( wxString oldVersion );
        void updateConnectionCheckerStatus();
        void manuallyDoConnectionCheck( std::vector< RDPConnection* > connections );

        DECLARE_EVENT_TABLE()
};

#endif // QUICKRDPMAIN_H
