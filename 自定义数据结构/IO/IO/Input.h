#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
class CInput
{
public:
	CInput();
	~CInput();

	CInput& operator>>(int &i){ //������ֵΪvoid������������>>����
		scanf_s("%d", &i);
		return *this;
	}
	CInput& operator>>(short &s){
		scanf_s("%d", &s);
		return *this;
	}
	CInput& operator>>(char &c){
		fflush(stdin);//getchar��%cǰ��������һ�䣬������
		//scanf("%d", &c);
		c = getchar();
		return *this;
	}
	CInput& operator>>(const char * str){
		scanf("%s", str);
		return *this;
	}
	CInput& operator>>(float &f){
		scanf_s("%f", &f);
		return *this;
	}
	CInput& operator>>(double &dl){
		scanf_s("%lf", &dl);
		return *this;
	}
};

