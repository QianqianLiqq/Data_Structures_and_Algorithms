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

void PreOrderWithoutRecusion(BinaryTreeNode *root){
	StackElement element;
	stack<StackElement> stack;
	if (root == nullptr)
		return;
	BinaryTreeNode *p = root;
	while (true){
		while (p){
			cout << p->val << endl;
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
		p = p->right;
	}
}

vector<int> preorderTraversal(BinaryTreeNode *root) {
	vector<int> vec;
	stack<BinaryTreeNode *> st;
	BinaryTreeNode  *current = root;
	if (root == NULL)
		return vec;
	while (!st.empty() || current)
	{
		while (current)
		{
			vec.push_back(current->val);
			st.push(current);
			current = current->left;
		}
		if (!st.empty()){
			current = st.top();
			st.pop();
			current = current->right;
		}
	}
	return vec;
}


int main(){
	BinaryTreeNode *root = new BinaryTreeNode(1);
	root->left = new BinaryTreeNode(2);
	root->right = new BinaryTreeNode(3);
	root->left->left = new BinaryTreeNode(4);
	root->right->left = new BinaryTreeNode(5);
	root->right->right = new BinaryTreeNode(6);
	root->left->left->right = new BinaryTreeNode(7);
	root->left->left->right ->left= new BinaryTreeNode(8);
	//PreOrderWithoutRecusion(root);
	vector<int> preorder = preorderTraversal(root);
	for (int i = 0; i < preorder.size(); ++i)
		cout << preorder[i] << endl;
	system("pause");
	return 0;
}