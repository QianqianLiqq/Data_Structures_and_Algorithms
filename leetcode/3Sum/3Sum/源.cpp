#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
		int n = num.size();
		sort(num.begin(), num.end());
		vector<vector<int>> res;
		for (int i = 0; i < n - 2; i++)
		{
			if (i > 0 && num[i] == num[i - 1])continue;//�ظ���Ԫ�ز��ü���
			int target2 = 0 - num[i];
			twoSum(num, i + 1, target2, res);
		}
		return res;			
	}
	void twoSum(vector<int> &sortedNum, int start, int target, vector<vector<int>>&res)
    {
		int head = start, tail = sortedNum.size() - 1;
		while (head < tail)
	    {
			int tmp = sortedNum[head] + sortedNum[tail];
			if (tmp < target)
				head++;
			else if (tmp > target)
				tail--;
			else
			{
			    res.push_back(vector<int>{sortedNum[start - 1], sortedNum[head], sortedNum[tail]});
				
			    //Ϊ�˷�ֹ�����ظ��Ķ�Ԫ�飬ʹ�������target
			    int k = head + 1;
				while (k < tail && sortedNum[k] == sortedNum[head])
					k++;
				head = k;
				
				k = tail - 1;
				while (k > head && sortedNum[k] == sortedNum[tail])
					k--;
				tail = k;
		    }
		}
    }
		
};
int main(){
	Solution s;
	vector<int> vec = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>>res = s.threeSum(vec);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
