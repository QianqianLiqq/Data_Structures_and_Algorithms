#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Input.h"
#include"Output.h"

CInput in;
COutput out;
int main(){
	int nID = 10001;
	float fMath = 95.5;
	char sName[20];
	in >> nID >> sName >> fMath;
	out << "�ҵ�ѧ���ǣ�" << nID << endl;
	out << "�ҵ������ǣ�" << sName << endl;
	out << "�ҵĳɼ��ǣ�" << fMath << endl;
	system("pause");
	return 0;
}