#include<iostream>
#include<vector>
#include<stack>
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

//void PostOrderWithoutRecusion(BinaryTreeNode *root){
//	StackElement element;
//	stack<StackElement> stack;
//	if (root == nullptr)
//		return;
//	BinaryTreeNode *p = root;
//	while (true){
//		while (p){
//			element.pointer = p;
//			element.tag = Left;
//			stack.push(element);
//			p = p->left;
//		}
//		element = stack.top();
//		stack.pop();
//		p = element.pointer;
//		while (element.tag == Right){
//			cout << p->val << endl;
//			if (stack.empty())
//				return;
//			else{
//				element = stack.top();
//				stack.pop();
//				p = element.pointer;
//			}
//		}
//		element.tag = Right;
//		stack.push(element);
//		p = p->right;
//	}
//}

vector<int> postorderTraversal(BinaryTreeNode *root) {
	vector<int> vec;
	stack<BinaryTreeNode *> st;
	BinaryTreeNode *temp = NULL, *current = root;
	if (root == NULL)
		return vec;
	while (!st.empty() || current)
	{
		while (current)
		{
			st.push(current);
			current = current->left;
		}
		current = st.top();
		if (current->left == temp&&current->right)
		{
			current = current->right;
			temp = NULL;
		}
		else
		{
			vec.push_back(current->val);
			st.pop();
			temp = current;
			current = NULL;
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
	vector<int> postorder = postorderTraversal(root);
	for (int i = 0; i < postorder.size(); ++i)
		cout << postorder[i] << endl;
	system("pause");
	return 0;
}