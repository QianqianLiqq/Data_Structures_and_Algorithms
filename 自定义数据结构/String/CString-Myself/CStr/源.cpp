#include<iostream>
#include"String.h"
using namespace std;

int main(){
	CString s1 = "abc", s2 = "-xyz";
	cout << s1.GetLenth() << endl;
	CString s = s1;//��Ҫһ���������캯��,��û�ж��忽�����캯������s��s1ָ��ͬһ����ַ��
	               //������ʱ������s���������s1ʱ�����delete�յ�ַ����������
    s = s1 + s2;
	cout << s.GetLenth() << endl;
	s1 = s2;//����֮�丳ֵҲ���������ǳ����
	cout << s1 << endl;
	const char * p = s1;//c�����ַ�����c++�ַ�����ת��
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