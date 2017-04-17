#include<iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* list1 = l1;
	ListNode* list2 = l2;
	int n1 = 1, n2 = 1;
	while (list1->next != NULL){
		++n1;
		list1 = list1->next;
	}
	while (list2->next != NULL){
		++n2;
		list2 = list2->next;
	}
	long int k = 1;
	long int num1 = 0, num2 = 0;
	while (n1>0){
		num1 += (l1->val)*k;
		l1 = l1->next;
		k = k * 10;
		n1--;
	}
	k = 1;
	while (n2>0){
		num2 += (l2->val)*k;
		l2 = l2->next;
		k = k * 10;
		n2--;
	}
	int num = num1 + num2;
	while (num == 0)
		return new ListNode(0);
	int i = 1, j = 0;
	while (num / i>0){
		i = i * 10;
		++j;
	}
	i = i / 10;
	stack<int> s;
	while (j>0){
		s.push(num / i);
		num = num%i;
		i = i / 10;
		--j;
	}
	ListNode *list, *list3;
	list = list3 = new ListNode(s.top());
	s.pop();
	while (!s.empty()){
		list3->next = new ListNode(s.top());
		s.pop();
		list3 = list3->next;
	}
	return list;
}*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *list, *list1;
	int sum = 0, flag = 0;
	sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
	if (sum<10){
		flag = 0;
	}
	else{
		flag = 1;
		sum = sum % 10;
	}
	list = new ListNode(sum);
	list1 = list;
	//list1 = list1->next;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 != NULL&&l2 != NULL){
		if (flag == 0)
			sum = l1->val + l2->val;
		else if (flag == 1)
			sum = l1->val + l2->val + 1;
		if (sum<10){
			flag = 0;
		}
		else{
			flag = 1;
			sum = sum % 10;
		}
		list1->next = new ListNode(sum);
		list1 = list1->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != NULL){
		if (flag == 0)
			sum = l1->val;
		else if (flag == 1)
			sum = l1->val + 1;
		if (sum<10){
			flag = 0;
		}
		else{
			flag = 1;
			sum = sum % 10;
		}
		list1->next = new ListNode(sum);
		list1 = list1->next;
		l1 = l1->next;
	}
	while (l2 != NULL){
		if (flag == 0)
			sum = l2->val;
		else if (flag == 1)
			sum = l2->val + 1;
		if (sum<10){
			flag = 0;
		}
		else{
			flag = 1;
			sum = sum % 10;
		}
		list1->next = new ListNode(sum);
		list1 = list1->next;
		l2 = l2->next;
	}
	if (flag == 1)
		list1->next = new ListNode(1);
	return list;
}

int main(){
	ListNode *list1 = new ListNode(2);
	list1->next = new ListNode(4);
	list1->next->next = new ListNode(3);
	ListNode *list2;
	list2  = new ListNode(5);
	list2->next = new ListNode(6);
	list2->next->next = new ListNode(4);	
	ListNode *list;
	list = addTwoNumbers(list1, list2);
	//cout << 999999991 + 9 * 1000000000 << endl;//³¬¹ýintµÄ·¶Î§ÁË
	//cout << list->val << " " << list->next->val << " " << list->next->next->val << " " << list->next->next->next->val << endl;
	system("pause");
	return 0;
}

