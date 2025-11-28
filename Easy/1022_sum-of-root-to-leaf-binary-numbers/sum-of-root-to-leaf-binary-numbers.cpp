#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

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
	int dfs(TreeNode* root, int val)
	{
		if (!root) return 0;
		val = (val << 1) | root->val;
		if (!root->left && !root->right)
			return val;
		return dfs(root->left, val) + dfs(root->right, val);
	}
	int sumRootToLeaf(TreeNode* root)
	{
		return dfs(root, 0);
	}
};

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::stringstream ss(s);
	while (std::getline(ss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

TreeNode* buildTree(const std::string& data)
{
	if (data.empty())
		return nullptr;

	std::vector<std::string> values = split(data, ',');
	if (values.empty() || values[0] == "null") return nullptr;

	TreeNode* root = new TreeNode(std::stoi(values[0]));
	std::queue<TreeNode*> q;
	q.push(root);
	int i = 1;

	while (!q.empty() && i < values.size())
	{
		TreeNode* node = q.front();
		q.pop();

		if (i < values.size() && values[i] != "null")
		{
			node->left = new TreeNode(std::stoi(values[i]));
			q.push(node->left);
		}
		i++;
		if (i < values.size() && values[i] != "null")
		{
			node->right = new TreeNode(std::stoi(values[i]));
			q.push(node->right);
		}
		i++;
	}
	return root;
}


int main()
{
	std::vector<std::string> tests = {
			"1,0,1,0,1,0,1",
			"0",
		};

	for (auto& t : tests)
	{
		TreeNode* tree = buildTree(t);
		std::cout << "---\ntree: [" << t << "]\nsumRootToLeaf: ";
		std::cout << Solution().sumRootToLeaf(tree) << std::endl;
	}
}
