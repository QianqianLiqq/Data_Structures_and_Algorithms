#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string.h>
#include<iostream>
class CString
{
	char * m_pData;
public:
	CString();
	CString(const char * p);
	CString(const CString & str);
	CString(char ch, int nRepeat =1);//串内有n个ch字符
	CString(const char* cstr, int nLength);//取前几个字符
	~CString();
	int GetLenth() const{
		return strlen(m_pData);
	}
	operator const char *(){ 
		return m_pData;
	}
	char operator[](int nindex) const{
		return m_pData[nindex];
	}
	friend std::ostream& operator<<(std::ostream & out, const CString& s);
	friend CString operator+(const CString& s1, const CString& s2);
	CString& operator=(const CString& s);
	CString& operator=(const char * str);
	friend bool operator!=(const CString& s1, const CString& s2);
	friend bool operator!=(const char * s1, const CString& s2);
	friend bool operator!=(const CString& s1, const char * s2);
	friend bool operator==(const CString& s1, const CString& s2);
	friend bool operator<(const CString& s1, const CString& s2);
	friend bool operator>(const CString& s1, const CString& s2);
	friend bool operator<=(const CString& s1, const CString& s2);
	friend bool operator>=(const CString& s1, const CString& s2);
	friend CString& operator+=(CString& s1, const CString& s2);
};

