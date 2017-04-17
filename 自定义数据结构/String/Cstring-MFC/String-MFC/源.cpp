#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <afxtempl.h>
using namespace std;

int main(){
	char s[20] = "abc";//c语言字符串
	strcat(s, "-xyz");
	CString  s1= "abc",s2=s1;//c++字符串
	s2 = "-xyz";
	CString  s3 = s1 + s2;
	s1 = s3.Left(5);//取s3左边5个字符
	s2 = s3.Right(3);
	s1 = s3.Mid(2, 3);//从s3的第2个字符开始取3个
	int i = 0;
	while (i < s3.GetLength()){
		cout << (char)s3[i] << endl;
		++i;
	}
	system("pause");
	return 0;
}