#pragma once
#include "List1.h"
class CTest
{
	
public:
	CTest();
	~CTest();
private:
	CList1 m_list1;
	CList1 m_list2;
public:
	int Menu();
	void Input();
	void Print();
	void getCount();
};

