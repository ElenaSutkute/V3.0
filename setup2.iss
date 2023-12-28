[Setup]
AppName=Vardenis-Pavardenis
AppVersion=1.5
DefaultDirName={pf}\VU\Vardenis-Pavardenis
DefaultGroupName=VU
OutputDir=Output

[Files]
Source: "C:\Users\Lenovo\Documents\c++\V2.0\v1.5.exe"; DestDir: "{pf}\VU\Vardenis-Pavardenis"; Flags: recursesubdirs createallsubdirs

[Icons]
Name: "{commondesktop}\Vardenis-Pavardenis"; Filename: "{pf}\VU\Vardenis-Pavardenis\v1.5.exe"
Name: "{commonstartmenu}\VU\Vardenis-Pavardenis"; Filename: "{pf}\VU\Vardenis-Pavardenis\v1.5.exe"

[Run]
Filename: "{pf}\VU\Vardenis-Pavardenis\v1.5.exe"; Flags: postinstall shellexec runasoriginaluser
