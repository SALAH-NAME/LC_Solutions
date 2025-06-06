#include <algorithm>

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
	int minDepth(TreeNode* root)
	{
		if (!root)
			return 0;

		int res = 1;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0 || right == 0)
			res += std::max(left, right);
		else
			res += (left < right) ? left : right;
		return res;
	}
};
