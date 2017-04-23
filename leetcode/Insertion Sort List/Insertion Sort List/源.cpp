#include<iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	/*ListNode* insertionSortList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode* Head = new ListNode(-1);
		Head->next = head;
		ListNode* prev = head;
		ListNode* q = head->next;
		int flag = 0;
		while (q){		
			ListNode* start = Head;
			ListNode* p = start->next;
			while (p != q){
				if (p->val>q->val){
					flag = 1;
					ListNode* temp = new ListNode(q->val);
					temp->next = p;
					start->next = temp;
					q = q->next;
					prev->next = q;
					break;
				}
				else{
					start = p;
					p = p->next;				
				}
			}
			if (flag == 0 || p == q){
				prev = q;
				q = q->next;
			}
		}
		return Head->next;
	}*/
	ListNode *insertionSortList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *list = new ListNode(0);
		list->next = head;
		ListNode *cur = head->next;
		ListNode *curprev = head;
		while (cur){
			ListNode *node = list->next;
			ListNode *prev = list;
			while (node != cur){
				if (cur->val>node->val){
					node = node->next;
					prev = prev->next;
				}
				else{
					curprev->next = cur->next;
					prev->next = cur;
					cur->next = node;
					break;
				}
			}
			if (node == cur){
				curprev = curprev->next;
				cur = cur->next;
			}
			else
				cur = curprev->next;

		}
		return list->next;
	}
};

int main(){
	ListNode* list = new ListNode(3);
	list->next = new ListNode(2);
	list->next->next = new ListNode(1);
	//list->next->next->next = new ListNode(3);
	Solution s;
	ListNode* sort = s.insertionSortList(list);
	ListNode* node = sort;
	while (node){
		std::cout << node->val << std::endl;
		node = node->next;
	}
	system("pause");
	return 0;
}