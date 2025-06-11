#include <vector>
#include <stack>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	std::vector<int> postorderTraversal(TreeNode* root)
	{
		std::vector<int> result;
		if (!root)
			return result;
		std::stack<TreeNode*> nodes;
		std::stack<TreeNode*> nodes_post;
		TreeNode* current;
		nodes.push(root);
		while (!nodes.empty())
		{
			current = nodes.top();
			nodes.pop();
			nodes_post.push(current);
			if (current->left)
				nodes.push(current->left);
			if (current->right)
				nodes.push(current->right);
		}
		while (!nodes_post.empty())
		{
			result.push_back(nodes_post.top()->val);
			nodes_post.pop();
		}
    return result;
	}
};
