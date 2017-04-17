#include<iostream>
#include<map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

bool hasCycle(ListNode *head) {
	if (!head || !head->next)
		return false;
	ListNode * prev = head;
	ListNode * p = head;
	map<ListNode *, int> map;
	int i = 0;
	while (p){
		if (map.count(p))
			return true;
		map.insert(pair<ListNode *, int>(p, i));
		p = p->next;
		++i;
	}
	return false;
}

int main(){
	ListNode *head = new ListNode(1);
	head->next = head;
	bool flag = hasCycle(head);
	cout << flag << endl;
	system("pause");
	return 0;
}
