#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4)
			return res;
		sort(nums.begin(), nums.end());
		int target2;
		for (int i = 0; i < nums.size() - 3; ++i){
			if (i>0&&nums[i] == nums[i - 1])
				continue;
			target2 = target - nums[i];
			threeSum(nums, i, i + 1, target2, res);
		}
		return res;
	}
	void threeSum(vector<int>&sortedNums, int first, int start, int target, vector<vector<int>>&res){
		int target3;
		for (int i = start; i < sortedNums.size() - 2; ++i){
			if (i>start&&sortedNums[i] == sortedNums[i - 1])
				continue;
			target3 = target - sortedNums[i];
			twoSum(sortedNums, first, i + 1, target3, res);
		}
	}
	void twoSum(vector<int>&sortedNums, int first, int start, int target, vector<vector<int>>&res){
		int head = start, tail = sortedNums.size() - 1;
		while (head < tail)
		{
			int tmp = sortedNums[head] + sortedNums[tail];
			if (tmp < target)
				head++;
			else if (tmp > target)
				tail--;
			else
			{
				res.push_back(vector<int>{sortedNums[first],sortedNums[start - 1], sortedNums[head], sortedNums[tail]});

				//为了防止出现重复的二元组，使结果等于target
				int k = head + 1;
				while (k < tail && sortedNums[k] == sortedNums[head])
					k++;
				head = k;

				k = tail - 1;
				while (k > head && sortedNums[k] == sortedNums[tail])
					k--;
				tail = k;
			}
		}
	}
};

int main(){
	Solution s;
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> res = s.fourSum(nums, 0);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}