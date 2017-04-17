#include "Test.h"
#include<iostream>
using namespace std;

CTest::CTest()
{
}


CTest::~CTest()
{
}


int CTest::Menu()
{
	puts("1、添加数据");
	puts("2、打印数据");
	puts("3、显示长度");
	puts("0、退出");
	int i;
	cin >> i;
	switch (i){
	case 1:Input();
		break;
	case 2:Print();
		break;
	case 3:getCount();
		break;
	case 0:
		break;
	}
	return i;
}


void CTest::Input()
{
	cout << "请输入一个数字：" << endl;
	DATA d;
	cin >> d;
	cout << "请选择一个链表：（1-2）" << endl;
	int i = 0;
	cin >> i;
	if (i == 1){
		m_list1.addHead(d);
	}
	if (i == 2){
		m_list2.addHead(d);
	}	
}




void CTest::Print(){
	cout << "请选择一个链表：（1-2）" << endl;
	int i = 0;
	cin >> i;
	if (i == 1){
		m_list1.Print();
	}
	if (i == 2){
		m_list2.Print();
	}
}


void CTest::getCount(){
	cout << "请选择一个链表：（1-2）" << endl;
	int i = 0;
	cin >> i;
	if (i == 1){
		cout << "链表1总共有" << m_list1.getCount() << "条数据！" << endl;
	}
	if (i == 2){
		cout << "链表2总共有" << m_list2.getCount() << "条数据！" << endl;
	}

}
