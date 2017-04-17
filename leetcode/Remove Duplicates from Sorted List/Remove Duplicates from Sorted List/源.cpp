

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr){
			return nullptr;
		}
		ListNode* p = head;
		ListNode* q = p->next;
		ListNode* temp = head;
		while (q != nullptr){
			if (p->val == q->val)
				;
			else{
				if (p->val != p->next->val){
					head = temp = p;
					break;
				}
				p = q;
			}
			q = q->next;
		}
		p = p->next;
		q = q->next;
		while (q != nullptr){
			if (p->val == q->val)
				;
			else{
				if (p->val != p->next->val){
					temp->next = p;
					temp = temp->next;
				}
				p = q;
			}
			q = q->next;
		}
		temp->next = nullptr;
		return head;
	}
};

int main(){
	ListNode* list = new ListNode(1);
/*	list->next = new ListNode(1);
	list->next->next = new ListNode(2);
	ListNode* list1 = list->next->next;
	list1->next = new ListNode(3);
	list1->next->next = new ListNode(3);
	ListNode* list2 = list1->next->next;
	list2->next = new ListNode(4);
	list2->next->next = new ListNode(5);
	ListNode* list3 = list2->next->next;
	list3->next = new ListNode(6);
	list3->next->next = new ListNode(6);*/
	Solution s;
	ListNode* p = s.deleteDuplicates(list);
}