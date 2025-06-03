
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
	bool checkPathSum(TreeNode* root, int targetSum, int indexSum)
	{
		if (!root)
			return false;
		indexSum += root->val;
		if (!root->left && !root->right)
			return targetSum == indexSum;
		return checkPathSum(root->left, targetSum, indexSum) || checkPathSum(root->right, targetSum, indexSum);
	}
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (checkPathSum(root, targetSum, 0))
			return true;
		return false;
	}
};
