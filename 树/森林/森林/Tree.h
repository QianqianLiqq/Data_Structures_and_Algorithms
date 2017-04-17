#pragma once
#include"TreeNode.h"
template<class T>
class Tree
{
public:
	Tree();
	~Tree();
	//�������еĸ��ڵ�
	TreeNode<T>* getRoot();
	//�������еĸ��ڵ㣬ʹ���ڵ�Ԫ�ص�ֵΪrootValue
	void creatRoot(const T& rootValue);
	//�ж��Ƿ�Ϊ������������򷵻�true
	bool isEmpty();
	//����current�ڵ�ĸ��ڵ�
	TreeNode<T>* Parent(TreeNode<T>* current);
	//����current�ڵ��ǰһ���ھӽڵ�
	TreeNode<T>* PrevSibling(TreeNode<T>* current);
	//ɾ����subrootΪ�������������нڵ�
	void deleteSubTree(TreeNode<T>* subroot);
	//�ȸ�����������������ȼ��ڶ������еĺ���
	void rootFirstTraverse(TreeNode<T>* root);
	//�������������������ȼ��ڶ������е�����
	void rootLastTraverse(TreeNode<T>* root);
	//�������������
	void widthTraverse(TreeNode<T>* root);
};

template<class T>
void Tree<T>::rootFirstTraverse(TreeNode<T>* root){
	while (root != nullptr){
		Visit(root->Value());
		//����ͷһ��������������
		rootFirstTraverse(root->LeftMostChild());
		root = root->RightSibling();//������������
	}
}

template<class T>
void Tree<T>::rootLastTraverse(TreeNode<T>* root){
	while (root != nullptr){
		//����ͷһ��������������
		rootLastTraverse(root->LeftMostChild());
		Visit(root->Value());
		root = root->RightSibling();//������������
	}
}

