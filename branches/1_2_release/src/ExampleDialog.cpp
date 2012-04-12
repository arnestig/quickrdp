#include "ExampleDialog.h"

//(*InternalHeaders(ExampleDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ExampleDialog)
const long ExampleDialog::ID_TEXTCTRL1 = wxNewId();
const long ExampleDialog::ID_BUTTON1 = wxNewId();
const long ExampleDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ExampleDialog,wxDialog)
	//(*EventTable(ExampleDialog)
	//*)
END_EVENT_TABLE()

ExampleDialog::ExampleDialog(wxString example, wxWindow* parent,wxWindowID id)
{
	//(*Initialize(ExampleDialog)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	exampleTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(610,183), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	exampleTextCtrl->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	BoxSizer2->Add(exampleTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExampleDialog::OnCloseButton);
	//*)
	exampleTextCtrl->ChangeValue( example );
	Button1->SetFocus();
}

ExampleDialog::~ExampleDialog()
{
	//(*Destroy(ExampleDialog)
	//*)
}

void ExampleDialog::OnCloseButton(wxCommandEvent& event)
{
    EndModal( 0 );
}
