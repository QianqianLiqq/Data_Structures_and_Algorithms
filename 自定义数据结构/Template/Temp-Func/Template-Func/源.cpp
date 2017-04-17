#include<iostream>
//using namespace std;
/*
void swap(int & a, int & b){
	int t = a;
	a = b;
	b = t;
}
void swap(double & a, double & b){
	double t = a;
	a = b;
	b = t;
}
*/
template<class T>
void swap(T & a, T & b){
	T t = a;
	a = b;
	b = t;
}
int main(){
	int i = -1, j = 10;
	double x = 1.1, y = 2.2;
	swap(i, j);
	swap(x, y);
	std::cout << "i=" << i <<'\t'<< "j=" << j << std::endl;
	std::cout << "x=" << x << '\t' << "y=" << y << std::endl;
	system("pause");
	return 0;
}