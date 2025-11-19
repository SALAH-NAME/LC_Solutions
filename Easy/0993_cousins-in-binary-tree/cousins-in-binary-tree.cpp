#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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
	bool isCousins(TreeNode* root, int x, int y)
	{
		if (!root) return false;

		std::queue<std::pair<TreeNode*, TreeNode*>> q;
		q.push({root, nullptr});
		while (!q.empty())
	{
			int size = q.size();
			TreeNode* parentX = nullptr;
			TreeNode* parentY = nullptr;

			for (int i = 0; i < size; i++)
			{
				auto [node, parrent] = q.front();
				q.pop();
				if (node->val == x) parentX = parrent;
				if (node->val == y) parentY = parrent;

				if (node->left) q.push({node->left, node});
				if (node->right) q.push({node->right, node});
			}

			if (parentX && parentY)
				return parentX != parentY;
			if (parentX || parentY)
				return false;
		}
    return false;
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

typedef struct testCase
{
	std::string t;
	int x;
	int y;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{"1,2,3,4", 4, 3},
			{"1,2,3,null,4,null,5", 5, 4},
			{"1,2,3,null,4", 2, 3},
		};

	for (auto& [t, x, y] : tests)
	{
		std::cout << "---\ntree: [" << t << "], x: " << x << ", y: " << y << "\n";
		TreeNode* tree = buildTree(t);
		std::cout << "isCousins: " << (Solution().isCousins(tree, x, y) ? "True" : "False");
		std::cout << std::endl;
	}
}
