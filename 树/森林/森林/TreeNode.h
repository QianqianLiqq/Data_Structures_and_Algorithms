#pragma once
template<class T>
class TreeNode
{
public:
	TreeNode();
	~TreeNode();
	TreeNode(const T&);//�������캯��
	bool isLeaf();
	T Value();//���ؽ���ֵ
	TreeNode* LeftMostChild();//���ص�һ������
	TreeNode* RightSibling();//�������ֵ�
	void setValue(const T&);
	//�������ӽڵ�
	void setChild(TreeNode<T>* pointer);
	//�������ֵ�
	void setSibling(TreeNode<T>* pointer);
	//�Ե�һ�����ӽڵ����ݲ����½ڵ�
	void InsertFirst(TreeNode<T>* node);
	//�����ֵܵ���ݲ����½ڵ�
	void InsertNext(TreeNode<T>* node);
};

