#include "OS.h"
#include "stdafx.h"
#include "Agentsock.h"
#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CAgentSocket, CAsyncSocket)

CAgentSocket::CAgentSocket()
{
	m_uiPort = 0;
	m_sSocketAddress = _T("");
}


void CAgentSocket::OnReceive(int nErrorCode)
{
	CAsyncSocket::OnReceive(nErrorCode);
}


BOOL CAgentSocket::Create(UINT nSocketPort, LPCTSTR lpszSocketAddress)
{
	int	nSocketType = SOCK_DGRAM;
	long	lEvent = FD_READ | FD_WRITE | FD_ACCEPT | FD_CONNECT | FD_CLOSE;

	// create the socket
	if (Socket(nSocketType, lEvent))
	{
		// try to bind the socket to any address
		if (Bind(nSocketPort, lpszSocketAddress))
			return TRUE;
		
		// an error occured
		int nResult = GetLastError();
		Close();
		WSASetLastError(nResult);
	}
	return FALSE;
}


BOOL CAgentSocket::Bind(UINT nSocketPort, LPCTSTR lpszSocketAddress)
{
	int	result;

	// bind to INADDR_ANY
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockAddr.sin_port = htons(0);
	result = CAsyncSocket::Bind((SOCKADDR*)&sockAddr, sizeof(sockAddr));

	// set the proper values of port and address for the following SendTo commands
	memset(&sockAddr, 0, sizeof(sockAddr));
	LPSTR lpszAscii = (LPTSTR)lpszSocketAddress;
   sockAddr.sin_family			= AF_INET ;
   sockAddr.sin_addr.s_addr	= inet_addr(lpszAscii) ;
	if (sockAddr.sin_addr.s_addr == INADDR_NONE)
	{
		// get the address from a nameserver
		LPHOSTENT lphost;
		lphost = gethostbyname(lpszAscii);
		if (lphost != NULL)
			sockAddr.sin_addr.s_addr = ((LPIN_ADDR)lphost->h_addr)->s_addr;
		else
		{
			WSASetLastError(WSAEINVAL);
			return FALSE;
		}
	}
	sockAddr.sin_port	= htons((u_short)nSocketPort) ;
	
	// return the result of the Bind command
	return result;
}


int CAgentSocket::ReceiveFrom(void* lpBuf, int nBufLen, CString& rSocketAddress
										, UINT& rSocketPort, int nFlags)
{
	// try to receive data
	memset(&sockAddr, 0, sizeof(sockAddr));
	int nSockAddrLen = sizeof(sockAddr);
	int nResult = CAsyncSocket::ReceiveFrom(lpBuf, nBufLen, (SOCKADDR*)&sockAddr
														 , &nSockAddrLen, nFlags);
	if(nResult != SOCKET_ERROR)
	{
		// succesfull
		rSocketPort = ntohs(sockAddr.sin_port);
		rSocketAddress = inet_ntoa(sockAddr.sin_addr);
	}

	return nResult;
}


int CAgentSocket::SendTo(const void* lpBuf, int nBufLen, UINT nHostPort
								 , LPCTSTR lpszHostAddress, int nFlags)
{
	// send the buffer
	return CAsyncSocket::SendTo(lpBuf, nBufLen, (SOCKADDR*)&sockAddr, sizeof(sockAddr), nFlags);
}

