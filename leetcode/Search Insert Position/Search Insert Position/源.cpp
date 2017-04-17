#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return 0;
	if (target<nums[0])
		return 0;
	int i = 0;
	for (i = 0; i<nums.size() - 1; ++i){
		if (target == nums[i])
			return i;
		if (target>nums[i] && target<nums[i + 1])
			return i + 1;
	}
	if (target == nums[i])
		return i;
	if (target>nums[i])
		return i + 1;
}
int main(){
	vector<int> nums = { 1,3,5,6 };
	int target = 0;
	cout << searchInsert(nums, 0) << endl;
	system("pause");
	return 0;
}