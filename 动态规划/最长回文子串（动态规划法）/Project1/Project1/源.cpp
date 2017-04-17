#include<iostream>
#include<string>
using namespace std;

string findLongestPalindrome(string &s)
{
	int length = s.size();
	int maxlength = 0;
	int start;
	int **P = new int*[length];
	for (int i = 0; i < length; ++i){
		P[i] = new int[length];
		memset(P[i], 0, length*sizeof(int));
	}
	
	for (int i = 0; i<length; i++)//��ʼ��׼��  
	{
		P[i][i] = 1;
		if (i<length - 1 && s[i] == s[i + 1])
		{
			P[i][i + 1] = 1;
			start = i;
			maxlength = 2;
		}
	}
	
	for (int len = 3; len <= length; len++){//�Ӵ�����  
		for (int i = 0; i <= length - len; i++)//�Ӵ���ʼ��ַ  
		{
			int j = i + len - 1;//�Ӵ�������ַ  
			if (P[i + 1][j - 1] && s[i] == s[j])
			{
				P[i][j] = 1;
				maxlength = len;
				start = i;
			}
		}
	}

	for (int i = 0; i < length; ++i)
		delete[] P[i];
	delete[] P;

	if (maxlength >= 2)
		return s.substr(start, maxlength);
	return NULL;
}

int main(){
	string str = "abcba";
	string s = findLongestPalindrome(str);
	cout << s << endl;
	system("pause");
	return 0;
}