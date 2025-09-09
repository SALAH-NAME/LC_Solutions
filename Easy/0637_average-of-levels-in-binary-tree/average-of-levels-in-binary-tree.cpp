#include <utility>
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
	std::vector<std::pair<double, int>> freq;
	void dfs(TreeNode* root, int depth = 0)
	{
		if (!root) return;
		if (depth >= freq.size())
			freq.push_back({root->val, 1});
		else
		{
			freq[depth].first += root->val;
			freq[depth].second++;
		}
		dfs(root->left, depth + 1);
		dfs(root->right, depth + 1);
	}
	std::vector<double> averageOfLevels(TreeNode* root)
	{
		dfs(root);
		std::vector<double> result;
		result.reserve(freq.size());
		for (auto& [sum, count] : freq)
			result.push_back(sum / count);
		return result;
	}
};
