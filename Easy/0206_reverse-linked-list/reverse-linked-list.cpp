
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
	ListNode* reverseList(ListNode* head)
	{
		if (!head)
			return nullptr;

		ListNode* curr = head;
		ListNode* prev = nullptr;
		while (curr)
		{
			ListNode* tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		return prev;
	}
};
