#include<iostream>
#include"Complex.h"
using namespace std;
int main(){
	CComplex<double> c1(3.5, 5.6);
	CComplex<int> c2(1, 2);
	c1.Print();
	c2.Print();
	system("pause");
	return 0;
}