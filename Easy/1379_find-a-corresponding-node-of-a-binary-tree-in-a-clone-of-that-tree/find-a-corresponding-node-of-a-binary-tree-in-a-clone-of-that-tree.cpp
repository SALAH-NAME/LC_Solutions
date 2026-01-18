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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
	{
		if (!original || !cloned) return nullptr;
		if (original == target) return cloned;
		TreeNode* left = getTargetCopy(original->left, cloned->left, target);
		if (left) return left;
		return getTargetCopy(original->right, cloned->right, target);
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

TreeNode* cloneTree(TreeNode* root)
{
	if (!root) return nullptr;
	TreeNode* newNode = new TreeNode(root->val);
	newNode->left = cloneTree(root->left);
	newNode->right = cloneTree(root->right);
	return newNode;
}

TreeNode* findNode(TreeNode* root, int val)
{ if (!root) return nullptr;
	if (root->val == val) return root;
	TreeNode* left = findNode(root->left, val);
	if (left) return left;
	return findNode(root->right, val);
}

typedef struct testCase
{
	std::string teeStr;
	int targetVal;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{"7,4,3,null,null,6,19", 3},
			{"7", 7},
			{"8,null,6,null,5,null,4,null,3,null,2,null,1", 4},
		};

	for (auto& [treeStr, targetVal] : tests)
	{
		std::cout << "---\ntree: [" << treeStr << "], target: " << targetVal << "\n";
		TreeNode* original = buildTree(treeStr);
		TreeNode* cloned = cloneTree(original);
		TreeNode* target = findNode(original, targetVal);
		TreeNode* result = Solution().getTargetCopy(original, cloned, target);
		std::cout << "getTargetCopy: " << (result ? std::to_string(result->val) : "null") << std::endl;
	}
	return 0;
}
