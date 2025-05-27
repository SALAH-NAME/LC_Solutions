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
	std::vector<int> concat(std::vector<int>& vec1, std::vector<int> vec2)
	{
		vec1.reserve(vec1.size() + vec2.size());
		vec1.insert(vec1.end(), vec2.begin(), vec2.end());
		return vec1;
	}
	std::vector<int> inorderTraversal(TreeNode* root)
	{
		std::vector<int> res;
		
		if (!root)
			return res;
		if (root->left)
			concat(res, inorderTraversal(root->left));
		res.push_back(root->val);
		if (root->right)
			concat(res, inorderTraversal(root->right));

		return res;
	}
};
