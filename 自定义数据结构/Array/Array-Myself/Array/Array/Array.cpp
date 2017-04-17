#include "Array.h"
#include<iostream>

CArray::CArray()
{
	m_nSize = 0;
	m_nCount = 4;
	m_pData = new TYPE[m_nCount];
}


CArray::~CArray()
{
	delete[]m_pData;
}

void CArray::Remalloc(int nCount){
	TYPE* p = new TYPE[nCount];
	if (m_nSize>0) 
		memcpy(p, m_pData, sizeof(TYPE)*m_nSize);
	delete[]m_pData;
	m_pData = p;
	m_nCount = nCount;
}

int CArray::Add(TYPE data){
	if (m_nSize >= m_nCount)
		Remalloc(m_nSize * 2);
	m_pData[m_nSize++] = data;
	return m_nSize;
}

void CArray::SetSize(int nNewSize){
	if (nNewSize > m_nCount)
		Remalloc(nNewSize);
	m_nCount= nNewSize;
}

void CArray::RemoveAt(int nIndex, int nCount){
	if (nIndex < 0 || nIndex >= m_nSize)
		return;
	if (nIndex + nCount >= m_nSize ){
		m_nSize = nIndex;
		return;
	}
	else{
		memmove(m_pData + nIndex, m_pData + nIndex + nCount, sizeof(TYPE)*(m_nSize - nIndex - nCount));
		m_nSize -= nCount;
	}
}

void  CArray::InsertAt(int nIndex, TYPE newElement, int nCount){
	if (nCount <= 0)
		return;
	if (nIndex < 0 || nIndex > m_nSize)
		return;
	if (m_nSize + nCount > m_nCount)
		Remalloc((m_nSize + nCount) * 2);
	memmove(m_pData + nIndex + nCount, m_pData + nIndex, sizeof(TYPE)*(m_nSize - nIndex));
	int i = 0;
	while (i < nCount){
		m_pData[nIndex+i] = newElement;
		++i;
	}
	m_nSize += nCount;
}