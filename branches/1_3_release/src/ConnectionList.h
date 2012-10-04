#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

//(*Headers(ConnectionList)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
//*)

#include "quickRDPMain.h"

class ConnectionList: public wxPanel
{
	public:

		ConnectionList(wxWindow* parent, quickRDPFrame *mainFrame, wxWindowID id=wxID_ANY );
		virtual ~ConnectionList();

		//(*Declarations(ConnectionList)
		wxListCtrl* ListCtrl1;
		//*)
		wxListCtrl* getConnectionList();
		void UpdateColumnWidth();

	protected:

		//(*Identifiers(ConnectionList)
		static const long ID_LISTCTRL1;
		//*)
		quickRDPFrame *mainFrame;

	private:

		//(*Handlers(ConnectionList)
		void OnColumnClick(wxListEvent& event);
		void OnItemRightClick(wxListEvent& event);
		void OnItemActivated(wxListEvent& event);
		void OnItemSelected(wxListEvent& event);
		void OnItemDeselected(wxListEvent& event);
		void OnColumnEndDrag(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
