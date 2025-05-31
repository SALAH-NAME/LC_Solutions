#include <vector>

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
	TreeNode* buildBalancedBST(std::vector<int>& nums, int start_index, int end_index)
	{
		if (start_index > end_index)
			return nullptr;
		int mid_index = (start_index + end_index) / 2;
		TreeNode* node = new TreeNode(nums[mid_index]);
		node->left = buildBalancedBST(nums, start_index, mid_index - 1);
		node->right = buildBalancedBST(nums, mid_index + 1, end_index);
		return node;
	}
	TreeNode* sortedArrayToBST(std::vector<int>& nums)
	{
		return buildBalancedBST(nums, 0, nums.size() - 1)	;	
	}
};
