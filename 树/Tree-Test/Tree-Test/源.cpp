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

void PreOrder(SNode* p){
	if (p == NULL)
		return;
	cout << p->data << " ";
	if (p->pLeft)
		PreOrder(p->pLeft);
	if (p->pRight)
		PreOrder(p->pRight);
}

void InnOrder(SNode* p){
	if (p == NULL)
		return;
	if (p->pLeft)
		InnOrder(p->pLeft);
	cout << p->data << " ";
	if (p->pRight)
		InnOrder(p->pRight);
}

void PostOrder(SNode* p){
	if (p == NULL)
		return;
	if (p->pLeft)
		PostOrder(p->pLeft);
	if (p->pRight)
		PostOrder(p->pRight);
	cout << p->data << " ";
}

SNode *g_pRoot ;
int main(){
	g_pRoot = NULL;
	/*g_pRoot = new SNode(30);
	g_pRoot->pLeft = new SNode(40);
	g_pRoot->pRight = new SNode(50);
	SNode *p1 = g_pRoot->pLeft;
	p1->pLeft = new SNode(70);
	p1->pRight = new SNode(90);
	SNode *p2 = p1->pLeft;
	p2->pLeft = new SNode(55);
	SNode *p3 = p1->pRight;
	p3->pLeft = new SNode(25);
	SNode *p4 = g_pRoot->pRight;
	p4->pLeft = new SNode(60);
	p4->pRight = new SNode(80);*/
	cout << "先序遍历：" << endl;
	PreOrder(g_pRoot);
	cout << endl;
	cout << "中序遍历：" << endl;
	InnOrder(g_pRoot);
	cout << endl;
	cout << "后序遍历：" << endl;
	PostOrder(g_pRoot);
	cout << endl;
	system("pause");
	return 0;
}