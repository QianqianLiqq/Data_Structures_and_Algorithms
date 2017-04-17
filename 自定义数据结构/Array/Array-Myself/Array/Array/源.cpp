#include<iostream>
#include"Array.h"
using namespace std;
int main(){
	CArray arr;
	//arr.SetSize(50);
	int i = 0;
	while (i < 10)
		arr.Add(++i);
	i = 0;
	while (i <arr.GetSize()){
		cout << arr[i] << endl;
		++i;
	}
	arr.RemoveAt(2, 3);
	i = 0;
	cout << "É¾³ýºó£º" << endl;
	while (i <arr.GetSize()){
		cout << arr[i] << endl;
		++i;
	}
	arr.InsertAt(7, 0,3);
	i = 0;
	cout << "²åÈëºó£º" << endl;
	while (i <arr.GetSize()){
		cout << arr[i] << endl;
		++i;
	}
	system("pause");
		
}