
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{

		ListNode sorted;
		ListNode* tmp = &sorted;

		ListNode* current_1 = list1;
		ListNode* current_2 = list2;

		while (current_1 && current_2)
		{
			if (current_1->val <= current_2->val)
			{
				tmp->next = current_1;
				current_1 = current_1->next;
			}
			else
			{
				tmp->next = current_2;
				current_2 = current_2->next;
			}
			tmp = tmp->next;
		}
		if (current_1)
			tmp->next = current_1;
		if (current_2)
			tmp->next = current_2;

		return sorted.next;
	}
};
