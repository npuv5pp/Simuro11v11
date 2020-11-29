// BaseAgent.h: interface for the CBaseAgent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEAGENT_H__7FCEA561_5114_11D1_B242_0000C09B5CBE__INCLUDED_)
#define AFX_BASEAGENT_H__7FCEA561_5114_11D1_B242_0000C09B5CBE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Agentsock.h"
class CMicroClientDoc;
class CBaseAgent : public CAgentSocket
{
	public:

		CBaseAgent();
		CBaseAgent(CMicroClientDoc* m_pDoc);
		virtual ~CBaseAgent();
		BOOL	ConnectAgent(LPCTSTR lpszTeam, LPCTSTR lpszServer, UINT nPort);
		void	DisconnectAgent(void);

		// communication functions
		virtual void OnReceive(int nErrorCode);
		void SendMsg(CString& strText);
	
		// overridables
		virtual void OnCreatedSocket();
		virtual void OnSentMessage(LPCTSTR message) {};
		virtual void OnReceivedMessage(LPCTSTR message) {};
		
		virtual void OnErrorCreatingSocket() {};
		virtual void OnErrorSendingMessage() {};
		virtual void OnErrorReceivingMessage() {};
		// the agents actions


		// attribute fuctions
		BOOL	IsConnected() { return m_bConnected; };
		void	SetSide(int side) { m_iSide = side; };

	
	protected:

		CString			m_strTeam;	// name of the team the player is in
		int				m_iSide;		// side on which playing
		int				m_iNumber;	// number of the player
	
		BOOL				m_bConnected;	// true, if the agent is currently connected
	public:
		void SendCommand();
		CString teamname;
		BOOL ParseObject(LPCTSTR str);
		int m_iTime;
		void ParseSee(LPCTSTR str);
		int m_iPlayMode;
		void ParseInit(LPCTSTR str);
		void ParseMessage(LPCTSTR str);
		CMicroClientDoc* m_pDoc;
		send_to_team teaminfo;

};

#endif // !defined(AFX_BASEAGENT_H__7FCEA561_5114_11D1_B242_0000C09B5CBE__INCLUDED_)
