#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string result, str;
		int int_a, int_b;
		int temp;
		bool flag = false;
		int i = a.size() - 1, j = b.size() - 1;
		while(i>=0 && j>=0){
			int_a = (int)(a[i] - '0');
			int_b = (int)(b[j] - '0');
			if (flag)
				temp = int_a + int_b + 1;
			else
				temp = int_a + int_b;
			if (temp >= 2){
				flag = true;
				temp = temp - 2;
			}
			else
				flag = false;
			stringstream stream;
			stream << temp;
			stream >> str;
			result += str;
			--i; 
			--j;
		}
		while (i>=0){
			if (flag)
				temp = int(a[i] - '0') + 1;
			else
				temp = int(a[i] - '0');
			if (temp >= 2){
				flag = true;
				temp = temp - 2;
			}
			else
				flag = false;
			stringstream stream;
			stream << temp;
			stream >> str;
			result += str;
			--i;
		}
		while (j>=0){
			if (flag)
				temp = int(b[j]-'0') + 1;
			else
				temp = int(b[j] - '0');
			if (temp >= 2){
				flag = true;
				temp = temp - 2;
			}
			else
				flag = false;
			stringstream stream;
			stream << temp;
			stream >> str;
			result += str;
			--j;
		}
		if (flag){
			temp = 1;
			stringstream stream;
			stream << temp;
			stream >> str;
			result += str;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main(){
	Solution s;
	string a("100");
	string b("110010");
	string str = s.addBinary(a,b);
	cout << str << endl;
	system("pause");
}