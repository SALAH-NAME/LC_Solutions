#include <iostream>
#include <vector>

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
	ListNode* middleNode(ListNode* head)
	{
		struct ListNode* slow = head, *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

struct ListNode* buildLinkedList(const std::vector<int>& vec)
{
	if (vec.empty()) return nullptr;

	struct ListNode* head = new struct ListNode(vec[0]);
	struct ListNode* curr = head;
	for (int i = 1; i < vec.size(); i++)
	{
		curr->next = new struct ListNode(vec[i]);
		curr = curr->next;
	}
	return head;
}

void printLinkedList(struct ListNode* node)
{
	while (node)
	{
		std::cout << node->val;
		node = node->next;
		if (node)
			std::cout << " -> ";
	}
}

void freeLinkedList(struct ListNode* node)
{
	struct ListNode* tmp;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

int main()
{
	std::vector<std::vector<int>> tests = {
		{1,2,3,4,5},
		{1,2,3,4,5,6},
		{1},
		{},
	};

	for (auto& tc : tests) {
		std::cout << "---\nlist :> ";
		struct ListNode* list = buildLinkedList(tc);
		struct ListNode* mid = Solution().middleNode(list);
		printLinkedList(list);
		std::cout << "\nmid: ";
		if (mid)
			std::cout << mid->val;
		else
			std::cout << "Null";
		freeLinkedList(list);
		std::cout << std::endl;
	}
	return 0;
}
