#include <algorithm>
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
private:
	int minDiff = INT_MAX;
	int prevVal = -1;

	void dfs(TreeNode* root)
	{
		if (!root) return;
		dfs(root->left);
		if (prevVal != -1) minDiff = std::min(minDiff, root->val - prevVal);
		prevVal = root->val;
		dfs(root->right);
	}
public:
	int getMinimumDifference(TreeNode* root)
	{
		dfs(root);
		return minDiff;
	}
};
