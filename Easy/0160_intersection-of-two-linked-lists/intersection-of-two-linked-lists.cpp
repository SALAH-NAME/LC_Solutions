#include <cmath>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (!headA || !headB) return nullptr;

		int lenA = 0, lenB = 0;
		for (auto p = headA; p; p = p->next) ++lenA;
		for (auto p = headB; p; p = p->next) ++lenB;

		auto pa = headA;
		auto pb = headB;
		int diff = std::abs(lenA - lenB);
		if (lenA > lenB)
			while (diff--) pa = pa->next;
		else
			while (diff--) pb = pb->next;

		while (pa && pb && pa != pb)
		{
			pa = pa->next;
			pb = pb->next;
		}
		return pa;
	}
};
