#include <climits>
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
	unsigned int firstMin = UINT_MAX, secondMin = UINT_MAX;
	void dfs(TreeNode* root)
	{
		if (!root) return;

		if (firstMin > root->val)
		{
			secondMin = firstMin;
			firstMin = root->val;
		}
		else if (secondMin > root->val && root->val != firstMin)
			secondMin = root->val;
		dfs(root->left);
		dfs(root->right);
	}
	int findSecondMinimumValue(TreeNode* root)
	{
		dfs(root);
		return (secondMin != UINT_MAX ? secondMin : -1);
	}
};
