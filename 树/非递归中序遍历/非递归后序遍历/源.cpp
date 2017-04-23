#include<iostream>
#include<stack>
#include<vector>
using namespace std;

enum Tags{Left,Right};

struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int data){
		val = data;
		left = right = nullptr;
	}
};

struct StackElement{
	BinaryTreeNode* pointer;
	Tags tag;
};

void InOrderWithoutRecusion(BinaryTreeNode *root){
	StackElement element;
	stack<StackElement> stack;
	if (root == nullptr)
		return;
	BinaryTreeNode *p = root;
	while (true){
		while (p){
			//cout << p->val << endl;
			element.pointer = p;
			element.tag = Left;
			stack.push(element);
			p = p->left;
		}
		element = stack.top();
		stack.pop();
		p = element.pointer;
		while (element.tag == Right){
			//cout << p->val << endl;
			if (stack.empty())
				return;
			else{
				element = stack.top();
				stack.pop();
				p = element.pointer;
			}
		}
		element.tag = Right;
		stack.push(element);
		cout << p->val << endl;
		p = p->right;
	}
}

vector<int> inorderTraversal(BinaryTreeNode *root) {
	vector<int> vec;
	stack<BinaryTreeNode*> s;
	BinaryTreeNode *p = root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			vec.push_back(p->val);
			s.pop();
			p = p->right;
		}
	}
	return vec;
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
	//InOrderWithoutRecusion(root);
	vector<int> inorder = inorderTraversal(root);
	for (int i = 0; i < inorder.size(); ++i)
		cout << inorder[i] << endl;
	system("pause");
	return 0;
}