#pragma once
template<class T>
class TreeNode
{
public:
	TreeNode();
	~TreeNode();
	TreeNode(const T&);//拷贝构造函数
	bool isLeaf();
	T Value();//返回结点的值
	TreeNode* LeftMostChild();//返回第一个左孩子
	TreeNode* RightSibling();//返回右兄弟
	void setValue(const T&);
	//设置左子节点
	void setChild(TreeNode<T>* pointer);
	//设置右兄弟
	void setSibling(TreeNode<T>* pointer);
	//以第一个左子节点的身份插入新节点
	void InsertFirst(TreeNode<T>* node);
	//以右兄弟的身份插入新节点
	void InsertNext(TreeNode<T>* node);
};

