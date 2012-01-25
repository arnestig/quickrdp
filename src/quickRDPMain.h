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

#ifndef QUICKRDPMAIN_H
#define QUICKRDPMAIN_H

#include "RDPDatabase.h"
#include <memory>

//(*Headers(quickRDPFrame)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
//*)

class quickRDPFrame: public wxFrame
{
    public:

        quickRDPFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~quickRDPFrame();

    private:

        //(*Handlers(quickRDPFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnListCtrl1ItemSelect(wxListEvent& event);
        void OnListCtrl1ItemDeselect(wxListEvent& event);
        void OnNewButtonClick(wxCommandEvent& event);
        void OnDeleteButtonClick(wxCommandEvent& event);
        void OnEditButtonClick(wxCommandEvent& event);
        void OnListCtrl1ItemActivated(wxListEvent& event);
        void OnDuplicateButtonClick(wxCommandEvent& event);
        void OnSearchTextEnter(wxCommandEvent& event);
        void OnListCtrl1ItemRClick(wxListEvent& event);
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
        void OnListCtrl1ColumnClick(wxListEvent& event);
        void OnPreferences(wxCommandEvent& event);
        void OnPopupMenuPing(wxCommandEvent& event);
        void OnMenuPerlScripts(wxCommandEvent& event);
        void OnMenuItemConnect(wxCommandEvent& event);
        //*)
        void OnTextCtrlClick(wxCommandEvent& event);
        void OnPerlScriptSelected(wxCommandEvent& event);

        //(*Identifiers(quickRDPFrame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_TEXTCTRL1;
        static const long ID_LISTCTRL1;
        static const long ID_PANEL1;
        static const long idMainMenuPerlScripts;
        static const long idMenuPreferences;
        static const long POPUPMENUCONNECT;
        static const long ID_POPUPMENUPROPERTIES;
        static const long ID_POPUPMENU_PING;
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
        //*)

        //(*Declarations(quickRDPFrame)
        wxMenu* MenuItem19;
        wxMenuItem* MenuItem7;
        wxListCtrl* ListCtrl1;
        wxMenu PopupMenu1;
        wxMenu* Menu3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem14;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem15;
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton2;
        wxMenuItem* MenuItem17;
        wxMenuItem* MenuItem13;
        wxBitmapButton* BitmapButton1;
        wxMenu* MenuItem8;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem12;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem6;
        wxBitmapButton* BitmapButton4;
        wxTextCtrl* TextCtrl1;
        wxBitmapButton* BitmapButton3;
        wxMenu* MenuItem5;
        wxMenuItem* MenuItem16;
        wxMenuItem* MenuItem9;
        //*)

        wxMenu *perlMenu;

        int last_column_click;

        void loadRDPFromDatabase();
        void clearListCtrl();
        void clearPopupMenuChoices();
        void execute_connections();

        DECLARE_EVENT_TABLE()
};

#endif // QUICKRDPMAIN_H
