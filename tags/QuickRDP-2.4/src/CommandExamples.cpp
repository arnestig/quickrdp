/**
    Copyright (C) 2010-2014 QuickRDP - Manages RDP, SSH, Telnet and VNC connections

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

#include "CommandExamples.h"
#include "Resources.h"

//(*InternalHeaders(CommandExamples)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CommandExamples)
const long CommandExamples::ID_LISTCTRL1 = wxNewId();
const long CommandExamples::ID_BUTTON1 = wxNewId();
const long CommandExamples::ID_BUTTON2 = wxNewId();
const long CommandExamples::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommandExamples,wxDialog)
	//(*EventTable(CommandExamples)
	//*)
END_EVENT_TABLE()

CommandExamples::CommandExamples(wxWindow* parent,wxWindowID id,const wxPoint& WXUNUSED(pos),const wxSize& WXUNUSED(size) )
{
	//(*Initialize(CommandExamples)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(461,154), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer2->Add(ListCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ButtonAdd = new wxButton(Panel1, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	ButtonAdd->Disable();
	BoxSizer3->Add(ButtonAdd, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonClose = new wxButton(Panel1, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(ButtonClose, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&CommandExamples::OnListCtrl1ItemSelectDeselect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&CommandExamples::OnListCtrl1ItemSelectDeselect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&CommandExamples::OnListCtrl1ItemActivated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandExamples::AddCommand);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommandExamples::OnClose);
	//*)

    #if defined(__WXMSW__)
        loadExampleCommandsWindows();
    #elif defined(__UNIX__)
        loadExampleCommandsLinux();
    #endif
	displayCommands();
}

CommandExamples::~CommandExamples()
{
	//(*Destroy(CommandExamples)
	//*)
	for ( std::map< wxString, Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
		delete (*it).second;
	}
}

void CommandExamples::loadExampleCommandsLinux()
{
	/** VLC **/
    wxString vlc_name = wxT("VLC");
    std::map< int, wxString > vlc_ConnectionProgram;
    std::map< int, wxString > vlc_ConnectionArgument;
    vlc_ConnectionProgram[ -1 ] = wxT("/usr/bin/vlc");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    vlc_ConnectionArgument[ -1 ] = wxT("http://%hostname%/stream.mp4");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool vlc_favorite = true;
    bool vlc_safety = false;
    int vlc_shortcutModifier = 0;
    int vlc_shortcutKey = 0;
    bool vlc_useSpecificCommands = false;
    Command *vlc = new Command( vlc_name, vlc_ConnectionProgram, vlc_ConnectionArgument, vlc_name, vlc_favorite, vlc_safety, vlc_shortcutModifier, vlc_shortcutKey, vlc_useSpecificCommands );
    commands[ wxT("Opens up VLC with the connection as a streaming target") ] = vlc;

	/** FTP/SFTP **/
    wxString ftp_sftp_name = wxT("FTP/SFTP");
    std::map< int, wxString > ftp_sftp_ConnectionProgram;
    std::map< int, wxString > ftp_sftp_ConnectionArgument;
    ftp_sftp_ConnectionProgram[ -1 ] = wxT("");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("/usr/bin/filezilla");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("/usr/bin/filezilla");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("/usr/bin/filezilla");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("/usr/bin/filezilla");
    ftp_sftp_ConnectionArgument[ -1 ] = wxT("");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("%username%:%password%@%hostname%:21");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("%username%:%password%@%hostname%:22");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("%username%:%password%@%hostname%:22");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("%username%:%password%@%hostname%:21");
    bool ftp_sftp_favorite = true;
    bool ftp_sftp_safety = false;
    int ftp_sftp_shortcutModifier = 2;
    int ftp_sftp_shortcutKey = 70;
    bool ftp_sftp_useSpecificCommands = true;
    Command *ftp_sftp = new Command( ftp_sftp_name, ftp_sftp_ConnectionProgram, ftp_sftp_ConnectionArgument, ftp_sftp_name, ftp_sftp_favorite, ftp_sftp_safety, ftp_sftp_shortcutModifier, ftp_sftp_shortcutKey, ftp_sftp_useSpecificCommands );
    commands[ wxT("Opens up FTP connections against RDP and VNC hosts while using SFTP protocol against Telnet and SSH connections.") ] = ftp_sftp;

    /** web browser **/
    wxString webbrowser_name = wxT("Chrome");
    std::map< int, wxString > webbrowser_ConnectionProgram;
    std::map< int, wxString > webbrowser_ConnectionArgument;
    webbrowser_ConnectionProgram[ -1 ] = wxT("/usr/bin/chromium-browser");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    webbrowser_ConnectionArgument[ -1 ] = wxT("http://%hostname%/");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool webbrowser_favorite = true;
    bool webbrowser_safety = false;
    int webbrowser_shortcutModifier = 0;
    int webbrowser_shortcutKey = 0;
    bool webbrowser_useSpecificCommands = false;
    Command *webbrowser = new Command( webbrowser_name, webbrowser_ConnectionProgram, webbrowser_ConnectionArgument, webbrowser_name, webbrowser_favorite, webbrowser_safety, webbrowser_shortcutModifier, webbrowser_shortcutKey, webbrowser_useSpecificCommands );
    commands[ wxT("Opens up Chrome browser with the connection as target") ] = webbrowser;

    /** SSH command **/
    wxString sshcommand_name = wxT("SSH command");
    std::map< int, wxString > sshcommand_ConnectionProgram;
    std::map< int, wxString > sshcommand_ConnectionArgument;
    sshcommand_ConnectionProgram[ -1 ] = wxT("/usr/bin/x-terminal-emulator");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    sshcommand_ConnectionArgument[ -1 ] = wxT("-e \"ssh %username%@%hostname% $command$\"");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool sshcommand_favorite = false;
    bool sshcommand_safety = false;
    int sshcommand_shortcutModifier = 0;
    int sshcommand_shortcutKey = 0;
    bool sshcommand_useSpecificCommands = false;
    Command *sshcommand = new Command( sshcommand_name, sshcommand_ConnectionProgram, sshcommand_ConnectionArgument, sshcommand_name, sshcommand_favorite, sshcommand_safety, sshcommand_shortcutModifier, sshcommand_shortcutKey, sshcommand_useSpecificCommands );
    commands[ wxT("Run an SSH command on target provided as a custom argument") ] = sshcommand;

    /** ping **/
    wxString ping_name = wxT("ping");
    std::map< int, wxString > ping_ConnectionProgram;
    std::map< int, wxString > ping_ConnectionArgument;
    ping_ConnectionProgram[ -1 ] = wxT("/usr/bin/x-terminal-emulator");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    ping_ConnectionArgument[ -1 ] = wxT("-e \"ping %hostname%\"");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool ping_favorite = true;
    bool ping_safety = false;
    int ping_shortcutModifier = 6;
    int ping_shortcutKey = 80;
    bool ping_useSpecificCommands = false;
    Command *ping = new Command( ping_name, ping_ConnectionProgram, ping_ConnectionArgument, ping_name, ping_favorite, ping_safety, ping_shortcutModifier, ping_shortcutKey, ping_useSpecificCommands );
    commands[ wxT("Starting a continuous ping session against the connection") ] = ping;

}

void CommandExamples::loadExampleCommandsWindows()
{
    /** mount C$ **/
    wxString mount_C_name = wxT("mount C$");
    std::map< int, wxString > mount_C_ConnectionProgram;
    std::map< int, wxString > mount_C_ConnectionArgument;
    mount_C_ConnectionProgram[ -1 ] = wxT("cmd.exe");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    mount_C_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    mount_C_ConnectionArgument[ -1 ] = wxT("/C \"net use X: /DELETE & net use X: \\\\%hostname%\\C$ %password% /USER:%username% & explorer X:\"");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    mount_C_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool mount_C_favorite = true;
    bool mount_C_safety = false;
    int mount_C_shortcutModifier = 2;
    int mount_C_shortcutKey = 67;
    bool mount_C_useSpecificCommands = false;
    Command *mount_C = new Command( mount_C_name, mount_C_ConnectionProgram, mount_C_ConnectionArgument, mount_C_name, mount_C_favorite, mount_C_safety, mount_C_shortcutModifier, mount_C_shortcutKey, mount_C_useSpecificCommands );
    commands[ wxT("Mounts the share C$ on a Windows controller and opens it in Explorer") ] = mount_C;

    /** web browser **/
    wxString webbrowser_name = wxT("Chrome");
    std::map< int, wxString > webbrowser_ConnectionProgram;
    std::map< int, wxString > webbrowser_ConnectionArgument;
    webbrowser_ConnectionProgram[ -1 ] = wxT("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    webbrowser_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    webbrowser_ConnectionArgument[ -1 ] = wxT("http://%hostname%/");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    webbrowser_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool webbrowser_favorite = true;
    bool webbrowser_safety = false;
    int webbrowser_shortcutModifier = 0;
    int webbrowser_shortcutKey = 0;
    bool webbrowser_useSpecificCommands = false;
    Command *webbrowser = new Command( webbrowser_name, webbrowser_ConnectionProgram, webbrowser_ConnectionArgument, webbrowser_name, webbrowser_favorite, webbrowser_safety, webbrowser_shortcutModifier, webbrowser_shortcutKey, webbrowser_useSpecificCommands );
    commands[ wxT("Opens up Chrome browser with the connection as target") ] = webbrowser;

    /** ping **/
    wxString ping_name = wxT("ping");
    std::map< int, wxString > ping_ConnectionProgram;
    std::map< int, wxString > ping_ConnectionArgument;
    ping_ConnectionProgram[ -1 ] = wxT("ping.exe");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    ping_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    ping_ConnectionArgument[ -1 ] = wxT("-t %hostname%");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    ping_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool ping_favorite = true;
    bool ping_safety = false;
    int ping_shortcutModifier = 6;
    int ping_shortcutKey = 80;
    bool ping_useSpecificCommands = false;
    Command *ping = new Command( ping_name, ping_ConnectionProgram, ping_ConnectionArgument, ping_name, ping_favorite, ping_safety, ping_shortcutModifier, ping_shortcutKey, ping_useSpecificCommands );
    commands[ wxT("Starting a continuous ping session against the connection") ] = ping;

    /** FTP/SFTP **/
    wxString ftp_sftp_name = wxT("FTP/SFTP");
    std::map< int, wxString > ftp_sftp_ConnectionProgram;
    std::map< int, wxString > ftp_sftp_ConnectionArgument;
    ftp_sftp_ConnectionProgram[ -1 ] = wxT("");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("C:\\Program Files (x86)\\FileZilla FTP Client\\filezilla.exe");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("C:\\Program Files (x86)\\FileZilla FTP Client\\filezilla.exe");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("C:\\Program Files (x86)\\FileZilla FTP Client\\filezilla.exe");
    ftp_sftp_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("C:\\Program Files (x86)\\FileZilla FTP Client\\filezilla.exe");
    ftp_sftp_ConnectionArgument[ -1 ] = wxT("");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("%username%:%password%@%hostname%:21");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("%username%:%password%@%hostname%:22");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("%username%:%password%@%hostname%:22");
    ftp_sftp_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("%username%:%password%@%hostname%:21");
    bool ftp_sftp_favorite = true;
    bool ftp_sftp_safety = false;
    int ftp_sftp_shortcutModifier = 2;
    int ftp_sftp_shortcutKey = 70;
    bool ftp_sftp_useSpecificCommands = true;
    Command *ftp_sftp = new Command( ftp_sftp_name, ftp_sftp_ConnectionProgram, ftp_sftp_ConnectionArgument, ftp_sftp_name, ftp_sftp_favorite, ftp_sftp_safety, ftp_sftp_shortcutModifier, ftp_sftp_shortcutKey, ftp_sftp_useSpecificCommands );
    commands[ wxT("Opens up FTP connections against RDP and VNC hosts while using SFTP protocol against Telnet and SSH connections.") ] = ftp_sftp;

	/** VLC **/
    wxString vlc_name = wxT("VLC");
    std::map< int, wxString > vlc_ConnectionProgram;
    std::map< int, wxString > vlc_ConnectionArgument;
    vlc_ConnectionProgram[ -1 ] = wxT("C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    vlc_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    vlc_ConnectionArgument[ -1 ] = wxT("http://%hostname%/stream.mp4");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    vlc_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool vlc_favorite = true;
    bool vlc_safety = false;
    int vlc_shortcutModifier = 0;
    int vlc_shortcutKey = 0;
    bool vlc_useSpecificCommands = false;
    Command *vlc = new Command( vlc_name, vlc_ConnectionProgram, vlc_ConnectionArgument, vlc_name, vlc_favorite, vlc_safety, vlc_shortcutModifier, vlc_shortcutKey, vlc_useSpecificCommands );
    commands[ wxT("Opens up VLC with the connection as a streaming target") ] = vlc;

    /** SSH command **/
    wxString sshcommand_name = wxT("SSH command (plink)");
    std::map< int, wxString > sshcommand_ConnectionProgram;
    std::map< int, wxString > sshcommand_ConnectionArgument;
    sshcommand_ConnectionProgram[ -1 ] = wxT("C:\\Program Files (x86)\\Putty\\plink.exe");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    sshcommand_ConnectionProgram[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    sshcommand_ConnectionArgument[ -1 ] = wxT("%username%@%hostname% {-pwd %password%} \"$command$\"");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::RDP ) ] = wxT("");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::TELNET ) ] = wxT("");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::SSH ) ] = wxT("");
    sshcommand_ConnectionArgument[ static_cast< int >( ConnectionType::VNC ) ] = wxT("");
    bool sshcommand_favorite = false;
    bool sshcommand_safety = false;
    int sshcommand_shortcutModifier = 0;
    int sshcommand_shortcutKey = 0;
    bool sshcommand_useSpecificCommands = false;
    Command *sshcommand = new Command( sshcommand_name, sshcommand_ConnectionProgram, sshcommand_ConnectionArgument, sshcommand_name, sshcommand_favorite, sshcommand_safety, sshcommand_shortcutModifier, sshcommand_shortcutKey, sshcommand_useSpecificCommands );
    commands[ wxT("Run an SSH command on target provided as a custom argument") ] = sshcommand;
}

void CommandExamples::displayCommands()
{
    ListCtrl1->Freeze();
    ListCtrl1->ClearAll();
    ListCtrl1->InsertColumn( 0, wxT("Name") );
    ListCtrl1->InsertColumn( 1, wxT("Description") );
    ListCtrl1->SetColumnWidth( 0, 85 );
    ListCtrl1->SetColumnWidth( 1, 350 );

    long itemIndexCounter = 0;

    for ( std::map< wxString, Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
        wxListItem item;
        item.SetId( itemIndexCounter );
        ListCtrl1->InsertItem( item );
        ListCtrl1->SetItem( itemIndexCounter, 0, (*it).second->getName()  );
        ListCtrl1->SetItem( itemIndexCounter, 1, (*it).first );
        itemIndexCounter++;
    }
    ListCtrl1->Thaw();
}

Command* CommandExamples::getCommandFromList()
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        long itemIndex = -1;
        for ( ;; ) {
            itemIndex = ListCtrl1->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
            if ( itemIndex == -1 ) {
                break;
            }
            wxString commandName = ListCtrl1->GetItemText( itemIndex );
            for ( std::map< wxString, Command* >::iterator it = commands.begin(); it != commands.end(); ++it ) {
                if ( (*it).second->getName() == commandName ) {
                    return (*it).second;
                }
            }
        }
    }
    return NULL;
}

void CommandExamples::AddCommand(wxCommandEvent& WXUNUSED(event) )
{
    Command *commandToAdd = getCommandFromList();
    if ( NULL != commandToAdd ) {
        Resources::Instance()->getCommandDatabase()->saveCommand( commandToAdd );
        EndModal( 1 );
    } else {
        EndModal( 0 );
    }
}

void CommandExamples::OnClose(wxCommandEvent& WXUNUSED(event) )
{
    EndModal( 0 );
}

void CommandExamples::OnListCtrl1ItemSelectDeselect(wxListEvent& WXUNUSED(event) )
{
    if ( ListCtrl1->GetSelectedItemCount() > 0 ) {
        ButtonAdd->Enable( true );
    } else {
        ButtonAdd->Enable( false );
    }
}

void CommandExamples::OnListCtrl1ItemActivated(wxListEvent& event)
{
    AddCommand( event );
}
