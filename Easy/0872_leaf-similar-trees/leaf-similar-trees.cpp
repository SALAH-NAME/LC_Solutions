#include <climits>
#include <cstddef>
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
private:
	void dfs(const TreeNode* root, std::vector<int>& arr)
	{
		if (!root) return;

		if (!root->left && !root->right) arr.push_back(root->val);

		dfs(root->left, arr);
		dfs(root->right, arr);
	}

public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2)
	{
		std::vector<int> arr1;
		std::vector<int> arr2;

		dfs(root1, arr1);
		dfs(root2, arr2);
		return arr1 == arr2;
	}
};


std::vector<int> parseInput(const std::string& data)
{
	std::vector<int> result;
	std::string token;
	std::stringstream ss(data);

	while (std::getline(ss, token, ','))
	{
		if (token == "null")
			result.push_back(INT_MIN);
		else
			result.push_back(std::stoi(token));
	}
	return result;
}

TreeNode* buildTree(const std::string& data)
{
	std::vector<int> values = parseInput(data);
	if (values.empty() || values[0] == INT_MIN) return nullptr;

	TreeNode* root = new TreeNode(values[0]);
	std::queue<TreeNode*> q;
	q.push(root);
	int i = 1;

	while (i < values.size())
	{
		TreeNode* current = q.front();
		q.pop();

		if (i < values.size() && values[i] != INT_MIN)
		{
			current->left = new TreeNode(values[i]);
			q.push(current->left);
		}
		i++;

		if (i < values.size() && values[i] != INT_MIN)
		{
			current->right = new TreeNode(values[i]);
			q.push(current->right);
		}
		i++;
	}
	return root;
}

void freeTree(TreeNode* root)
{
	if (!root) return;
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

template <typename T>
void printVector(const std::vector<T>& vec)
{
	std::cout << "[";
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
}

typedef struct testCase
{
	std::string v1;
	std::string v2;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"3,5,1,6,2,9,8,null,null,7,4","3,5,1,6,7,4,2,null,null,null,null,null,null,9,8"},
		{"1,2,3","1,3,2"},
		{"1,2","1,2"},
		{"1,2,3,null,4,3","1,2,3,4,null,null,3"},
		{"",""},
	};
	
	for (auto& tc : tests)
	{
		std::cout << "---\nroot1=[" << tc.v1 << "] root2=[" << tc.v2 << "]";
		TreeNode* r1 = buildTree(tc.v1);
		TreeNode* r2 = buildTree(tc.v2);
		std::cout << "\nleafSimilar: " << (Solution().leafSimilar(r1, r2) ? "True" : "False");
		std::cout << std::endl;
		freeTree(r1);
		freeTree(r2);
	}
	return 0;
}
