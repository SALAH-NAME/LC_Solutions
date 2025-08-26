#include <algorithm>
#include <vector>

// Definition for a Node.
class Node
{
public:
  int val;
	std::vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node*> _children)
	{
      val = _val;
      children = _children;
  }
};


class Solution
{
public:
	int maxDepth(Node* root)
	{
		if (!root) return 0;
		short max = 0;
		for (auto child : root->children)
			max = std::max(static_cast<int>(max), maxDepth(child));
		return max + 1;
	}
};
