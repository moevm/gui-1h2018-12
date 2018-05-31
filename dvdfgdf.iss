; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Family Tree"
#define MyAppVersion "1.0"
#define MyAppPublisher "L_V, Inc."
#define MyAppURL "http://www.example.com/"
#define MyAppExeName "family_tree_2.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{B6587926-848B-4B54-A0D3-E332D4A351EC}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DisableProgramGroupPage=yes
OutputDir=C:\Users\Alyona\Desktop
OutputBaseFilename=Family_Tree_setup
SetupIconFile=D:\study\3_kurs\GUI\family_tree_2\deciduoustree_caducifolio_3734.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\family_tree_2.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\study\3_kurs\GUI\build-family_tree_2-Desktop_Qt_5_8_0_MinGW_32bit-Release\release\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
