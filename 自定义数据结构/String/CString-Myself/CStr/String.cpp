#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include<string.h>
#include<iostream>


CString::CString()
{
	m_pData = new char(0);//申请一个字节，并初始化为0
}

CString::CString(const CString & str){//深拷贝
	//m_pData = str.m_pData;//浅拷贝
	int n = str.GetLenth();
	m_pData = new char[n + 1];
	strcpy(m_pData, str.m_pData);
}


CString::~CString()
{
	delete []m_pData;
}

CString::CString(const char * p){
	int nLen = strlen(p);
	m_pData = new char[nLen + 1];
	strcpy(m_pData, p);
}

CString::CString(char ch, int nRepeat ){
	m_pData = new char[nRepeat + 1];
	memset(m_pData, ch, nRepeat);
	m_pData[nRepeat] = '\0';
/*	strcpy(m_pData, &ch);
	for (int i = 0; i < nRepeat-1; ++i){
		strcat(m_pData, &ch);
	}
	*/
}

CString::CString(const char* cstr, int nLength){
	int nLen = strlen(cstr);
	if (nLen > nLength)
		nLen = nLength;
	m_pData = new char[nLen + 1];
	memcpy(m_pData, cstr, nLen);//指定长度复制
	m_pData[nLen] = '\0';
}

std::ostream& operator<<(std::ostream & out, const CString& s){//自定义输出对象
	out << s.m_pData;
	return out;
}
CString operator+(const CString& s1, const CString& s2){
	CString s ;
	int n = s1.GetLenth() + s2.GetLenth();
	s.m_pData = new char[n + 1];
	strcpy(s.m_pData, s1.m_pData);
	strcat(s.m_pData, s2.m_pData);
	return s;
}
CString& CString::operator=(const CString& s){
	int n = s.GetLenth();
	if (GetLenth() < n){
		delete []m_pData;
		m_pData = new char[n + 1];
		strcpy(m_pData, s.m_pData);
	}
	strcpy(m_pData, s.m_pData);
	return *this;
}
CString& CString::operator=(const char * str){
	int n = strlen(str);
	if (n > GetLenth()){
		delete[]m_pData;
		m_pData = new char[n + 1];
	}
	strcpy(m_pData, str);
	return *this;
}
bool operator!=(const CString& s1, const CString& s2){
	if (strcmp(s1.m_pData,s2.m_pData) != 0)
		return true;
	return false;
}
bool operator!=(const char * s1, const CString& s2){
	if (strcmp(s1, s2.m_pData) != 0)
		return true;
	return false;
}
bool operator==(const CString& s1, const CString& s2){
	if (strcmp(s1.m_pData, s2.m_pData) == 0)
		return true;
	return false;
}
bool operator<(const CString& s1, const CString& s2){
	if (strcmp(s1.m_pData, s2.m_pData) < 0)
		return true;
	return false;
}
bool operator>(const CString& s1, const CString& s2){
	if (strcmp(s1.m_pData, s2.m_pData) > 0)
		return true;
	return false;
}
CString& operator+=(CString& s1, const CString& s2){
	int n = s1.GetLenth() + s2.GetLenth();
	char *p = new char[n + 1];
	strcpy(p, s1.m_pData);
	strcat(p, s2.m_pData);
	delete s1.m_pData;
	s1.m_pData = p;
	return s1;
}