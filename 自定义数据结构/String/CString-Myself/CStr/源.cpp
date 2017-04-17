#include<iostream>
#include"String.h"
using namespace std;

int main(){
	CString s1 = "abc", s2 = "-xyz";
	cout << s1.GetLenth() << endl;
	CString s = s1;//需要一个拷贝构造函数,若没有定义拷贝构造函数，则s和s1指向同一个地址，
	               //则析构时先析构s，最后析构s1时会出现delete空地址，程序会崩溃
    s = s1 + s2;
	cout << s.GetLenth() << endl;
	s1 = s2;//对象之间赋值也存在深拷贝和浅拷贝
	cout << s1 << endl;
	const char * p = s1;//c语言字符串与c++字符串的转换
	cout << p << endl;
	CString s3('*', 8);
	cout << s3 << endl;
	CString s4("nd hrifngha", 5);
	cout << s4 << endl;
	s = "1234567";
	cout << s << endl;
	if (s1 == s2)
		cout << "s1==s2" << endl;
	else
	    cout << "s1!=s2" << endl;
	if ("1234" != s)
		cout << "1234!=s" << endl;
	else
		cout << "1234==s" << endl;
	int i = 0;
	while (i < s.GetLenth()){
		cout << s[i] << endl;
		++i;
	}
	s += s1;
	cout << s << endl;
	system("pause");
	return 0;
}