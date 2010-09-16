#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <wx/hyperlink.h>

//(*Headers(aboutDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/dialog.h>
//*)

class aboutDialog: public wxDialog
{
	public:

		aboutDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~aboutDialog();

		//(*Declarations(aboutDialog)
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxStaticBitmap* StaticBitmap1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* StaticText4;
		//*)
		wxHyperlinkCtrl* Hyperlink1;
		wxHyperlinkCtrl* Hyperlink2;

	protected:

		//(*Identifiers(aboutDialog)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT6;
		static const long ID_PANEL1;
		//*)
		static const long ID_HYPERLINK1;
		static const long ID_HYPERLINK2;

	private:

		//(*Handlers(aboutDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
