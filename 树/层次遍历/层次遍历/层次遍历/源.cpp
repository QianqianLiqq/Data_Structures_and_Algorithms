#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int data){
		val = data;
		left = right = nullptr;
	}
};

void LevelTraverseWithoutRecusion(BinaryTreeNode *root){
	if (root == nullptr)
		return;
	BinaryTreeNode* p = root;
	queue<BinaryTreeNode*> q;
	q.push(p);
	BinaryTreeNode* temp;
	while (!q.empty()){
		temp = q.front();
		q.pop();
		cout << temp->val << endl;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

int getTreeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	int leftDepth = getTreeDepth(pRoot->left) + 1;
	int rightDepth = getTreeDepth(pRoot->right) + 1;
	int ret = leftDepth >= rightDepth ? leftDepth : rightDepth;
	return ret;
}

void PrintNodeAtLevel(BinaryTreeNode* root, int level){
	 // 空树或层级不合理
	if (NULL == root || level < 1)
		return;
	if (1 == level){
		cout << root->val << endl;
		return;
	}

	// 左子树的 level - 1 级
	PrintNodeAtLevel(root->left, level - 1);
	// 右子树的 level - 1 级
	PrintNodeAtLevel(root->right, level - 1);
}

void LevelTraverse(BinaryTreeNode* root){
	if (NULL == root)
		return;
	int depth = getTreeDepth(root);
	for (int i = 1; i <= depth; i++)
		PrintNodeAtLevel(root, i);    
}

int main(){
	BinaryTreeNode *root = new BinaryTreeNode(1);
	root->left = new BinaryTreeNode(2);
	root->right = new BinaryTreeNode(3);
	root->left->left = new BinaryTreeNode(4);
	root->left->right = new BinaryTreeNode(10);
	root->right->left = new BinaryTreeNode(5);
	root->right->right = new BinaryTreeNode(6);
	root->left->left->right = new BinaryTreeNode(7);
	root->left->left->right->left = new BinaryTreeNode(8);
	root->left->left->right->right = new BinaryTreeNode(9);
	//LevelTraverseWithoutRecusion(root);
	LevelTraverse(root);
	system("pause");
	return 0;
}