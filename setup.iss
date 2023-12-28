[Setup]
AppName=Vardenis-Pavardenis
AppVersion=1.5
DefaultDirName={pf}\VU\Vardenis-Pavardenis
DefaultGroupName=VU
OutputDir=Output


[Files]
Source: "C:\Users\Lenovo\Documents\c++\V2.0\studentai.txt"; DestDir: "{pf}\VU\Vardenis-Pavardenis"; Flags: recursesubdirs createallsubdirs


[Icons]
Name: "{commondesktop}\Vardenis-Pavardenis"; Filename: "{pf}\VU\Vardenis-Pavardenis\studentai.txt"
Name: "{commonstartmenu}\VU\Vardenis-Pavardenis"; Filename: "{pf}\VU\Vardenis-Pavardenis\studentai.txt"

[Run]
Filename: "{pf}\VU\Vardenis-Pavardenis\studentai.txt"; Flags: postinstall shellexec runasoriginaluser
