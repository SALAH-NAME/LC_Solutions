#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* current = head;
		ListNode* tmp;	

		while (current && current->next)
		{
			while (current->next && current->val == current->next->val)
			{
				tmp = current->next->next;
				delete current->next;
				current->next = tmp;
			}
			current = current->next;
		}

		return head;
	}
};
