#include "OS.h"
#include "stdafx.h"
#include "Agentsock.h"
#include <iostream.h>
#include "MicroClientDoc.h"
#include "TParseString.h"
#include "StrategySystem.h"
#include "BaseAgent.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern Robot2 r[2][11];
extern Robot3 op;
extern Robot1 theball;
extern CStrategySystem* thePlannerR;
extern CStrategySystem* thePlannerL;

//extern FILE* fp;
#define MAX_MSG_LENGTH 1500
CBaseAgent::CBaseAgent()
{
	m_bConnected = FALSE;
	m_iSide = LEFT_TO_RIGHT;
	m_iNumber = 0;
}

CBaseAgent::CBaseAgent(CMicroClientDoc* m_Doc)
{
	m_pDoc=m_Doc;
	m_bConnected = FALSE;
	m_iSide = LEFT_TO_RIGHT;
	m_iNumber = 0;
}
CBaseAgent::~CBaseAgent()
{
	DisconnectAgent();
}

BOOL CBaseAgent::ConnectAgent(LPCTSTR lpszTeam, LPCTSTR lpszServer, UINT nPort)
{
	// is the agent already connected (should not happen) 
	if (m_bConnected)
		return FALSE;

	// create the datagram socket
	if (!Create(nPort, lpszServer))
	{
		// socket could not be created
		OnErrorCreatingSocket();
		return FALSE;
	}
	else
	{
		m_bConnected = TRUE;
		m_strTeam = lpszTeam;
		OnCreatedSocket();
		Sleep(100);
		return TRUE;
	}
}
void CBaseAgent::OnCreatedSocket()
{
	CString	message;

	// send the (init team) command
	message.Format("(init %s (version 4.00))", (LPCTSTR) m_strTeam);
	SendMsg(message);
}

void CBaseAgent::DisconnectAgent()
{
	// is the socket active ?
	if (m_bConnected)
	{
		BYTE Buffer[50];

		ShutDown();
		while(Receive(Buffer,50) > 0);
		Close();
	}
	m_bConnected = FALSE;
}

void CBaseAgent::SendMsg(CString& strText)
{
	int		iLength;
	
	// send the buffer
	iLength = SendTo(strText, strText.GetLength(), GetPort(), GetAddress(), 0);
	if (iLength == strText.GetLength())
		OnSentMessage((LPCTSTR) strText);
	else
	{
		// an error occured
		#ifdef _DEBUG
			afxDump << "error writing to socket\n";
		#endif
		OnErrorSendingMessage();
	}
}

void CBaseAgent::OnReceive(int iError)
{
	char		buffer[MAX_MSG_LENGTH];
	int		iLength = 0;
	UINT		iPort = GetPort();
	int		iPosition = 0;

	// first call base classes method
	CAgentSocket::OnReceive(iError);

	// read a message from the socket
	iLength = ReceiveFrom(buffer, MAX_MSG_LENGTH, GetAddress(), iPort, 0);
	// the port may have changed
	SetPort(iPort);

	if (iLength > 0)
	{
		//OnReceivedMessage((LPCTSTR) buffer);
		ParseMessage((LPCTSTR) buffer);
		if(m_iSide==LEFT_TO_RIGHT)
		{
			thePlannerL->ReceiveData(theball,r[0][0],r[0][1],r[0][2],r[0][3],r[0][4],
				r[0][5],r[0][6],r[0][7],r[0][8],r[0][9],r[0][10],op);
			thePlannerL->Action();
		}
		else if(m_iSide==RIGHT_TO_LEFT)
		{
			thePlannerR->ReceiveData(theball,r[0][0],r[0][1],r[0][2],r[0][3],r[0][4],
				r[0][5],r[0][6],r[0][7],r[0][8],r[0][9],r[0][10],op);
			thePlannerR->Action();

		}
		SendCommand();
	}
	else
	{
		// an error occured
		#ifdef _DEBUG
			afxDump << "error reading socket\n";
		#endif
		OnErrorReceivingMessage();
	}
}


void CBaseAgent::ParseMessage(LPCTSTR str)
{
	switch(str[1])
	{
		case 's':
			if (str[3] == 'e')

			ParseSee(str);
			break;
		case 'i':
			AfxMessageBox("Init successful");
			ParseInit(str);
			break;
	}
	//return TRUE;
}

void CBaseAgent::ParseInit(LPCTSTR str)
{

	TParseString	msg(str);
	CString			tmp;
//	int				number;

	// get the side
	if ((msg.GetLength() > 6) && (msg.GetAt(6) == 'r'))
	{
		AfxMessageBox("right right");
		SetSide(RIGHT_TO_LEFT);
	}
	else
	{
		SetSide(LEFT_TO_RIGHT);
	}


	//return TRUE;
}

void CBaseAgent::ParseSee(LPCTSTR str)
{
	TParseString	msg(str);
	TParseString	strObject;
	
	msg.SetPosition(5);
	m_iTime = msg.ParseInteger();
	if (msg.HasErrorOccured())
		return;
	
	while (msg.ParseBracket(strObject))
	{
		if (!ParseObject(strObject))
		{
			#ifdef _DEBUG
				CString error;
				error.Format(" : error parsing object info at position %d !\n", strObject.GetPosition());
				afxDump << error << strObject;
			#endif
		}
	}
}

BOOL CBaseAgent::ParseObject(LPCTSTR str)
{
	TParseString	msg(str);
	TParseString	name;
	CString		teamname;
	int team;
	int iNum;
	int x;
	int y;
	double angle;

	// read the objects name bracket
	if (!msg.ParseBracket(name))//name="player TeamName TeamNum"
		return FALSE;
	x=msg.ParseInteger();
	if (msg.HasErrorOccured())
	{
	}
	y=msg.ParseInteger();
	if (msg.HasErrorOccured())
	{
	}
	angle=msg.ParseDouble();
	if(msg.HasErrorOccured())
	{
	}
	switch (name.GetAt(0))
	{
		// it is a player
		case 'P':
		case 'p':
			name.SetPosition(7);
			// read the teamname
			if (name.ParseString(teamname))
			{
				// ist it my team ?
				if (teamname.Compare(_T(name)) == 0)
					team = OWN_TEAM;
				else
					team = OTHER_TEAM;

				// read player number
				iNum = name.ParseInteger();
				if (msg.HasErrorOccured())
				{
				}
				
			}
			switch(iNum)
			{
			case 1:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][0].position.x=x;
					r[0][0].position.y=y;
					r[0][0].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position1.x=x;
					op.position1.y=y;
				}
				break;
			case 2://左方二号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][1].position.x=x;
					r[0][1].position.y=y;
					r[0][1].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position2.x=x;
					op.position2.y=y;
				}
				break;
			case 3://左方三号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][2].position.x=x;
					r[0][2].position.y=y;
					r[0][2].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position3.x=x;
					op.position3.y=y;
				}
				break;
			case 4://左方四号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][3].position.x=x;
					r[0][3].position.y=y;
					r[0][3].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position4.x=x;
					op.position4.y=y;
				}
				break;
			case 5://左方五号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][4].position.x=x;
					r[0][4].position.y=y;
					r[0][4].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position5.x=x;
					op.position5.y=y;
				}
				break;
			case 6://左方六号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][5].position.x=x;
					r[0][5].position.y=y;
					r[0][5].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position6.x=x;
					op.position6.y=y;
				}
				break;
			case 7://左方七号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][6].position.x=x;
					r[0][6].position.y=y;
					r[0][6].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position7.x=x;
					op.position7.y=y;
				}
				break;
			case 8://左方八号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][7].position.x=x;
					r[0][7].position.y=y;
					r[0][7].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position8.x=x;
					op.position8.y=y;
				}
				break;
			case 9://左方九号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][8].position.x=x;
					r[0][8].position.y=y;
					r[0][8].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position9.x=x;
					op.position9.y=y;
				}
				break;
			case 10://左方十号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][9].position.x=x;
					r[0][9].position.y=y;
					r[0][9].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position10.x=x;
					op.position10.y=y;
				}
				break;
			case 11://左方十一号队员的坐标
				if(m_iSide==LEFT_TO_RIGHT)
				{
					r[0][10].position.x=x;
					r[0][10].position.y=y;
					r[0][10].angle=(int)angle;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					op.position11.x=x;
					op.position11.y=y;
				}
				break;
			//下面的是从右向左进攻的队员的坐标处理
			case 12:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position1.x=x;
					op.position1.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)//右方一号队员坐标
				{
					r[0][0].position.x=x;
					r[0][0].position.y=y;
					r[0][0].angle=(int)angle;
				}
				break;
			case 13:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position2.x=x;
					op.position2.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][1].position.x=x;
					r[0][1].position.y=y;
					r[0][1].angle=(int)angle;
				}
				break;
			case 14:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position3.x=x;
					op.position3.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][2].position.x=x;
					r[0][2].position.y=y;
					r[0][2].angle=(int)angle;
				}
				break;
			case 15:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position4.x=x;
					op.position4.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][3].position.x=x;
					r[0][3].position.y=y;
					r[0][3].angle=(int)angle;
				}
				break;
			case 16:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position5.x=x;
					op.position5.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][4].position.x=x;
					r[0][4].position.y=y;
					r[0][4].angle=(int)angle;
				}
				break;
			case 17:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position6.x=x;
					op.position6.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][5].position.x=x;
					r[0][5].position.y=y;
					r[0][5].angle=(int)angle;
				}
				break;
			case 18:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position7.x=x;
					op.position7.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][6].position.x=x;
					r[0][6].position.y=y;
					r[0][6].angle=(int)angle;
				}
				break;
			case 19:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position8.x=x;
					op.position8.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][7].position.x=x;
					r[0][7].position.y=y;
					r[0][7].angle=(int)angle;
				}
				break;
			case 20:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position9.x=x;
					op.position9.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][8].position.x=x;
					r[0][8].position.y=y;
					r[0][8].angle=(int)angle;
				}
				break;	
			case 21:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position10.x=x;
					op.position10.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][9].position.x=x;
					r[0][9].position.y=y;
					r[0][9].angle=(int)angle;
				}
				break;
			case 22:
				if(m_iSide==LEFT_TO_RIGHT)
				{
					op.position11.x=x;
					op.position11.y=y;
				}
				else if(m_iSide==RIGHT_TO_LEFT)
				{
					r[0][10].position.x=x;
					r[0][10].position.y=y;
					r[0][10].angle=(int)angle;
				}
				break;				
			}
			break;
		case 'b':
		case 'B':
			theball.position.x=x;
			theball.position.y=y;
			break;
	}
	return TRUE;

}

void CBaseAgent::SendCommand()
{
	CString msg;
	if(m_iSide==LEFT_TO_RIGHT)
	{
		msg.Format("((player left 1) %d %d) ((player left 2) %d %d) ((player left 3) %d %d) ((player left 4) %d %d) ((player left 5) %d %d) ((player left 6) %d %d) ((player left 7) %d %d) ((player left 8) %d %d) ((player left 9) %d %d) ((player left 10) %d %d) ((player left 11) %d %d)",
		thePlannerL->command[2],thePlannerL->command[3],
		thePlannerL->command[5],thePlannerL->command[6],
		thePlannerL->command[8],thePlannerL->command[9],
		thePlannerL->command[11],thePlannerL->command[12],
		thePlannerL->command[14],thePlannerL->command[15],
		thePlannerL->command[17],thePlannerL->command[18],
		thePlannerL->command[20],thePlannerL->command[21],
		thePlannerL->command[23],thePlannerL->command[24],
		thePlannerL->command[26],thePlannerL->command[27],
		thePlannerL->command[29],thePlannerL->command[30],
		thePlannerL->command[32],thePlannerL->command[33]);
	}
	else if(m_iSide==RIGHT_TO_LEFT)
	{
		msg.Format("((player right 1) %d %d) ((player right 2) %d %d) ((player right 3) %d %d) ((player right 4) %d %d) ((player right 5) %d %d) ((player right 6) %d %d) ((player right 7) %d %d) ((player right 8) %d %d) ((player right 9) %d %d) ((player right 10) %d %d) ((player right 11) %d %d)",
		thePlannerR->command[2],thePlannerR->command[3],
		thePlannerR->command[5],thePlannerR->command[6],
		thePlannerR->command[8],thePlannerR->command[9],
		thePlannerR->command[11],thePlannerR->command[12],
		thePlannerR->command[14],thePlannerR->command[15],
		thePlannerR->command[17],thePlannerR->command[18],
		thePlannerR->command[20],thePlannerR->command[21],
		thePlannerR->command[23],thePlannerR->command[24],
		thePlannerR->command[26],thePlannerR->command[27],
		thePlannerR->command[29],thePlannerR->command[30],
		thePlannerR->command[32],thePlannerR->command[33]);
	}

	SendMsg(msg);

}

