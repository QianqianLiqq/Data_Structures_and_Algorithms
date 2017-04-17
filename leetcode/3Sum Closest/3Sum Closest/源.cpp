#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> res;
		for (int i = 0; i < n - 2; ++i){
			if (i > 0 && nums[i] == nums[i - 1])continue;
			int target2 = target - nums[i];
			twoSumClosest(nums, i + 1, target2, res);
		}
		int min = abs(res[0] - target) + 1;
		int value = 0;
		int result = 0;
		for (int i = 0; i < res.size(); ++i){
			value = abs(res[i] - target);
			if (value < min){
				min = value;
				result = res[i];
			}
		}
		return result;
	}
	void twoSumClosest(vector<int>& sortedNums, int start, int target, vector<int>&res){//res要被修改，必须用引用类型
		int head = start;
		int tail = sortedNums.size() - 1;
		while (head < tail){
			int tmp = sortedNums[head] + sortedNums[tail];
			if (tmp < target){
				while (sortedNums[head] + sortedNums[tail] < target && head<tail-1)
					++head;
				if (head == start)
					res.push_back(sortedNums[start - 1] + sortedNums[head] + sortedNums[tail]);
				else{
					int value = abs(sortedNums[head] + sortedNums[tail] - target)>
						abs(sortedNums[head - 1] + sortedNums[tail] - target) ?
						(sortedNums[head - 1] + sortedNums[tail]) : (sortedNums[head] + sortedNums[tail]);
					res.push_back(sortedNums[start - 1] + value);
				}
				--tail;
			}
			else if (tmp>target){
				while (sortedNums[head] + sortedNums[tail] > target && head<tail-1)
					--tail;
				if (tail == sortedNums.size() - 1)
					res.push_back(sortedNums[start - 1] + sortedNums[head] + sortedNums[tail]);
				else{
					int value = abs(sortedNums[head] + sortedNums[tail] - target)>
						abs(sortedNums[head] + sortedNums[tail + 1] - target) ?
						(sortedNums[head] + sortedNums[tail + 1]) : (sortedNums[head] + sortedNums[tail]);
					res.push_back(sortedNums[start - 1] + value);
				}
				++head;
			}
			else{
				res.push_back(sortedNums[start - 1] + tmp);
				break;
			}
		}
	}
};
int main(){
	Solution s;
	vector<int> vec = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int target = 82;
	int value = s.threeSumClosest(vec, target);
	cout << value << endl;
	system("pause");
	return 0;
}