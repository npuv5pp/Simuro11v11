// TParseString.cpp: implementation of the TParseString class.
//
//////////////////////////////////////////////////////////////////////

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include "stdafx.h"
#include "TParseString.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


BOOL TParseString::ParseBracket(TParseString &retString)
{
	int		iNoOfOpenBrackets = 1;
	int		iRightPosition = m_iPosition + 1;	
	int		iLen = GetLength();
	m_bErrorOccured = FALSE;
	// iposition must index an opening bracket
	if ((m_iPosition >= iLen) || GetAt(m_iPosition) != '(' )
		return FALSE;

	while (iNoOfOpenBrackets > 0)
	{
		// reached the end of the string ? error
		if (iRightPosition >= iLen)
			return FALSE;

		// look at the next character
		switch (GetAt(iRightPosition))
		{
			case '(':
				iNoOfOpenBrackets++;
				break;

			case ')':
				iNoOfOpenBrackets--;
				break;
		}
		iRightPosition++;
	}
	retString.CString::operator=(Mid(m_iPosition + 1, iRightPosition - m_iPosition - 2));	
	m_iPosition = iRightPosition + 1;
	return TRUE;
}

BOOL TParseString::ParseString(CString &str)
{
	int		iRightPos;
	BOOL		bReady = FALSE;
	int		len = GetLength();
	char		tmp;

	m_bErrorOccured = FALSE;
	OverreadLeadingSpaces();
	iRightPos = m_iPosition + 1;

	// check, if there is a string
	if (m_iPosition - 1 >= len)
	{
		// the expected string is not there
		m_iPosition++;
		return FALSE;
	}

	// search for a ' ' or ')'
	bReady = FALSE;
	while (!bReady && (iRightPos < len))
	{
		tmp = GetAt(iRightPos);
		switch (tmp)
		{
			case ' ':
			case ')':
			case '\r':
			case '\n':
				bReady = TRUE;
				break;
			
			default:
				iRightPos++;
		}
	}

	// get the string
	str = Mid(m_iPosition, iRightPos - m_iPosition);
	m_iPosition = iRightPos + 1;

	return TRUE;
}

int TParseString::ParseInteger()
{
	int	iValue = 0;
	BOOL	bSign = FALSE;
	BOOL	bReady = FALSE;
	char	cChar;
	int	len = GetLength();

	m_bErrorOccured = TRUE;
	OverreadLeadingSpaces();
	// read in the number
	while (!bReady && (m_iPosition < len))
	{
		cChar = GetAt(m_iPosition);
		switch(cChar)
		{
			case '-':
				// only one - sign expected
				bSign = TRUE;
				m_iPosition++;
				break;
			
			case '+':
				m_iPosition++;
				break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				iValue = 10 * iValue + cChar - '0';
				m_bErrorOccured = FALSE;
				m_iPosition++;
				break;
			
			case ')':
			case ' ':
				m_iPosition++;
				// no break here

			default:
				bReady = TRUE;
		}
	}
	
	// convert the number if neccessary
	if (bSign)
		iValue = -iValue;
	
	return iValue;
}


double TParseString::ParseDouble()
{
	double	dValue = 0.0;
	double	dNumber;
	BOOL		bSign = FALSE;
	BOOL		bReady = FALSE;
	BOOL		bDot = FALSE;
	double	dDivisor = 1.0;
	char		cChar;
	int		len = GetLength();

	m_bErrorOccured = TRUE;
	// read in the number
	while (!bReady && (m_iPosition < len))
	{
		cChar = GetAt(m_iPosition);
		switch(cChar)
		{
			case '-':
				// only one - sign expected
				bSign = TRUE;
				m_iPosition++;
				break;
			
			case '+':
				m_iPosition++;
				break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				dValue = 10.0 * dValue + (double) (cChar - '0');
				dDivisor *= 10.0;
				m_bErrorOccured = FALSE;
				m_iPosition++;
				break;
			
			case '.':
			case ',':
				dDivisor = 1.0;
				bDot = TRUE;
				m_iPosition++;
				break;

			case ')':
			case ' ':
				m_iPosition++;
				// no break here

			default:
				bReady = TRUE;
		}
	}
	
	// convert the number if neccessary
	if (bDot)
		dNumber = dValue / dDivisor;
	else
		dNumber = dValue;

	if (bSign)
		dNumber = -dNumber;
	
	return dNumber;
}


void TParseString::OverreadLeadingSpaces()
{
	char		tmp;

	// overread inital spaces, returns and new lines
	while (m_iPosition < GetLength())
	{
		tmp = GetAt(m_iPosition);
		switch (tmp)
		{
			case ' ':
			case '\r':
			case '\n':
				m_iPosition++;
				break;
		
			default:
				return;
		}
	}
}


void TParseString::SetPosition(int pos)
{
	if (pos >= GetLength())
	{
		m_iPosition = GetLength() - 1;
		if (m_iPosition < 0)
			m_iPosition = 0;
	}	
	else if (pos < 0)
		m_iPosition = 0;
	else
		m_iPosition = pos; 
}
