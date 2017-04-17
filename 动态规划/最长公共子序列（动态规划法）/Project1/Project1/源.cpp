#include<iostream>
using namespace std;
#include<string>

int max(int &x, int &y){
	return (x >= y) ? x : y;
}

int lcs(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int **c = new int*[len1 + 1];
	for (int i = 0; i < len1 + 1; ++i)
		c[i] = new int[len2 + 1];
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	for (int i = 0; i <= len1; ++i){
		for (int j = 0; j <= len2; ++j){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return c[len1][len2];
}

int main(){
	string str1 = "cnblogs";
	string str2 = "belongs";
	int result = lcs(str1, str2);
	cout << result << endl;
	system("pause");
	return 0;
}