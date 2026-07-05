#include <string>
#include <vector>
#include <iostream>


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
  bool checkTree(TreeNode* root)
  {
    if (root == nullptr || root->left == nullptr || root->right == nullptr)
      return false;
    return root->val == (root->left->val + root->right->val);
  }
};

TreeNode* buildTree(const std::vector<int>& data)
{
  if (data.size() < 3)
    return nullptr;
  TreeNode* root = new TreeNode(data[0]);
  root->left = new TreeNode(data[1]);
  root->right = new  TreeNode(data[2]);
  return root;
}

typedef struct testCase
{
  std::vector<int> r;
} testCase;

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

int main()
{
  std::vector<testCase> tests = {
    {{10,4,6}},
    {{5,3,1}},
  };

  for (auto& [r] : tests)
  {
    std::cout << "---\nroot: ";
    printV(r);
    TreeNode* root = buildTree(r);
    std::cout << "\ncheckTree: ";
    std::cout << (Solution().checkTree(root) ? "True" : "False") << std::endl;
  }
  return 0;
}
