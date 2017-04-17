#include<iostream>
#include <vector>
#include<map>
using namespace std;
int rob(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;		
	vector<int> temp(nums);
	temp[0] = nums[0];
	temp[1] = (nums[0] >= nums[1] ? nums[0] : nums[1]);
	for (int i = 2; i<nums.size(); ++i){
		if (temp[i - 1] < temp[i - 2] + nums[i])
			temp[i] = temp[i - 2] + nums[i];
		else
			temp[i] = temp[i - 1];
	}
	return temp[nums.size() - 1];	
}
int main(){
	vector<int> nums = { 1,2,3 };
	int sum = rob(nums);
	cout << sum << endl;
	system("pause");
}