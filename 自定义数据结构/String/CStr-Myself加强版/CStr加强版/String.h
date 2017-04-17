#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
class CString
{
	int m_nLength;
	char * m_pData;
public:
	CString();
	~CString();
	int GetLength() const{
		return m_nLength;
	}
	CString(const char * p);
	CString(const CString & str);
	operator const char *(){
		return m_pData;//特殊的返回值，因为返回值也为const char *
	}
	CString& operator=(const CString& s);
	CString& operator=(const char * str);
	friend CString& operator+=(CString& s1, const CString& s2);
	char operator[](int nindex) const{
		return m_pData[nindex];
	}
	char& operator[](int nindex) {
		return m_pData[nindex];
	}
	friend CString operator+(const CString& s1, const CString& s2);
	int Find(const char* pszSub, int iStart = 0);
	int Find(char ch, int iStart = 0);
	CString& MakeLower();
	CString& MakeUpper();
	CString& MakeReverse();
	CString Mid(int iFirst, int nCount) const;
	CString Mid(int iFirst) const;
	CString Left(int nCount) const;
	CString Right(int nCount) const;
};

