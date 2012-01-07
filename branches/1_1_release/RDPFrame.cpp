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

#include "RDPFrame.h"
#include "RDPDatabase.h"

#include <memory>

//(*InternalHeaders(RDPFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(RDPFrame)
const long RDPFrame::ID_NOTEBOOK1 = wxNewId();
const long RDPFrame::ID_BUTTON1 = wxNewId();
const long RDPFrame::ID_BUTTON2 = wxNewId();
const long RDPFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RDPFrame,wxDialog)
	//(*EventTable(RDPFrame)
	//*)
END_EVENT_TABLE()

extern std::auto_ptr<RDPDatabase> rdpDatabase;

RDPFrame::RDPFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	//(*Initialize(RDPFrame)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(371,447));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxSize(361,391), 0, _T("ID_NOTEBOOK1"));
	BoxSizer2->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->Disable();
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RDPFrame::onSaveClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RDPFrame::onCloseClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&RDPFrame::OnClose);
	//*)
	generalTab = new generalTabPanel( Notebook1, wxID_ANY );
	windowTab = new windowTabPanel( Notebook1, wxID_ANY );
	resourcesTab = new resourcesTabPanel( Notebook1, wxID_ANY );
	Notebook1->AddPage( generalTab, wxT("General") );
    Notebook1->AddPage( windowTab, wxT("Window") );
    Notebook1->AddPage( resourcesTab, wxT("Resources") );
    generalTab->setOwner( this );
    windowTab->setOwner( this );
    resourcesTab->setOwner( this );
}

RDPFrame::~RDPFrame()
{
	//(*Destroy(RDPFrame)
	//*)
}

void RDPFrame::loadRDPConnection( RDPConnection* rdpConnection )
{
    this->rdpConnection = rdpConnection;

    /// select correct layout based on which connectiontype we have.
    switchConnectionType( rdpConnection->getConnectionType() );

    /// GENERALTAB BEGIN
    generalTab->Choice1->Select( rdpConnection->getConnectionType() );
    generalTab->TextCtrl2->ChangeValue( rdpConnection->getHostname() ); // hostname
    generalTab->TextCtrl7->ChangeValue( rdpConnection->getUsername() ); // user
    generalTab->TextCtrl3->ChangeValue( rdpConnection->getPassword() ); // pass
    generalTab->TextCtrl4->ChangeValue( rdpConnection->getDomain() ); // domain
    generalTab->TextCtrl6->ChangeValue( rdpConnection->getComment() ); // comment
    generalTab->TextCtrl5->ChangeValue( rdpConnection->getClientHostname() ); // client hostname
    if ( rdpConnection->getConsole() == wxT("1") ) {
        generalTab->CheckBox1->SetValue( true );
    } else {
        generalTab->CheckBox1->SetValue( false );
    }
    /// GENERALTAB END


    /// WINDOWTAB BEGIN
    if ( rdpConnection->getScreenMode() == wxT("2") ) {
        windowTab->RadioBox1->SetStringSelection( wxT("Fullscreen") );
    } else if ( rdpConnection->getScreenMode() == wxT("1") && rdpConnection->getDesktopHeight() == wxT("0") && rdpConnection->getDesktopWidth() == wxT("0") ) {
        windowTab->RadioBox1->SetStringSelection( wxT("Default resolution" ) );
    } else {
        windowTab->RadioBox1->SetStringSelection( wxT("Custom resolution" ) );
        windowTab->ComboBox2->SetValue( rdpConnection->getDesktopWidth() + wxT(" x ") + rdpConnection->getDesktopHeight() );
    }

    if ( rdpConnection->getDesktopBpp() == wxT("0") ) {
        windowTab->RadioBox2->SetStringSelection( wxT("Default colors") );
    } else {
        windowTab->RadioBox2->SetStringSelection( wxT("Custom colors") );
        if ( rdpConnection->getDesktopBpp() == wxT("15") ) { windowTab->ComboBox1->SetValue( wxT("\"High Color\" (15 bits)") ); }
        if ( rdpConnection->getDesktopBpp() == wxT("16") ) { windowTab->ComboBox1->SetValue( wxT("\"High Color\" (16 bits)") ); }
        if ( rdpConnection->getDesktopBpp() == wxT("24") ) { windowTab->ComboBox1->SetValue( wxT("\"True Color\" (24 bits)") ); }
    }

    windowTab->MarkComboBoxes();
    /// WINDOWTAB END

    /// RESOURCESTAB BEGIN

    resourcesTab->RadioBox1->SetSelection( wxAtoi( rdpConnection->getSoundMode() ) );
    if ( rdpConnection->getDiskMapping() == wxT("1") ) {
        resourcesTab->CheckBox1->SetValue( true );
    }

    /// RESOURCESTAB END
}

void RDPFrame::switchConnectionType( ConnectionType::ConnectionType connectionType )
{
    /** Layout for RDP connections **/
    if ( connectionType == ConnectionType::RDP ) {
        if ( Notebook1->GetPageCount() == 1 ) {
            Notebook1->AddPage( windowTab, wxT("Window") );
            Notebook1->AddPage( resourcesTab, wxT("Resources") );
            generalTab->StaticText4->Show();
            generalTab->TextCtrl4->Show();
            generalTab->StaticText5->Show();
            generalTab->TextCtrl5->Show();
            generalTab->CheckBox1->Show();
        }
    } else {
        /** Layout for SSH or telnet connections **/
        if ( Notebook1->GetPageCount() > 1 ) {
            Notebook1->RemovePage( 2 );
            Notebook1->RemovePage( 1 );
            generalTab->StaticText4->Hide();
            generalTab->TextCtrl4->Hide();
            generalTab->StaticText5->Hide();
            generalTab->TextCtrl5->Hide();
            generalTab->CheckBox1->Hide();
        }
    }
}

void RDPFrame::checkForChanges()
{
    /// general tab
    bool hasChangedSomething = false;
    if ( generalTab->Choice1->GetCurrentSelection() != rdpConnection->getConnectionType() ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl2->GetValue().Cmp( rdpConnection->getHostname() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl7->GetValue().Cmp( rdpConnection->getUsername() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl3->GetValue().Cmp( rdpConnection->getPassword() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl4->GetValue().Cmp( rdpConnection->getDomain() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl6->GetValue().Cmp( rdpConnection->getComment() ) != 0 ) { hasChangedSomething = true; }
    if ( generalTab->TextCtrl5->GetValue().Cmp( rdpConnection->getClientHostname() ) != 0 ) { hasChangedSomething = true; }
    if ( ( generalTab->CheckBox1->IsChecked() == true && rdpConnection->getConsole() == wxT("0") ) || ( generalTab->CheckBox1->IsChecked() == false && rdpConnection->getConsole() == wxT("1") ) ) { hasChangedSomething = true; }

    /// desktop resolution
    switch ( windowTab->RadioBox1->GetSelection() )
    {
        case 0: // default resolution
            if ( !( rdpConnection->getScreenMode() == wxT("1") )
            || !( rdpConnection->getDesktopHeight() == wxT("0") )
            || !( rdpConnection->getDesktopWidth() == wxT("0") ) ) { hasChangedSomething = true; }
        break;
        case 1: // full screen
            if ( !( rdpConnection->getScreenMode() == wxT("2") )
            || !( rdpConnection->getDesktopHeight() == wxT("0") )
            || !( rdpConnection->getDesktopWidth() == wxT("0") ) ) { hasChangedSomething = true; }
        break;
        case 2: // custom resolution
            if ( !( rdpConnection->getDesktopWidth() + wxT(" x ") + rdpConnection->getDesktopHeight() == windowTab->ComboBox2->GetValue() ) ) { hasChangedSomething = true; }
        break;
    }

    /// desktop bpp
    switch ( windowTab->RadioBox2->GetSelection() )
    {
        case 0:
            if ( rdpConnection->getDesktopBpp() != wxT("0") ) { hasChangedSomething = true; }
        break;
        case 1:
            if (  ( rdpConnection->getDesktopBpp() == wxT("0" ) )
               || ( rdpConnection->getDesktopBpp() == wxT("15") && windowTab->ComboBox1->GetValue() != wxT("\"High Color\" (15 bits)") )
               || ( rdpConnection->getDesktopBpp() == wxT("16") && windowTab->ComboBox1->GetValue() != wxT("\"High Color\" (16 bits)") )
               || ( rdpConnection->getDesktopBpp() == wxT("24") && windowTab->ComboBox1->GetValue() != wxT("\"True Color\" (24 bits)") ) ) { hasChangedSomething = true; }
        break;
    }

    /// resources tab
    switch ( resourcesTab->RadioBox1->GetSelection() )
    {
        case 0:
            if ( rdpConnection->getSoundMode() != wxT("0") ) { hasChangedSomething = true; }
        break;
        case 1:
            if ( rdpConnection->getSoundMode() != wxT("1") ) { hasChangedSomething = true; }
        break;
        case 2:
            if ( rdpConnection->getSoundMode() != wxT("2") ) { hasChangedSomething = true; }
        break;
    }

    if ( ( resourcesTab->CheckBox1->IsChecked() == true && rdpConnection->getDiskMapping() == wxT("0") ) || ( resourcesTab->CheckBox1->IsChecked() == false && rdpConnection->getDiskMapping() == wxT("1") ) ) { hasChangedSomething = true; }

    if ( generalTab->TextCtrl2->IsEmpty() == true ) {
        Button1->Disable();
        return;
    }

    if ( hasChangedSomething == false ) {
        Button1->Disable();
    } else {
        Button1->Enable();
    }
}

void RDPFrame::onCloseClick(wxCommandEvent& event)
{
    Close();
}

void RDPFrame::onSaveClick(wxCommandEvent& event)
{
    rdpConnection->setConnectionType( static_cast< ConnectionType::ConnectionType > ( generalTab->Choice1->GetCurrentSelection() ) );
    rdpConnection->setHostname( generalTab->TextCtrl2->GetValue() );
    rdpConnection->setUsername( generalTab->TextCtrl7->GetValue() );
    rdpConnection->setPassword( generalTab->TextCtrl3->GetValue() );
    rdpConnection->setDomain( generalTab->TextCtrl4->GetValue() );
    rdpConnection->setComment( generalTab->TextCtrl6->GetValue() );
    rdpConnection->setClientHostname( generalTab->TextCtrl5->GetValue() );
    if ( generalTab->CheckBox1->IsChecked() == true ) {
        rdpConnection->setConsole( wxT("1") );
    } else {
        rdpConnection->setConsole( wxT("0") );
    }

    /// desktop resolution
    switch ( windowTab->RadioBox1->GetSelection() )
    {
        case 0: // default resolution
            rdpConnection->setDesktopHeight( wxT("0") );
            rdpConnection->setDesktopWidth( wxT("0") );
            rdpConnection->setScreenMode( wxT("1") );
        break;
        case 1: // full screen
            rdpConnection->setDesktopHeight( wxT("0") );
            rdpConnection->setDesktopWidth( wxT("0") );
            rdpConnection->setScreenMode( wxT("2") );
        break;
        case 2: // custom resolution
            rdpConnection->setScreenMode( wxT("1") );
            wxString resolutionString = windowTab->ComboBox2->GetValue();
            wxString splitString = wxT(" x ");
            int splitPos = resolutionString.Find( splitString );
            rdpConnection->setDesktopWidth( resolutionString.SubString( 0, splitPos-1 ) );
            rdpConnection->setDesktopHeight( resolutionString.SubString( splitPos + splitString.Len(), resolutionString.Len() ) );
        break;
    }
    switch( windowTab->RadioBox2->GetSelection() )
    {
        case 0:
            rdpConnection->setDesktopBpp( wxT("0") );
        break;
        case 1:
            if ( windowTab->ComboBox1->GetValue() == wxT("\"High Color\" (15 bits)") ) { rdpConnection->setDesktopBpp( wxT("15") ); }
            if ( windowTab->ComboBox1->GetValue() == wxT("\"High Color\" (16 bits)") ) { rdpConnection->setDesktopBpp( wxT("16") ); }
            if ( windowTab->ComboBox1->GetValue() == wxT("\"True Color\" (24 bits)") ) { rdpConnection->setDesktopBpp( wxT("24") ); }
        break;
    }

    rdpConnection->setSoundMode( wxString::Format( wxT("%d"),resourcesTab->RadioBox1->GetSelection() ) );
    rdpConnection->setDiskMapping( wxString::Format( wxT("%d"),resourcesTab->CheckBox1->IsChecked() ) );


    rdpConnection->saveFile();
    Button1->Disable();
    Button2->SetFocus();
    Close();
}

void RDPFrame::OnClose(wxCloseEvent& event)
{
    if ( rdpConnection->getHostname().IsEmpty() == true ) {
        rdpDatabase->deleteRDPConnectionByPointer( rdpConnection );
    }
    Destroy();
}
