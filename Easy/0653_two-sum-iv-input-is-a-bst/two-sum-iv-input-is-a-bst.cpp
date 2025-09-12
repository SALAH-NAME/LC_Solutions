#include <cstddef>
#include <unordered_set>
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
	std::unordered_set<int> freq;
	void inorder(TreeNode* root, std::vector<int>& nums)
	{
		if (!root) return ;
		inorder(root->left, nums);
		nums.push_back(root->val);
		inorder(root->right, nums);
	}

	std::size_t estimatedSize(TreeNode* root)
	{
		if (!root) return 0;
		return (estimatedSize(root->left) + estimatedSize(root->right) + 1);
	}

	bool findTarget(TreeNode* root, int k)
	{
		std::vector<int> nums;
		nums.reserve(estimatedSize(root));
		inorder(root, nums);

		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int sum = nums[left] + nums[right];
			if (sum == k) return true;
			else if (sum < k) left++;
			else right--;
		}
		return false;
	}
};
