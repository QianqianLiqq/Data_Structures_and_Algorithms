#pragma once
#include<assert.h>
template<typename TYPE,typename ARG_TYPE=const TYPE&>
class CArray
{
	int m_nSize;//有效数据数量
	int m_nCount;//资源数量
	TYPE * m_pData;
	void Remalloc(int nCount);
public:
	CArray();
	~CArray();
	int GetSize() const{
		return m_nSize;
	}
	TYPE& GetAt(int nIndex){
		return m_pData[nIndex];
	}
	TYPE GetAt(int nIndex) const{
		//assert(nIndex >= 0 && nIndex < m_nSize);
		return m_pData[nIndex];
	}
	TYPE& operator[](int nIndex){
		return m_pData[nIndex];
	}
	TYPE operator[](int nIndex) const{
		return m_pData[nIndex];
	}
	void SetAt(int nIndex, ARG_TYPE data){
		m_pData[nIndex] = data;
	}
	void RemoveAll(){
		m_nSize = 0;
	}
	int Add(ARG_TYPE data);
	void RemoveAt(int nIndex,int nCount=1);
	void InsertAt(int nIndex, ARG_TYPE newElement, int nCount = 1);
	void SetSize(int nNewSize);
	const TYPE* GetData() const{
		return m_pData;
	}
	TYPE* GetData(){
		return m_pData;
	}
};

template<typename TYPE, typename ARG_TYPE = const TYPE&>
CArray<TYPE, ARG_TYPE>::CArray()
{
	m_nSize = 0;
	m_nCount = 4;
	m_pData = new TYPE[m_nCount];
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
CArray<TYPE, ARG_TYPE>::~CArray()
{
	delete[]m_pData;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void CArray<TYPE, ARG_TYPE>::Remalloc(int nCount){
	TYPE* p = new TYPE[nCount];
	if (m_nSize>0)
		memcpy(p, m_pData, sizeof(TYPE)*m_nSize);
	delete[]m_pData;
	m_pData = p;
	m_nCount = nCount;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
int CArray<TYPE, ARG_TYPE>::Add(ARG_TYPE data){
	if (m_nSize >= m_nCount)
		Remalloc(m_nSize * 2);
	m_pData[m_nSize++] = data;
	return m_nSize;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void CArray<TYPE, ARG_TYPE>::SetSize(int nNewSize){
	if (nNewSize > m_nCount)
		Remalloc(nNewSize);
	m_nCount = nNewSize;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void CArray<TYPE, ARG_TYPE>::RemoveAt(int nIndex, int nCount){
	if (nIndex < 0 || nIndex >= m_nSize)
		return;
	if (nIndex + nCount >= m_nSize){
		m_nSize = nIndex;
		return;
	}
	else{
		memmove(m_pData + nIndex, m_pData + nIndex + nCount, sizeof(TYPE)*(m_nSize - nIndex - nCount));
		m_nSize -= nCount;
	}
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void  CArray<TYPE, ARG_TYPE>::InsertAt(int nIndex, ARG_TYPE newElement, int nCount){
	if (nCount <= 0)
		return;
	if (nIndex < 0 || nIndex > m_nSize)
		return;
	if (m_nSize + nCount > m_nCount)
		Remalloc((m_nSize + nCount) * 2);
	memmove(m_pData + nIndex + nCount, m_pData + nIndex, sizeof(TYPE)*(m_nSize - nIndex));
	int i = 0;
	while (i < nCount){
		m_pData[nIndex + i] = newElement;
		++i;
	}
	m_nSize += nCount;
}