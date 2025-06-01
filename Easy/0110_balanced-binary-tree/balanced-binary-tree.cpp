#include <algorithm>
#include <cstdlib>

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
	int height(TreeNode* node)
	{
		if (!node)
			return 0;
		return std::max(height(node->left), height(node->right)) + 1;
	}
	bool isBalanced(TreeNode* root)
	{
		if (!root)
			return true;
		int left_height = height(root->left);
		int right_height = height(root->right);
		if (std::abs(left_height - right_height) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};
