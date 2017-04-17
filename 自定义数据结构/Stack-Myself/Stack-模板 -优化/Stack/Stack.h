#pragma once
template<typename DATA>
class CStack{
	DATA  *m_pData;
	int m_nTop;
	int m_nCount;
public:
	CStack(int nCount=10) :m_nTop(-1){
		m_pData = new DATA[nCount];
		m_nCount = nCount;
	}
	bool isFull(){
		return m_nTop + 1 >= m_nCount;
	}
	bool isEmpty(){
		return m_nTop == -1;
	}
	void push(const DATA &data){
		if (!isFull())
		   m_pData[++m_nTop] = data;
	}
	bool pop(DATA & data){
		if (!isEmpty()){
			data = m_pData[m_nTop--];
			return true;
		}
		return false;
	}
};
