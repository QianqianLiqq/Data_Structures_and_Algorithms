#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<vector<int>> v;
		vector<int> vec;
		vector<int> res;
		if (!root)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* current = root;
		int height = -1;
		int oldHeight = -1;
		while (!q.empty()){
			current = q.front();
			q.pop();
			height = getLevel(root, current);
			if (height>oldHeight){
				if (!vec.empty())
					v.push_back(vec);
				vec.clear();
				oldHeight = height;
			}
			vec.push_back(current->val);
			if (current->left)
				q.push(current->left);
			if (current->right)
				q.push(current->right);
		}
		v.push_back(vec);
		for (int i = 0; i < v.size(); ++i){
			int n = v[i].size();
			int value = v[i][n - 1];
			res.push_back(value);
		}
		return res;
	}
	int getLevel(TreeNode* root, TreeNode* p){
		if (!root)
			return 0;
		if (root == p)
			return 1;
		int d;
		d = getLevel(root->left, p);
		if (d>0)
			return d + 1;
		d = getLevel(root->right, p);
		if (d>0)
			return d + 1;
		return 0;
	}
};

int main(){
	Solution s;
	TreeNode * p = new TreeNode(6);
	p->left = new TreeNode(1);
	p->left->right = new TreeNode(3);
	p->left->right->left = new TreeNode(2);
	p->left->right->right = new TreeNode(5);
	p->left->right->right->left = new TreeNode(4);
	//s.rightSideView(p);
	cout << (2 << 3) << endl;
	system("pause");
	return 0;
}