// TParseString.h: interface for the TParseString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TPARSESTRING_H__B6B1C1C4_8CBF_11D1_B242_0000C09B5CBE__INCLUDED_)
#define AFX_TPARSESTRING_H__B6B1C1C4_8CBF_11D1_B242_0000C09B5CBE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
class TParseString : public CString  
{
	public:
		TParseString() { m_iPosition = 0; };
		TParseString(LPCTSTR name) : CString(name) { m_iPosition = 0; };

		BOOL		ParseBracket(TParseString &str);
		BOOL		ParseString(CString &str);
		int		ParseInteger();
		double	ParseDouble();
		void	OverreadLeadingSpaces();

		BOOL	HasErrorOccured() const { return m_bErrorOccured; };
		int	GetPosition() const { return m_iPosition; };
		void	SetPosition(int pos);

	private:
		int	m_iPosition;
		BOOL	m_bErrorOccured;
};

#endif // !defined(AFX_TPARSESTRING_H__B6B1C1C4_8CBF_11D1_B242_0000C09B5CBE__INCLUDED_)
