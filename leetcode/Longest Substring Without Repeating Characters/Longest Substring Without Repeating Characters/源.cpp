#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		if (n == 0 || n == 1)
			return n;
		vector<int> vec;
		vector<char> vecstr;
		vector<char>::iterator it;
		vector<char> temp;
		int i = 0;
		while (i != s.size()){
			it = vecstr.begin();
			while (it != vecstr.end()&&(*it) != s[i])
				++it;
			if (it != vecstr.end()){//ур╣╫ак
				vec.push_back(vecstr.size());
				++it;
				while (it != vecstr.end()){
					temp.push_back(*it);
					++it;
				}
				vecstr.clear();
				for (int k = 0; k < temp.size(); ++k)
					vecstr.push_back(temp[k]);
				temp.clear();
				vecstr.push_back(s[i]);
			}
			else
				vecstr.push_back(s[i]);
			++i;
		}
		vec.push_back(vecstr.size());
		int max = 0;
		for (int j = 0; j < vec.size(); ++j){
			if (vec[j] > max)
				max = vec[j];
		}
		return max;
	}
};
int main(){
	Solution s;
	string str("ynyo");
	int l = s.lengthOfLongestSubstring(str);
	cout << l << endl;
	system("pause");
	return 0;
}