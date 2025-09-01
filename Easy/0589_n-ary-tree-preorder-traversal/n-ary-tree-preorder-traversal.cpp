#include <cstddef>
#include <vector>

// Definition for a Node.
class Node
{
public:
  int val;
	std::vector<Node*> children;

  Node() {}

  Node(int _val)
	{
      val = _val;
  }

  Node(int _val, std::vector<Node*> _children)
	{
      val = _val;
      children = _children;
  }
};


class Solution
{
private:
	void dfs(Node* root, std::vector<int>& result)
	{
		if (!root) return ;
		result.push_back(root->val);
		for (auto child : root->children)
			dfs(child, result);
	}
	std::size_t estimateSize(Node* node)
	{
		if (!node) return 0;
		size_t count = 1;
		for (auto child : node->children) count += estimateSize(child);
		return count;
	}
public:
	std::vector<int> preorder(Node* root)
	{
		std::vector<int> result;
		result.reserve(estimateSize(root));
		dfs(root, result);
		return result;
	}
};
