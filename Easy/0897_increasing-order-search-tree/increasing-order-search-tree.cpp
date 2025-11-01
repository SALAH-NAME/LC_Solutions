#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
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
	TreeNode* increasingBST(TreeNode* root)
	{
		TreeNode dummy = TreeNode(-1);
		TreeNode* curr = &dummy;

		std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
			if (!node) return;
			inorder(node->left);
			node->left = nullptr;
			curr->right = node;
			curr = node;
			inorder(node->right);
		};

		inorder(root);
		return dummy.right;
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
	if (data.empty()) return nullptr;

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

std::string printTree(TreeNode* root)
{
	if (!root) return "[]";
	
	std::vector<std::string> result;
	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();

		if (node)
		{
			result.push_back(std::to_string(node->val));
			q.push(node->left);
			q.push(node->right);
		}
		else
		{
			result.push_back("null");
		}
	}
	while (!result.empty() && result.back() == "null")
		result.pop_back();

	std::string output = "[";
	for (std::size_t i = 0; i < result.size(); i++)
	{
		output += result[i];
		if (i + 1 < result.size()) output += ",";
	}
	output += "]";
	return output;
}

int main()
{
	std::vector<std::string> tests = {
			"5,3,6,2,4,null,8,1,null,null,null,7,9",
			"5,1,7",
		};

	for (auto& tree : tests)
	{
		auto root = buildTree(tree);
		auto res = Solution().increasingBST(root);
		std::cout << "---\nTree: [" << tree << "]\nResult: " << printTree(res) << std::endl;
	}
	return 0;
}
