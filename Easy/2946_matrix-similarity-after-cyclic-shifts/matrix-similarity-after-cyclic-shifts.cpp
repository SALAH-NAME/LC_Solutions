#include <vector>
#include <iostream>

class Solution
{
public:
  bool areSimilar(std::vector<std::vector<int>>& mat, int k)
  {
    int n = mat[0].size();
    k %= n;

    for (const auto& row : mat)
    {
      for (int j = 0; j < n; j++)
      {
        if (row[j] != row[(j + k) % n ])
        {
          return false;
        }
      }
    }
    return true;
  }
};

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

void printM(const std::vector<std::vector<int>>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> m;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{1,2,3},{4,5,6},{7,8,9}}, 4},
    {{{1,2,1,2},{5,5,5,5},{6,3,6,3}}, 2},
    {{{2,2},{2,2}}, 3},
  };

  for (auto& [m, k] : tests)
  {
    std::cout << "---\nmat: ";
    printM(m);
    std::cout << ", k: " << k << "\nareSimilar: ";
    std::cout << Solution().areSimilar(m, k) << std::endl;
  }
  return 0;
}
