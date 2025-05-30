
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
	bool isSym(TreeNode* p, TreeNode* q)
	{
		if(!p && !q) return true;
		if(!p || !q) return false;

		return (p->val == q->val) && isSym(p->left, q->right) && isSym(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root)
	{
		(void)root;
		return isSym(root->left, root->right);
	}
};
