#include<iostream>
using namespace std;

struct SNode{
	int data;
	SNode* next;
	SNode(int value){
		data = value;
		next = NULL;
	}
};

SNode* reverseList(SNode* m_pHead){
	if (!m_pHead || !m_pHead->next)
		return m_pHead;
	SNode* pNode = m_pHead;
	SNode* pPrev = NULL;
	while (pNode!=NULL){
		SNode* pNext = pNode->next;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pPrev;
}

int main(){
	SNode* root = new SNode(1);
	root->next = new SNode(2);
	root->next->next = new SNode(3);
	root->next->next ->next= new SNode(4);
	SNode* p = root;
	while (p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	SNode* node = reverseList(root);
	while (node){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
	system("pause");
	return 0;
}

