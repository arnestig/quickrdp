    !define APPNAME "QuickRDP"
    !define COMPANYNAME "Tobias Eliasson"
    !ifndef VERSION
    !define VERSION "1.2.2"
    !endif
    !define HELPURL "http://sourceforge.net/projects/quickrdp/" # "Support Information" link
    !define UPDATEURL "http://sourceforge.net/projects/quickrdp/" # "Product Updates" link
    !define ABOUTURL "http://sourceforge.net/projects/quickrdp/" # "Publisher" link
    !define INSTALLSIZE 3332

RequestExecutionLevel admin ;Require admin rights on NT6+ (When UAC is turned on)

InstallDir "$PROGRAMFILES\${APPNAME}"

    LicenseData "license.rtf"
    Name "${APPNAME}"
    Icon "../../data/${APPNAME}.ico"
    outFile "${APPNAME}-${VERSION}-setup.exe"

!include LogicLib.nsh

    page license
    page directory
    Page instfiles

!macro VerifyUserIsAdmin
UserInfo::GetAccountType
pop $0
${If} $0 != "admin" ;Require admin rights on NT4+
messageBox mb_iconstop "Administrator rights required!"
setErrorLevel 740 ;ERROR_ELEVATION_REQUIRED
quit
${EndIf}
!macroend

function .onInit
setShellVarContext all
!insertmacro VerifyUserIsAdmin
functionEnd

section "install" # Files for the install directory - to build the installer, these should be in the same directory as the install script (this file)
setOutPath "$INSTDIR\data" # Files added here should be removed by the uninstaller (see section "uninstall")
file "..\..\data\*.*" # Add any other files for the install directory (license files, app data, etc) here
file "..\..\ChangeLog"
setOutPath $INSTDIR # Files added here should be removed by the uninstaller (see section "uninstall")
file "..\..\QuickRDP.exe"

    writeUninstaller "$INSTDIR\uninstall.exe"

    createDirectory "$SMPROGRAMS\${APPNAME}"
    createShortCut "$SMPROGRAMS\${APPNAME}\${APPNAME}.lnk" "$INSTDIR\QuickRDP.exe" "" "$INSTDIR\data\QuickRDP.ico"

    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "DisplayName" "${APPNAME}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "QuietUninstallString" "$\"$INSTDIR\uninstall.exe$\" /S"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "InstallLocation" "$\"$INSTDIR$\""
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "DisplayIcon" "$\"$INSTDIR\QuickRDP.ico$\""
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "Publisher" "${APPNAME}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "HelpLink" "${HELPURL}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "URLUpdateInfo" "${UPDATEURL}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "URLInfoAbout" "${ABOUTURL}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "DisplayVersion" "${VERSION}"
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "VersionMajor" ${VERSION}
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "NoModify" 1
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "NoRepair" 1
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "EstimatedSize" ${INSTALLSIZE}
    sectionEnd

function un.onInit
SetShellVarContext all

#Verify the uninstaller - last chance to back out
    MessageBox MB_OKCANCEL "Permanantly remove ${APPNAME}?" IDOK next
        Abort
    next:
    !insertmacro VerifyUserIsAdmin
functionEnd

section "uninstall"
    delete "$SMPROGRAMS\${APPNAME}\${APPNAME}.lnk"
    rmDir "$SMPROGRAMS\${APPNAME}"

    delete $INSTDIR\QuickRDP.exe
    delete $INSTDIR\QuickRDP.ico
	delete "$INSTDIR\data\*.*"
    rmDir "$INSTDIR\data"

    delete $INSTDIR\uninstall.exe

    rmDir $INSTDIR

    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}"
sectionEnd
