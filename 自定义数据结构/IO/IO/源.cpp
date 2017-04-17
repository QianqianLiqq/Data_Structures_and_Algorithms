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
	out << "我的学号是：" << nID << endl;
	out << "我的姓名是：" << sName << endl;
	out << "我的成绩是：" << fMath << endl;
	system("pause");
	return 0;
}