
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
public:
	void innorder(TreeNode* root, int& prev, int& ans)
	{
		if (!root) return;
		
		innorder(root->left, prev, ans);

		if (prev != -1) ans = std::min(ans, root->val - prev);

		prev = root->val;
		innorder(root->right, prev, ans);
	}
	int minDiffInBST(TreeNode* root)
	{
		int ans = INT_MAX;
		int prev = -1;
		innorder(root, prev, ans);
		return ans;
	}
};
