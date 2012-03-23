#ifndef COMMANDDIALOG_H
#define COMMANDDIALOG_H

//(*Headers(CommandDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommandDialog: public wxDialog
{
	public:

		CommandDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~CommandDialog();

		//(*Declarations(CommandDialog)
		wxTextCtrl* argumentTextCtrl;
		wxButton* closeButton;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxButton* saveButton;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* nameTextCtrl;
		wxListBox* CommandList;
		wxStaticLine* StaticLine1;
		wxTextCtrl* programTextCtrl;
		wxButton* RemoveButton;
		wxButton* editButton;
		//*)

	protected:

		//(*Identifiers(CommandDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON2;
		static const long ID_STATICLINE1;
		static const long ID_LISTBOX1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(CommandDialog)
		void OnCloseButton(wxCommandEvent& event);
		void OnListDoubleClick(wxCommandEvent& event);
		void OnCommandListClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif