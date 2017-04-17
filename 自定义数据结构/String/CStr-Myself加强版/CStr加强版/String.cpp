#define _CRT_SECURE_NO_WARNINGS
#include "String.h"


CString::CString()
{
	m_nLength = 0;
	m_pData = new char[1];
	m_pData[0] = '\0';
}

CString::~CString()
{
	delete[]m_pData;
}

CString::CString(const char * p){
	int nLen = strlen(p);
	m_pData = new char[nLen + 1];
	strcpy(m_pData, p);
	m_nLength = nLen;
}
CString::CString(const CString & str){
	//m_pData = str.m_pData;//浅拷贝
	int nLen = str.m_nLength;
	m_pData = new char[nLen + 1];
	strcpy(m_pData, str.m_pData);
	m_nLength = nLen;
}
CString& CString::operator=(const CString& s){
	int n = s.m_nLength;
	if (m_nLength < n){
		delete []m_pData;
		m_pData = new char[n + 1];
	}
	strcpy(m_pData, s.m_pData);
	m_nLength = n;
	return *this;
}
CString& CString::operator=(const char * str){
	int n = strlen(str);
	if (n > m_nLength){
		delete[]m_pData;
		m_pData = new char[n + 1];
	}
	strcpy(m_pData, str);
	m_nLength = n;
	return *this;
}
CString& operator+=(CString& s1, const CString& s2){
	int n = s1.m_nLength + s2.m_nLength;
	char *p = new char[n + 1];
	strcpy(p, s1.m_pData);
	//strcat(p, s2.m_pData);
	strcpy(p + s1.m_nLength, s2.m_pData);
	delete s1.m_pData;
	s1.m_pData = p;
	s1.m_nLength = n;
	return s1;
}
CString operator+(const CString& s1, const CString& s2){
	CString s;
	int n = s1.m_nLength + s2.m_nLength;
	s.m_pData = new char[n + 1];
	strcpy(s.m_pData, s1.m_pData);
	strcat(s.m_pData, s2.m_pData);
	s.m_nLength = n;
	return s;
}

int CString::Find(const char* pszSub, int iStart){
	if (iStart >= m_nLength)
		return -1;
	char *p = strstr(m_pData + iStart, pszSub);
	if (!p)
		return -1;
	return p - m_pData;
}

int CString::Find(char ch, int iStart ){
	if (iStart >= m_nLength)
		return -1;
	char *p = strchr(m_pData + iStart, ch);//str第一个参数以下标开始算
	if (!p)
		return -1;
	return p - m_pData;
}

CString& CString::MakeLower(){
/*  for (int i = 0; i < m_nLength; ++i){
		if (m_pData[i] >= 'A'&&m_pData[i] <= 'Z')
			m_pData[i] = m_pData[i] + 32;
	}
	return *this;
*/
	_strlwr(m_pData);
	return *this;
}

CString& CString::MakeUpper(){
/*	for (int i = 0; i < m_nLength; ++i){
		if (m_pData[i] >= 'a'&&m_pData[i] <= 'z')
			m_pData[i] = m_pData[i] - 32;
	}
	return *this;
*/
	_strupr(m_pData);
	return *this;
}

CString& CString::MakeReverse(){
/*	for (int i = 0; i < m_nLength / 2; ++i){
		char temp = m_pData[i];
		m_pData[i] = m_pData[m_nLength - 1 - i];
		m_pData[m_nLength - 1 - i] = temp;
	}				
	return *this;
*/
	char *p = m_pData;
	char *q = m_pData + m_nLength-1;
	while (p < q){
		char t = *p;
		*p = *q;
		*q = t;
		++p;
		--q;
	}
	return *this;
}

CString CString::Mid(int iFirst, int nCount) const{ //参数iFirst从0开始
	if (iFirst >= m_nLength)
		return CString();
	if (nCount + iFirst > m_nLength)
		nCount = m_nLength - iFirst ;
	CString str;
	delete[]str.m_pData;
	str.m_pData = new char[nCount + 1];
/*	int j = 0;
	for (int i = iFirst; i < nCount,j<nCount; ++i,++j)
		str.m_pData[j] = m_pData[i];
*/
	memcpy(str.m_pData, m_pData + iFirst , nCount);
	str.m_pData[nCount] = '\0';
	str.m_nLength = nCount;
	return str;
}

CString CString::Mid(int iFirst) const{
	if (iFirst >= m_nLength)
		return CString();
	CString str;
	delete[]str.m_pData;
	str.m_pData = new char[m_nLength-iFirst + 1];
	memcpy(str.m_pData, m_pData + iFirst , m_nLength - iFirst );
	str.m_pData[m_nLength - iFirst ] = '\0';
	str.m_nLength = m_nLength - iFirst ;
	return str;
}

CString CString::Left(int nCount) const{
	return Mid(0, nCount);
}

CString CString::Right(int nCount) const{
	return Mid(m_nLength - nCount, nCount);
}