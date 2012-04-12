#ifndef EXAMPLEDIALOG_H
#define EXAMPLEDIALOG_H

//(*Headers(ExampleDialog)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class ExampleDialog: public wxDialog
{
	public:

		ExampleDialog(wxString example, wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ExampleDialog();

		//(*Declarations(ExampleDialog)
		wxButton* Button1;
		wxPanel* Panel1;
		wxTextCtrl* exampleTextCtrl;
		//*)

	protected:

		//(*Identifiers(ExampleDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ExampleDialog)
		void OnCloseButton(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
