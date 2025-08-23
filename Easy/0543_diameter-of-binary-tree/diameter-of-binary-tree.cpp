
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
private:
	int _maxPath = 0;

	unsigned short dfs(TreeNode* root)
	{
		if (!root) return 0;
		short left = 0;
		short right = 0;
		left = dfs(root->left);
		right = dfs(root->right);
		_maxPath = std::max(_maxPath, left + right);
		return std::max(left, right) + 1;

	}

public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		dfs(root);
		return _maxPath;
	}
};
