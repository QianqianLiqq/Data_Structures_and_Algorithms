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
	puts("1���������");
	puts("2����ӡ����");
	puts("3����ʾ����");
	puts("0���˳�");
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
	cout << "������һ�����֣�" << endl;
	DATA d;
	cin >> d;
	cout << "��ѡ��һ��������1-2��" << endl;
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
	cout << "��ѡ��һ��������1-2��" << endl;
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
	cout << "��ѡ��һ��������1-2��" << endl;
	int i = 0;
	cin >> i;
	if (i == 1){
		cout << "����1�ܹ���" << m_list1.getCount() << "�����ݣ�" << endl;
	}
	if (i == 2){
		cout << "����2�ܹ���" << m_list2.getCount() << "�����ݣ�" << endl;
	}

}
