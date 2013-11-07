#include "NetworkScanner.h"
#include "Resources.h"
#include "QuickrdpFunctions.h"
#include <wx/msgdlg.h>
#include "RDPFrame.h"
#include <wx/imaglist.h>
#include <wx/image.h>
#include <wx/icon.h>
#include "ExampleDialog.h"

//(*InternalHeaders(NetworkScanner)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NetworkScanner)
const long NetworkScanner::ID_STATICTEXT2 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL1 = wxNewId();
const long NetworkScanner::ID_STATICTEXT3 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL2 = wxNewId();
const long NetworkScanner::ID_STATICTEXT4 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL3 = wxNewId();
const long NetworkScanner::ID_STATICTEXT5 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL4 = wxNewId();
const long NetworkScanner::ID_STATICTEXT1 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL8 = wxNewId();
const long NetworkScanner::ID_STATICTEXT6 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL7 = wxNewId();
const long NetworkScanner::ID_STATICTEXT7 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL6 = wxNewId();
const long NetworkScanner::ID_STATICTEXT8 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL5 = wxNewId();
const long NetworkScanner::ID_BUTTON1 = wxNewId();
const long NetworkScanner::ID_CHECKBOX1 = wxNewId();
const long NetworkScanner::ID_CHECKBOX2 = wxNewId();
const long NetworkScanner::ID_CHECKBOX3 = wxNewId();
const long NetworkScanner::ID_CHECKBOX4 = wxNewId();
const long NetworkScanner::ID_STATICTEXT9 = wxNewId();
const long NetworkScanner::ID_BUTTON3 = wxNewId();
const long NetworkScanner::ID_TEXTCTRL9 = wxNewId();
const long NetworkScanner::ID_GAUGE1 = wxNewId();
const long NetworkScanner::ID_STATICLINE1 = wxNewId();
const long NetworkScanner::ID_LISTCTRL1 = wxNewId();
const long NetworkScanner::ID_CHECKBOX5 = wxNewId();
const long NetworkScanner::ID_ADD_SELECTED = wxNewId();
const long NetworkScanner::ID_BUTTON2 = wxNewId();
const long NetworkScanner::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NetworkScanner,wxDialog)
	//(*EventTable(NetworkScanner)
	//*))
	EVT_COMMAND(wxID_ANY, wxEVT_CONNECTION_CHECK_STATUS_UPDATE, NetworkScanner::onScanResult)
END_EVENT_TABLE()

NetworkScanner::NetworkScanner(wxWindow* parent,wxWindowID WXUNUSED( id) )
{
	//(*Initialize(NetworkScanner)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("IP Range"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer5->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPFrom1 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer5->Add(IPFrom1, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer5->Add(StaticText3, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPFrom2 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer5->Add(IPFrom2, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer5->Add(StaticText4, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPFrom3 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer5->Add(IPFrom3, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer5->Add(StaticText5, 1, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPFrom4 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer5->Add(IPFrom4, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("=>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer5->Add(StaticText1, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPTo1 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	BoxSizer5->Add(IPTo1, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer5->Add(StaticText6, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPTo2 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer5->Add(IPTo2, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer5->Add(StaticText7, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPTo3 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer5->Add(IPTo3, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer5->Add(StaticText8, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	IPTo4 = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(30,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer5->Add(IPTo4, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer5, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	ScanButton = new wxButton(Panel1, ID_BUTTON1, _("Scan"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	ScanButton->Disable();
	BoxSizer6->Add(ScanButton, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer6, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer7, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Ports"));
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	RDPCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX1, _("RDP (3389)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	RDPCheckBox->SetValue(true);
	BoxSizer9->Add(RDPCheckBox, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SSHCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX2, _("SSH (22)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	SSHCheckBox->SetValue(true);
	BoxSizer9->Add(SSHCheckBox, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TelnetCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Telnet (23)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	TelnetCheckBox->SetValue(true);
	BoxSizer9->Add(TelnetCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	VNCCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX4, _("VNC (5900)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	VNCCheckBox->SetValue(true);
	BoxSizer9->Add(VNCCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer9, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Other ports:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer10->Add(StaticText9, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON3, _("\?"), wxDefaultPosition, wxSize(25,21), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer10->Add(Button1, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	OtherPortsText = new QuickRDPTextCtrl(Panel1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(138,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	BoxSizer10->Add(OtherPortsText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer10, 0, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(StaticBoxSizer1, 1, wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Gauge1 = new wxGauge(Panel1, ID_GAUGE1, 100, wxDefaultPosition, wxSize(293,22), 0, wxDefaultValidator, _T("ID_GAUGE1"));
	BoxSizer8->Add(Gauge1, 0, wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer8, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer2->Add(StaticLine1, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(309,147), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer4->Add(ListCtrl1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	CheckboxShowAll = new wxCheckBox(Panel1, ID_CHECKBOX5, _("Show all connections"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	CheckboxShowAll->SetValue(false);
	BoxSizer12->Add(CheckboxShowAll, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonAddSelected = new wxButton(Panel1, ID_ADD_SELECTED, _("Add connection"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ADD_SELECTED"));
	ButtonAddSelected->Disable();
	BoxSizer12->Add(ButtonAddSelected, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11->Add(BoxSizer12, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	ButtonClose = new wxButton(Panel1, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer13->Add(ButtonClose, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11->Add(BoxSizer13, 0, wxTOP|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer11, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnScan);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnOtherPortsHelpClick);
	Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NetworkScanner::OnCheckBoxesClick);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&NetworkScanner::OnListCtrlSelect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&NetworkScanner::OnListCtrlSelect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&NetworkScanner::OnListCtrlItemActivated);
	Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnShowAllConnections);
	Connect(ID_ADD_SELECTED,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnButtonAdd);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NetworkScanner::OnClose);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&NetworkScanner::OnQuit);
	//*)

    scanner = NULL;
    targetsAdded = 0;

    // Setup our connection list with columns
    populateListCtrl();

    IPFrom1->setNextTextCtrl( IPFrom2, 46 );
    IPFrom1->SetMaxLength( 3 );
    IPFrom1->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPFrom2->setNextTextCtrl( IPFrom3, 46 );
    IPFrom2->SetMaxLength( 3 );
    IPFrom2->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPFrom3->setNextTextCtrl( IPFrom4, 46 );
    IPFrom3->SetMaxLength( 3 );
    IPFrom3->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPFrom4->setNextTextCtrl( IPTo1, 46 );
    IPFrom4->SetMaxLength( 3 );
    IPFrom4->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPTo1->setNextTextCtrl( IPTo2, 46 );
    IPTo1->SetMaxLength( 3 );
    IPTo1->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPTo2->setNextTextCtrl( IPTo3, 46 );
    IPTo2->SetMaxLength( 3 );
    IPTo2->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPTo3->setNextTextCtrl( IPTo4, 46 );
    IPTo3->SetMaxLength( 3 );
    IPTo3->addValidKeyCodes( std::make_pair( 48, 57 ) );
    IPTo4->SetMaxLength( 3 );
    IPTo4->addValidKeyCodes( std::make_pair( 48, 57 ) );

    OtherPortsText->addValidKeyCodes( std::make_pair( 44, 45 ) );
    OtherPortsText->addValidKeyCodes( std::make_pair( 48, 57 ) );

    imageList = new wxImageList( 16,16, true );
    #if defined(__UNIX__)
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionerror.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionok.xpm") ) );
        imageList->Add( wxIcon( Resources::Instance()->getSettings()->getDataPath() + wxT("connectionunk.xpm") ) );
    #else
        imageList->Add( wxICON( connectionerror ) );
        imageList->Add( wxICON( connectionok ) );
        imageList->Add( wxICON( connectionunk ) );
    #endif
    ListCtrl1->SetImageList( imageList, wxIMAGE_LIST_SMALL );
}

NetworkScanner::~NetworkScanner()
{
	//(*Destroy(NetworkScanner)
	//*)
    stopScanner();
	cleanTargets();
	delete imageList;
}

void NetworkScanner::startScanner()
{
    Settings *settings = Resources::Instance()->getSettings();
    if ( scanner == NULL ) {
        scanner = new ConnectionChecker( this, settings->getCCWorkerThreads(), settings->getCCTimeout() * 1000 );
        if ( scanner->Create() != wxTHREAD_NO_ERROR ) {
            delete scanner;
            scanner = NULL;
            wxMessageBox( wxT("Error creating ConnectionChecker!"), wxT("Error!") );
        } else {
            if ( scanner->Run() != wxTHREAD_NO_ERROR ) {
                delete scanner;
                scanner = NULL;
                wxMessageBox( wxT("Error while running ConnectionChecker!") );
            }
        }
    }
}

void NetworkScanner::stopScanner()
{
    if ( scanner != NULL ) {
        scanner->Delete();
        scanner = NULL;
    }
}

void NetworkScanner::redrawListCtrl()
{
    populateListCtrl();
    for ( std::vector< RDPConnection* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
        addTargetToListCtrl( (*it ) );
    }
}

void NetworkScanner::addTargetToListCtrl( RDPConnection *connection )
{
    int connectionStatus = connection->getConnectionStatus();
    if ( connectionStatus == 1 || CheckboxShowAll->IsChecked() == true ) {
        int index = ListCtrl1->GetItemCount();
        wxListItem item;
        item.SetId( index );
        ListCtrl1->InsertItem( item );
        ListCtrl1->SetItem( index, 0, connection->getHostname() );
        ListCtrl1->SetItem( index, 1, wxString::Format( wxT("%i"), connection->getPort() ) );
        ListCtrl1->SetItemImage( index, connectionStatus );
        ListCtrlRDPConnectionTable[ index ] = connection;
    }
}

void NetworkScanner::onScanResult( wxCommandEvent& event )
{
    Gauge1->SetValue( Gauge1->GetValue() + 1 );
    RDPConnection *connection = getConnectionFromId( event.GetExtraLong() );
    if ( connection != NULL ) {
        connection->setConnectionStatus( event.GetInt() );
        addTargetToListCtrl( connection );
    }

    /** is the scan finished? **/
    if ( Gauge1->GetValue() == Gauge1->GetRange() ) {
        ScanButton->SetLabel( wxT("Scan") );
        stopScanner();
    }
}

void NetworkScanner::OnScan(wxCommandEvent& WXUNUSED( event ) )
{
    if ( ScanButton->GetLabel() == wxT("Scan") ) {
        if ( IPTo1->IsEmpty() == true || IPTo2->IsEmpty() == true || IPTo3->IsEmpty() == true || IPTo4->IsEmpty() == true ) {
            IPTo1->SetValue( IPFrom1->GetValue() );
            IPTo2->SetValue( IPFrom2->GetValue() );
            IPTo3->SetValue( IPFrom3->GetValue() );
            IPTo4->SetValue( IPFrom4->GetValue() );
        }
    }

    if ( ScanButton->GetLabel() == wxT("Cancel") ) {
        stopScanner();
        ScanButton->SetLabel( wxT("Scan") );
        Gauge1->SetRange( 0 );
        Gauge1->SetValue( 0 );
    } else {
        ScanButton->SetLabel( wxT("Cancel") );

        // clean targets, so we don't have anything floating around that we don't want.
        cleanTargets();

        // clean our listctrl
        populateListCtrl();

        // collect all IP-addresses and ports we're going to scan
        std::vector< wxString > iprange = getIPRange( IPFrom1->GetValue() << wxT(".") <<
                                                     IPFrom2->GetValue() << wxT(".") <<
                                                     IPFrom3->GetValue() << wxT(".") <<
                                                     IPFrom4->GetValue(),
                                                     IPTo1->GetValue() << wxT(".") <<
                                                     IPTo2->GetValue() << wxT(".") <<
                                                     IPTo3->GetValue() << wxT(".") <<
                                                     IPTo4->GetValue() );
        std::vector< int > ports = getCustomPortsFromTextCtrl();
        if ( RDPCheckBox->IsChecked() == true ) { ports.push_back( 3389 ); }
        if ( SSHCheckBox->IsChecked() == true ) { ports.push_back( 22 ); }
        if ( TelnetCheckBox->IsChecked() == true ) { ports.push_back( 23 ); }
        if ( VNCCheckBox->IsChecked() == true ) { ports.push_back( 5900 ); }

        for ( std::vector< wxString >::iterator ip = iprange.begin(); ip != iprange.end(); ++ip ) {
            for ( std::vector< int >::iterator port = ports.begin(); port != ports.end(); ++port ) {
                RDPConnection *newCon = new RDPConnection( wxT("") );
                newCon->setHostname( (*ip) );
                newCon->setPort( (*port) );
                newCon->setConnectionType( ConnectionType::getConnectionTypeForPort( (*port) ) );
                targets.push_back( newCon );
            }
        }
        Gauge1->SetValue( 0 );
        startScanner();
        scanner->addTargets( targets );
        Gauge1->SetRange( targets.size() );
    }
}

void NetworkScanner::cleanTargets()
{
    for ( std::vector< RDPConnection* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
		delete (*it);
	}
	targets.clear();
	ListCtrlRDPConnectionTable.clear();
}

RDPConnection* NetworkScanner::getConnectionFromId( long connectionCheckerId ) {
    for ( std::vector< RDPConnection* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
        if ( (*it)->getConnectionCheckerId() == connectionCheckerId ) {
            return (*it);
        }
    }
    return NULL;
}

void NetworkScanner::populateListCtrl()
{
    ListCtrlRDPConnectionTable.clear();
    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("IP address" ) );
    ListCtrl1->InsertColumn( 1, wxT("Service / port" ) );
    ListCtrl1->SetColumnWidth( 0, 190 );
    ListCtrl1->SetColumnWidth( 1, 90 );
}

std::vector< int > NetworkScanner::getCustomPortsFromTextCtrl()
{
    std::vector< int > retval;
    if ( OtherPortsText->IsEmpty() == false ) {
        wxString otherPorts = OtherPortsText->GetValue();
        otherPorts << wxT(",");
        while ( otherPorts.Find( wxChar(',') ) != wxNOT_FOUND ) {
            wxString subPortsString = otherPorts.BeforeFirst( wxChar(',') );
            // Check if we can find a range indicator
            if ( subPortsString.Find( wxChar('-') ) != wxNOT_FOUND ) {
                int first = wxAtoi( subPortsString.BeforeFirst( wxChar('-') ) );
                int last = wxAtoi( subPortsString.AfterFirst( wxChar('-') ) );
                if ( last < first ) {
                    int temp = last;
                    last = first;
                    first = temp;
                }
                for ( int i = first; i <= last; i++ ) {
                    retval.push_back( i );
                }
            } else {
                retval.push_back( wxAtoi( subPortsString ) );
            }
            otherPorts = otherPorts.AfterFirst( wxChar(',') );
        }
    }
    return retval;
}

std::vector< wxString > NetworkScanner::getIPRange( wxString first, wxString last ) {
    std::vector< wxString > iprange;
    iprange.push_back( first );
    int first_address = inet_addr( first.mb_str() );
    int last_address = inet_addr( last.mb_str() );
    first_address = ntohl(first_address);
    last_address = ntohl(last_address);

    if ( last_address < first_address ) {
        int temp = last_address;
        last_address = first_address;
        first_address = temp;
    }

    for ( int ip = first_address; ip < last_address; ip++ ) {
        wxString newIp = getNextIP( ip );
        iprange.push_back( newIp );
    }

    return iprange;
}

wxString NetworkScanner::getNextIP( int ipaddress )
{
    struct in_addr address_struct;
    address_struct.s_addr = htonl(++ipaddress);

    return wxString::FromUTF8( inet_ntoa( address_struct ) );
}

void NetworkScanner::OnCheckBoxesClick(wxCommandEvent& WXUNUSED( event ) )
{
    bool enableScan = false;
    if ( RDPCheckBox->IsChecked() == true ) { enableScan = true; }
    if ( SSHCheckBox->IsChecked() == true ) { enableScan = true; }
    if ( TelnetCheckBox->IsChecked() == true ) { enableScan = true; }
    if ( VNCCheckBox->IsChecked() == true ) { enableScan = true; }
    if ( OtherPortsText->IsEmpty() == false ) { enableScan = true; }
    if ( IPFrom1->IsEmpty() == true || IPFrom2->IsEmpty() == true || IPFrom3->IsEmpty() == true || IPFrom4->IsEmpty() == true ) { enableScan = false; }
    ScanButton->Enable( enableScan );
}

void NetworkScanner::addNewConnection( RDPConnection *target ) {
    wxString filename = quickRDP::Generators::generateHex( 8 );
    RDPConnection *newCon = Resources::Instance()->getConnectionDatabase()->duplicateRDPConnection( filename, target );

    RDPFrame *newFrame = new RDPFrame( this, 0 );
    newFrame->loadRDPConnection( newCon );

    newFrame->ShowModal();
    targetsAdded++;
}

std::vector< RDPConnection* > NetworkScanner::getSelectedConnections()
{
    std::vector< RDPConnection* > retval;
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        for ( ;; ) {
            itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
            if ( itemIndex == -1 ) {
                break;
            }
            retval.push_back( ListCtrlRDPConnectionTable[ itemIndex ] );
        }
    }
    return retval;
}

void NetworkScanner::OnButtonAdd(wxCommandEvent& WXUNUSED( event ) )
{
    std::vector< RDPConnection* > targets = getSelectedConnections();
    for ( std::vector< RDPConnection* >::iterator it = targets.begin(); it != targets.end(); ++it ) {
        addNewConnection( (*it) );
    }
}

void NetworkScanner::OnListCtrlSelect(wxListEvent& WXUNUSED( event ) )
{
    if ( getSelectedConnections().empty() == false ) {
        if ( getSelectedConnections().size() > 1 ) {
            ButtonAddSelected->SetLabel( wxT("Add connections" ) );
        } else {
            ButtonAddSelected->SetLabel( wxT("Add connection" ) );
        }
        ButtonAddSelected->Enable();
    } else {
        ButtonAddSelected->Disable();
    }
}

void NetworkScanner::OnListCtrlItemActivated(wxListEvent& event)
{
    OnButtonAdd( event );
}

void NetworkScanner::OnClose(wxCommandEvent& WXUNUSED( event ) )
{
    EndModal( targetsAdded );
}

void NetworkScanner::OnQuit(wxCloseEvent& WXUNUSED( event ) )
{
    EndModal( targetsAdded );
}

void NetworkScanner::OnShowAllConnections(wxCommandEvent& WXUNUSED( event ) )
{
    redrawListCtrl();
}

void NetworkScanner::OnOtherPortsHelpClick(wxCommandEvent& WXUNUSED( event ) )
{
    ExampleDialog *example = new ExampleDialog( wxT("Define other ports to be scanned here.\nSeparate ports with comma (,) or create a range using hyphen (-).\n\nExample: 21-23,80,8080"), this );
    example->ShowModal();
    delete example;
}
