#include <cstdio>
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
	int rangeSumBST(TreeNode* root, int low, int high)
	{
		if (!root) return 0;

		if (root->val < low)
			return rangeSumBST(root->right, low, high);
		if (root->val > high)
			return rangeSumBST(root->left, low, high);

		return root->val +
			rangeSumBST(root->left, low, high) +
			rangeSumBST(root->right, low, high);
	}
};

TreeNode* buildTree(const std::string& data)
{
	if (data.empty()) return nullptr;

	std::stringstream ss(data);
	std::string item;
	std::vector<std::string> nodes;

	while (getline(ss, item, ','))
		nodes.push_back(item);

	if (nodes.empty() || nodes[0] == "null") return nullptr;

	TreeNode* root = new TreeNode(std::stoi(nodes[0]));
	std::queue<TreeNode*> q;
	q.push(root);

	int i = 1;
	while (!q.empty() && i < nodes.size())
	{
		TreeNode* current = q.front();
		q.pop();
		if (i < nodes.size() && nodes[i] != "null")
		{
			current->left = new TreeNode(std::stoi(nodes[i]));
			q.push(current->left);
		}
		i++;

		if (i < nodes.size() && nodes[i] != "null")
		{
			current->right = new TreeNode(std::stoi(nodes[i]));
			q.push(current->right);
		}
		i++;
	}
	return root;
}

typedef struct testCase {
	std::string tree;
	int l;
	int h;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"10,5,15,3,7,null,18", 7, 15},
		{"10,5,15,3,7,13,18,1,null,6", 6, 15},
		{"10,5,15,4,7,13,18,3,null,6", 1, 2},
	};

	for (auto& tc : tests)
	{
		TreeNode* tree = buildTree(tc.tree);
		std::cout << "---\nTree: [" << tc.tree << "] low: " << tc.l << " hight: " << tc.h;
		std::cout << "\nRangeSumBST: " << Solution().rangeSumBST(tree, tc.l, tc.h);
		std::cout << std::endl;
	}
	return 0;
}
