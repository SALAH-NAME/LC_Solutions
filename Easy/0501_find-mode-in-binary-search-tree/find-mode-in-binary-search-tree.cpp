#include <climits>
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
	std::vector<int> _modes;
	int _prev = INT_MIN;
	unsigned short _currCount = 0;
	unsigned short _maxCount = 0;

	void inorder(TreeNode* node)
	{
		if (!node) return ;
		inorder(node->left);

		if (node->val == _prev)
			++_currCount;
		else
			_currCount = 1;

		if (_currCount > _maxCount)
		{
			_maxCount = _currCount;
			_modes.clear();
			_modes.push_back(node->val);
		}
		else if (_currCount == _maxCount)
			_modes.push_back(node->val);

		_prev = node->val;

		inorder(node->right);
	}

public:
	std::vector<int> findMode(TreeNode* root)
	{
		inorder(root);
		return _modes;
	}
};
