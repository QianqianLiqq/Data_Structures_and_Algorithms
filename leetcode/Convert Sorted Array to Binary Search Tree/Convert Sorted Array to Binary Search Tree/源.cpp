#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
		return convert2BST(nums, 0, n - 1);
	}
	TreeNode* convert2BST(vector<int>& nums, int left, int right){
		if (left > right)
			return nullptr;
		int mid = (left + right) / 2;
		TreeNode* pNode = new TreeNode(nums[mid]);
		pNode->left = convert2BST(nums, left, mid - 1);
		pNode->right = convert2BST(nums, mid + 1, right);
		return pNode;
	}
};

int main(){

	return 0;
}