#include<iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode* p){
	//getTreeDepth()Ò»Ñù
}

int getTreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	int leftDepth = getTreeDepth(pRoot->left) + 1;
	int rightDepth = getTreeDepth(pRoot->right) + 1;
	int ret = leftDepth >= rightDepth ? leftDepth : rightDepth ;
	return ret;
}

int getLevel(TreeNode* root, TreeNode* p){
	int d;
	if (!root)
		return 0;
	if (root == p)
		return 1;
	d = getLevel(root->left, p);
	if (d > 0)
		return d + 1;
	d = getLevel(root->right, p);
	if (d > 0)
		return d + 1;
	return 0;
}