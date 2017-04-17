#include<iostream>
#include<string>
using namespace std;

int max(int &x, int &y){
	return (x >= y) ? x : y;
}

string lcs(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int end = 0;
	int maxlength = 0;     //记录最长公共子串长度
	int **c = new int*[len1 + 1];
	for (int i = 0; i <= len1; ++i)
		c[i] = new int[len2 + 1];
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				if (c[i][j] > maxlength){
					maxlength = max(c[i][j], maxlength);
					end = i - 1;
				}
			}
			else {
				c[i][j] = 0;
			}
		}
	}
	for (int i = 0; i <= len1; ++i){
		for (int j = 0; j <= len2; ++j)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return str1.substr(end - maxlength + 1, maxlength);
}

int main(){
	string str1 = "abcdefghixyzj";
	string str2 = "hxzj";
	string maxlength = lcs(str1, str2);
	cout << maxlength << endl;
	system("pause");

}