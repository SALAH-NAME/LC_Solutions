
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		if (!head || !head->next) return true;

		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* prev = nullptr;
		ListNode* curr = slow->next;
		while (curr)
		{
			ListNode* nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}

		ListNode* p1 = head;
		ListNode* p2 = prev;
		bool isTrue = true;
		while (p2)
		{
			if (p1->val != p2->val) { isTrue = false; break; }
			p1 = p1->next;
			p2 = p2->next;
		}

		/*curr = prev; prev = nullptr;*/
		/*while (curr)*/
		/*{*/
		/*	ListNode* nxt = curr->next;*/
		/*	curr->next = prev;*/
		/*	prev = curr;*/
		/*	curr = nxt;*/
		/*}*/
		/*slow->next = prev;*/
		return isTrue;
	}
};
