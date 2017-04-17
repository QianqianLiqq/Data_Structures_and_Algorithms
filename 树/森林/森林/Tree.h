#pragma once
#include"TreeNode.h"
template<class T>
class Tree
{
public:
	Tree();
	~Tree();
	//返回树中的根节点
	TreeNode<T>* getRoot();
	//创建树中的根节点，使根节点元素的值为rootValue
	void creatRoot(const T& rootValue);
	//判断是否为空树，如果是则返回true
	bool isEmpty();
	//返回current节点的父节点
	TreeNode<T>* Parent(TreeNode<T>* current);
	//返回current节点的前一个邻居节点
	TreeNode<T>* PrevSibling(TreeNode<T>* current);
	//删除以subroot为根的子树的所有节点
	void deleteSubTree(TreeNode<T>* subroot);
	//先根深度优先周游树（等价于二叉树中的后序）
	void rootFirstTraverse(TreeNode<T>* root);
	//后根深度优先周游树（等价于二叉树中的中序）
	void rootLastTraverse(TreeNode<T>* root);
	//广度优先周游树
	void widthTraverse(TreeNode<T>* root);
};

template<class T>
void Tree<T>::rootFirstTraverse(TreeNode<T>* root){
	while (root != nullptr){
		Visit(root->Value());
		//周游头一棵树树根的子树
		rootFirstTraverse(root->LeftMostChild());
		root = root->RightSibling();//周游其他的树
	}
}

template<class T>
void Tree<T>::rootLastTraverse(TreeNode<T>* root){
	while (root != nullptr){
		//周游头一棵树树根的子树
		rootLastTraverse(root->LeftMostChild());
		Visit(root->Value());
		root = root->RightSibling();//周游其他的树
	}
}

