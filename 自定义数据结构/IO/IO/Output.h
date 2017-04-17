#pragma once
#include<iostream>
class COutput
{
public:
	COutput();
	~COutput();

	COutput& operator<<(int i){
		printf("%d", i);
		return *this;
	}
	COutput& operator<<(short s){
		printf("%d", s);
		return *this;
	}
	COutput& operator<<(char c){
		printf("%c", c);
		return *this;
	}
	COutput& operator<<(const char * str){
		printf(str);
		return *this;
	}
	COutput& operator<<(float f){
		printf("%f", f);
		return *this;
	}
	COutput& operator<<(double dl){
		printf("%lf", dl);
		return *this;
	}

};
#define endl "\n"
