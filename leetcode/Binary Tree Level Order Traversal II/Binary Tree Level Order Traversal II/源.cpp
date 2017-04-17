#include<iostream>
#include<vector>
#include<map>
#include<stack>
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
	 vector<vector<int>> levelOrderBottom(TreeNode* root){
		 if (!root)
			 return{};
		 vector<vector<int>> v;
		 vector<int> v2;
		 queue<TreeNode*> q;
		 TreeNode* p = root;
		 TreeNode* current = root;
		 vector<int> vec;
		 q.push(p);
		 int height = -1;
		 int oldHeight = -1;
		 while (!q.empty()){
			 current = q.front();
			 height = getLevel(root,current);
			 if (height > oldHeight){
				 if (!vec.empty())
				    v.push_back(vec);
				 vec.clear();
				 oldHeight = height;
			 }
			 vec.push_back(current->val);
			 q.pop();
			 if (current->left)
				 q.push(current->left);
			 if (current->right)
				 q.push(current->right);
		 }
		 v.push_back(vec);
		 reverse(v.begin(), v.end());
		 return v;
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
 };


int main(){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(17);
	Solution s;
	vector<vector<int>> A=s.levelOrderBottom(root);
	for (int i = 0; i < A.size(); ++i){
		for (int j = 0; j < A[i].size(); ++j)
			cout << A[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}