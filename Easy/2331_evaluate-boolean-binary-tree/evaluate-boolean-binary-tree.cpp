#include <iostream>
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
  bool evaluateTree(TreeNode* root)
  {
    if (root->left == nullptr && root->right == nullptr)
    {
      return root->val == 1;
    }

    bool leftValue = evaluateTree(root->left);
    bool rightValue = evaluateTree(root->right);
    if (root->val == 2)
    {
      return leftValue || rightValue;
    }
    return leftValue && rightValue;
  }
};

int main()
{
  TreeNode* root = new TreeNode(2,
    new TreeNode(1),
    new TreeNode(3,
      new TreeNode(0),
      new TreeNode(1)
    )
  );

  std::cout << "Result: " << (Solution().evaluateTree(root) ? "True" : "False");
  std::cout << std::endl;
  return 0;
}
