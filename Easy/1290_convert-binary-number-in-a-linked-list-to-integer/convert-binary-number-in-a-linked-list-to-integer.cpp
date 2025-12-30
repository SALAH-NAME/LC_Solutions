#include <vector>
#include <iostream>

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
	int getDecimalValue(ListNode* head)
	{
		int value = 0;

		while (head)
		{
			value = (value << 1) | head->val;
			head = head->next;
		}
		return value;
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
		{1,0,1},
		{0},
	};

	for (auto& t : tests)
	{
		ListNode* list = buildLinkedList(t);
		std::cout << "---\narr: ";
		printLinkedList(list);
		std::cout << "\ngetDecimalValue: " << Solution().getDecimalValue(list);
		std::cout << std::endl;
	}
		return 0;
}
