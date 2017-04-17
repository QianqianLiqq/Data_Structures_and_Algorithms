#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		string result, res;
		vector<char> temp;
		vector<char> vec;
		int A = 0, B = 0;
		for (int i = 0; i < secret.size(); ++i){
			if (secret[i] == guess[i])
				++A;
			else{
				vec.push_back(secret[i]);
				temp.push_back(guess[i]);
			}
		}
		vector<char>::iterator it, ite;
		for (int j = 0; j < temp.size(); ++j){
			it = vec.begin();
			ite = vec.end();
			while (it != ite){
				if (temp[j] == *it){
					++B;
					vec.erase(it);
					break;
				}
				++it;
			}
		}
		return std::to_string(A) + "A" + std::to_string(B) + "B";
	}
};

int main(){
	Solution s;
	string res = s.getHint("1122", "2211");
	cout << res << endl;
	system("pause");
	return 0;
}