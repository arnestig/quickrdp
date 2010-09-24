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

#ifndef QUICKRDPMAIN_H
#define QUICKRDPMAIN_H

#include "RDPDatabase.h"


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
        //*)

        //(*Identifiers(quickRDPFrame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_TEXTCTRL1;
        static const long ID_LISTCTRL1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_POPUPMENUPROPERTIES;
        static const long ID_POPUPMENUCONSOLE;
        //*)

        //(*Declarations(quickRDPFrame)
        wxListCtrl* ListCtrl1;
        wxMenu PopupMenu1;
        wxMenuItem* MenuItem4;
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton1;
        wxMenuItem* MenuItem3;
        wxBitmapButton* BitmapButton4;
        wxTextCtrl* TextCtrl1;
        wxBitmapButton* BitmapButton3;
        //*)

        void loadRDPFromDatabase();
        void clearListCtrl();

        DECLARE_EVENT_TABLE()
};

#endif // QUICKRDPMAIN_H
