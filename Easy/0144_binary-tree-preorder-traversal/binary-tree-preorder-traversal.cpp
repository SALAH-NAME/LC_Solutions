#include <vector>
#include <stack>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (!root)
            return result;
        
        std::stack<TreeNode*> nodes;
        TreeNode* current;
        nodes.push(root);
        while (!nodes.empty())
        {
            current = nodes.top();
            nodes.pop();
            result.push_back(current->val);
            if (current->right)
                nodes.push(current->right);
            if (current->left)
                nodes.push(current->left);
        }
        return result;
    }
};
