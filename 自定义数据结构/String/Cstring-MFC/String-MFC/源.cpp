#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <afxtempl.h>
using namespace std;

int main(){
	char s[20] = "abc";//c�����ַ���
	strcat(s, "-xyz");
	CString  s1= "abc",s2=s1;//c++�ַ���
	s2 = "-xyz";
	CString  s3 = s1 + s2;
	s1 = s3.Left(5);//ȡs3���5���ַ�
	s2 = s3.Right(3);
	s1 = s3.Mid(2, 3);//��s3�ĵ�2���ַ���ʼȡ3��
	int i = 0;
	while (i < s3.GetLength()){
		cout << (char)s3[i] << endl;
		++i;
	}
	system("pause");
	return 0;
}