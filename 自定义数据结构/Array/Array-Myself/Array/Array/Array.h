#pragma once
#include<assert.h>
typedef int TYPE;
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
	void SetAt(int nIndex, TYPE data){
		m_pData[nIndex] = data;
	}
	void RemoveAll(){
		m_nSize = 0;
	}
	int Add(TYPE data);
	void RemoveAt(int nIndex,int nCount=1);
	void InsertAt(int nIndex, TYPE newElement, int nCount = 1);
	void SetSize(int nNewSize);
	const TYPE* GetData() const{
		return m_pData;
	}
	TYPE* GetData(){
		return m_pData;
	}
};

