#include<iostream>
#include<string>
using namespace std;

string findLongestPalindrome(string &s)
{
	const int length = s.size();
	int maxlength = 0;
	int start;

	for (int i = 0; i<length; i++)//长度为奇数  
	{
		int j = i - 1, k = i + 1;
		while (j >= 0 && k<length&&s.at(j) == s.at(k))
		{
			if (k - j + 1>maxlength)
			{
				maxlength = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}

	for (int i = 0; i<length; i++)//长度为偶数  
	{
		int j = i, k = i + 1;
		while (j >= 0 && k<length&&s.at(j) == s.at(k))
		{
			if (k - j + 1>maxlength)
			{
				maxlength = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}
	if (maxlength>0)
		return s.substr(start, maxlength);
	return NULL;
}

int main(){
	string str = "abcba";
	string result = findLongestPalindrome(str);
	cout << result << endl;
	system("pause");
	return 0;
}