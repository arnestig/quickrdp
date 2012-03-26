#include "CommandDialog.h"
#include "Resources.h"
#include <vector>

//(*InternalHeaders(CommandDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CommandDialog)
const long CommandDialog::ID_STATICTEXT1 = wxNewId();
const long CommandDialog::ID_TEXTCTRL1 = wxNewId();
const long CommandDialog::ID_STATICTEXT2 = wxNewId();
const long CommandDialog::ID_TEXTCTRL2 = wxNewId();
const long CommandDialog::ID_BUTTON1 = wxNewId();
const long CommandDialog::ID_STATICTEXT3 = wxNewId();
const long CommandDialog::ID_TEXTCTRL3 = wxNewId();
const long CommandDialog::ID_STATICTEXT4 = wxNewId();
const long CommandDialog::ID_STATICTEXT9 = wxNewId();
const long CommandDialog::ID_CHECKBOX1 = wxNewId();
const long CommandDialog::ID_BUTTON2 = wxNewId();
const long CommandDialog::ID_STATICLINE1 = wxNewId();
const long CommandDialog::ID_LISTBOX1 = wxNewId();
const long CommandDialog::ID_BUTTON3 = wxNewId();
const long CommandDialog::ID_BUTTON4 = wxNewId();
const long CommandDialog::ID_BUTTON5 = wxNewId();
const long CommandDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommandDialog,wxDialog)
	//(*EventTable(CommandDialog)
	//*)
END_EVENT_TABLE()

CommandDialog::CommandDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(CommandDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(391,253));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	nameTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(170,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(nameTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Program"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer5->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	programTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(135,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer5->Add(programTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(25,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer5->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Argument"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer6->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	argumentTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(170,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer6->Add(argumentTextCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Favorite"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer12->Add(StaticText4, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _(" \? "), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICTEXT9"));
	StaticText9->SetForegroundColour(wxColour(255,0,0));
	StaticText9->SetToolTip(_("Favorite commands will appear in the top right-click menu instead of in the sub-menu called \"Commands\"."));
	BoxSizer12->Add(StaticText9, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	BoxSizer12->Add(CheckBox1, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer12, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	saveButton = new wxButton(Panel1, ID_BUTTON2, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer7->Add(saveButton, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	CommandList = new wxListBox(Panel1, ID_LISTBOX1, wxDefaultPosition, wxSize(195,270), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	BoxSizer9->Add(CommandList, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	editButton = new wxButton(Panel1, ID_BUTTON3, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer10->Add(editButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RemoveButton = new wxButton(Panel1, ID_BUTTON4, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	RemoveButton->Disable();
	BoxSizer10->Add(RemoveButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	closeButton = new wxButton(Panel1, ID_BUTTON5, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer11->Add(closeButton, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
	BoxSizer10->Add(BoxSizer11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer10, 0, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommandDialog::OnNameTextChange);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnSaveButton);
	Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&CommandDialog::OnListDoubleClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandDialog::OnCloseButton);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&CommandDialog::OnInit);
	//*)
	reloadCommandList();
}

CommandDialog::~CommandDialog()
{
	//(*Destroy(CommandDialog)
	//*)
}

void CommandDialog::reloadCommandList()
{
    CommandList->Clear();
	std::vector< Command* > commands = Resources::Instance()->getCommandDatabase()->getCommands();

	for ( size_t sId = 0; sId < commands.size(); ++sId ) {
        CommandList->Append( commands[ sId ]->getName() );
	}
    nameTextCtrl->Clear();
    programTextCtrl->Clear();
    argumentTextCtrl->Clear();
}

void CommandDialog::OnCloseButton(wxCommandEvent& event)
{
   this->EndModal( 0 );
}

void CommandDialog::OnListDoubleClick(wxCommandEvent& event)
{
    wxString selectedItem = CommandList->GetStringSelection();
    if ( selectedItem != wxT("") ) {
        Command *curCommand = Resources::Instance()->getCommandDatabase()->getCommand( selectedItem );
        if ( curCommand != NULL ) {
            nameTextCtrl->SetValue( curCommand->getName() );
            programTextCtrl->SetValue( curCommand->getProgram() );
            argumentTextCtrl->SetValue( curCommand->getArgument() );
        }
    }
}

void CommandDialog::OnCommandListClick(wxCommandEvent& event)
{
    wxString selectedItem = CommandList->GetStringSelection();
    if ( selectedItem != wxT("") ) {
        RemoveButton->Enable( true );
    } else {
        RemoveButton->Enable( false );
    }
}

void CommandDialog::OnNameTextChange(wxCommandEvent& event)
{
    if ( nameTextCtrl->IsEmpty() == true ) {
        saveButton->Enable( false );
    } else {
        saveButton->Enable( true );
    }
}

void CommandDialog::OnSaveButton(wxCommandEvent& event)
{
    Resources::Instance()->getCommandDatabase()->saveCommand( nameTextCtrl->GetValue(), programTextCtrl->GetValue(), argumentTextCtrl->GetValue() );
    reloadCommandList();
}

void CommandDialog::OnRemoveButton(wxCommandEvent& event)
{
    wxString selectedItem = CommandList->GetStringSelection();
    if ( selectedItem != wxT("") ) {
        Resources::Instance()->getCommandDatabase()->deleteCommand( selectedItem );
        reloadCommandList();
        RemoveButton->Enable( false );
    }
}

void CommandDialog::OnInit(wxInitDialogEvent& event)
{
}