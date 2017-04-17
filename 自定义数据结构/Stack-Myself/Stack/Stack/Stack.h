#pragma once
typedef int DATA;
class CStack{
	enum{COUNT=5};
	DATA m_data[COUNT];
	int m_nTop;
public:
	CStack() :m_nTop(-1){

	}
	bool isFull(){
		return m_nTop + 1 >= COUNT;
	}
	bool isEmpty(){
		return m_nTop == -1;
	}
	void push(DATA data){
		if (!isFull())
		   m_data[++m_nTop] = data;
	}
	bool pop(DATA & data){
		if (!isEmpty()){
			data = m_data[m_nTop--];
			return true;
		}
		return false;
	}
};
