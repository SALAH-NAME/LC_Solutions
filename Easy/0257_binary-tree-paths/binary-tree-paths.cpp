#include <string>
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
	void dfs(TreeNode* node, std::string currentPath, std::vector<std::string>& paths)
	{
		if (!node)
			return ;
		currentPath += std::to_string(node->val);
		if (node->left || node->right)
			currentPath += "->";
		if (!node->left && !node->right)
			paths.push_back(currentPath);
		dfs(node->left, currentPath, paths);
		dfs(node->right, currentPath, paths);
	}

	std::vector<std::string> binaryTreePaths(TreeNode* root)
	{
		std::vector<std::string> paths;
		dfs(root, "",paths);	
		return paths;
 	}
};
