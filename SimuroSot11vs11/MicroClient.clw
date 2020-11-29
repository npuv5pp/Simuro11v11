; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMicroClientDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MicroClient.h"
LastPage=0

ClassCount=6
Class1=CMicroClientApp
Class2=CMicroClientDoc
Class3=CMicroClientView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=DSetupDlg
Resource3=IDD_DIALOG1 (Chinese (P.R.C.))
Resource4=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource5=IDR_MAINFRAME (English (U.S.))

[CLS:CMicroClientApp]
Type=0
HeaderFile=MicroClient.h
ImplementationFile=MicroClient.cpp
Filter=N

[CLS:CMicroClientDoc]
Type=0
HeaderFile=MicroClientDoc.h
ImplementationFile=MicroClientDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_CONNECT

[CLS:CMicroClientView]
Type=0
HeaderFile=MicroClientView.h
ImplementationFile=MicroClientView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_DISCONNECT




[CLS:CAboutDlg]
Type=0
HeaderFile=MicroClient.cpp
ImplementationFile=MicroClient.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1]
Type=1
Class=DSetupDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TEAM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SERVER,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CHANNEL,edit,1350631552

[CLS:DSetupDlg]
Type=0
HeaderFile=DSetupDlg.h
ImplementationFile=DSetupDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=DSetupDlg
VirtualFilter=dWC

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_APP_ABOUT
CommandCount=6

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_CONNECT
Command2=ID_DISCONNECT
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_DIALOG1 (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TEAM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SERVER,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CHANNEL,edit,1350631552

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

