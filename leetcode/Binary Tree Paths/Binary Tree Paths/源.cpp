#include<iostream>
#include<vector>
#include<string>
#include <sstream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

class Solution {
	enum Tags{ left, right };
	struct Element{
		TreeNode* pointer;
		Tags tag;
	};
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string strtemp;
		TreeNode* p = root;
		stack<Element> Stack;
		Element element;
		if (!p)
			return res;
		while (true){
			while (p){
				element.pointer = p;
				element.tag = left;
				Stack.push(element);
				p = p->left;
			}
			element = Stack.top();
			Stack.pop();
			element.tag = right;
			Stack.push(element);
			p = element.pointer;
			p = p->right;
			if (!p){
				strtemp = getElement(Stack);
				res.push_back(strtemp);				
				element = Stack.top();
				while (element.tag == right){
					Stack.pop();
					if (Stack.empty())				
						return res;					
					element = Stack.top();
				}    
				Stack.pop();
				element.tag = right;
				Stack.push(element);
				p = element.pointer;
				while (!p->right){
					while (element.tag == right){
						Stack.pop();
						if (Stack.empty())
							return res;
						element = Stack.top();
					}										
					element = Stack.top();
					Stack.pop();
					element.tag = right;
					Stack.push(element);
					p = element.pointer;										
				}
				p = p->right;
			}
		}
	}
	string getElement(stack<Element> Stack){
		string str;
		string strtemp;
		//stringstream ss;
		int value;
		stack<TreeNode*> temp;
		while (!Stack.empty()){
			Element element = Stack.top();
			temp.push(element.pointer);
			Stack.pop();
		}
		if (!temp.empty()){
			stringstream ss;
			value = temp.top()->val;
			ss << value;
			ss >> str;
			temp.pop();
		}
		while (!temp.empty()){
			stringstream ss;
			value = temp.top()->val;
			ss << value;
			ss >> strtemp;
			str = str + "->" + strtemp;
			temp.pop();
		}
		return str;
	}
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	//root->left->left = new TreeNode(3);
	root->right->left = new TreeNode(4);
	Solution s;
	vector<string> result = s.binaryTreePaths(root);
	for (int i = 0; i < result.size(); ++i){
		//for (int j = 0; j < result[i].size(); ++j)
			cout << result[i] << endl;
	}
	system("pause");
}