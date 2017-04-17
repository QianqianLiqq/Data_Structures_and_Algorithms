/*
二叉搜索树查找次数不超过树的深度
二叉搜索树按中序遍历，能得到从小到大的排序
*/
#include<iostream>
using namespace std;
typedef int DATA;
struct SNode{
	DATA data;
	SNode *pLeft, *pRight;
	SNode(DATA d) :data(d){
		pLeft = pRight = NULL;
	}
};
SNode *g_pRoot = NULL;
void SetAt(DATA data){
	SNode *pNew = new SNode(data);
	SNode *p = g_pRoot;
	if (!p){
		g_pRoot = pNew;
		return;
	}
	while (true){
		if (data == p->data)
			return;
		if (data < p->data){
			if (p->pLeft == NULL){
				p->pLeft = pNew;
				return;
			}
			else
				p = p->pLeft;
		}
		if (data > p->data){
			if (p->pRight == NULL){
				p->pRight = pNew;
				return;
			}
			else
				p = p->pRight;
		}
	}
}
SNode * getPointer(DATA data){
	SNode *p = g_pRoot;
	if (!p)
		return nullptr;
	while (p){
		if (data == p->data)
			return p;
		if (data < p->data)
			p = p->pLeft;
		if (data > p->data)
			p = p->pRight;
	}
	return nullptr;
}
SNode * getParent(DATA data){
	SNode *p = g_pRoot;
	if (!p || data == p->data)
		return nullptr;
	while (p){
		if (data == p->pLeft->data || data == p->pRight->data)
			return p;
		if (data < p->data)
			p = p->pLeft;
		if (data > p->data)
			p = p->pRight;
	}
	return nullptr;
}
void Delete(DATA data){
	SNode *p = g_pRoot;
	if (!p)
		return;
	SNode *pointer = getPointer(data);
	if (!pointer)
		return;
	SNode *parent = getParent(data);
	SNode *child = nullptr;
	SNode *temp = nullptr;
	if (pointer->pLeft){
		temp = child = pointer->pLeft;
		while (temp->pRight)		
			temp = temp->pRight;
		temp->pRight = pointer->pRight;
	}else
		child = pointer->pRight;
	if (!parent)
		g_pRoot = child;
	else if (data < parent->data)
		parent->pLeft = child;
	else
		parent->pRight = child;
}
void InnOrder(SNode* p){
	if (p->pLeft)
		InnOrder(p->pLeft);
	cout << p->data << " ";
	if (p->pRight)
		InnOrder(p->pRight);
}
bool Lookup(DATA data){
	SNode *p = g_pRoot;
	while (p){
		if (data == p->data)
			return true;
		if (data < p->data)
			p = p->pLeft;
		else
			p = p->pRight;
	}
	return false;
}
int main(){
	SetAt(80);
	SetAt(50);
	SetAt(60);
	SetAt(40);
	SetAt(45);
	SetAt(120);
	SetAt(100);
	SetAt(150);
	SetAt(140);
	SetAt(160);
	SetAt(115);
	Delete(50);
	InnOrder(g_pRoot);
	cout << endl;
	if (Lookup(45))
		cout << "找到了45" << endl;
	else
		cout << "找不到45" << endl;
	system("pause");
	return 0;
}