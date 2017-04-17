#include"String.h"
#include<iostream>
using namespace std;
int main(){
	CString str = "abc",str2="-xyz";
	CString s1 = str2;
	s1 = "1234567";
	cout <<str<<"长度为："<< str.GetLength() << endl;
	cout <<s1<<"长度为：" << s1.GetLength() << endl;
	str += str2;
	cout << str << "长度为：" << str.GetLength() << endl;
	int i = 0;
	while (i < str.GetLength()){
		cout << str[i] << endl;
		++i;
	}
	str[1] = '*';//返回引用可以做左值
	 i = 0;
	while (i < str.GetLength()){
		cout << str[i] << endl;
		++i;
	}
	CString s2 = str + str2;
	cout << s2 << "长度为：" << s2.GetLength() << endl;
	CString s3 = "ABcdEFg";
	cout << s3.MakeLower() << endl;
	CString s4 = "ABcdEFg";
	cout << s4.MakeUpper() << endl;
	CString s5 = "ABcdEFg";
	cout << s5.MakeReverse() << endl;
	cout << s5.Mid(2, 7) << endl;
	cout << s5.Mid(2) << endl;
	cout << s5.Left(3) << endl;
	cout << s5.Right(4) << endl;
	int p = s5.Find('d', 3);
	cout << p << endl;
	 p = s5.Find("dcB");
	cout << p << endl;
	system("pause");
}