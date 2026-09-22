#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<int> ans(cols, 0);

    for (int j = 0; j < cols; j++)
    {
      int max_len = 0;
      for (int i = 0; i < rows; i++)
      {
        int len = std::to_string(grid[i][j]).length();
        max_len = std::max(max_len, len);
      }
      ans[j] = max_len;
    }
    return ans;
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
  std::vector<std::vector<int>> g;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{1},{22},{333}}},
    {{{-15,1,3},{15,7,12},{5,6,-2}}},
  };

  for (auto& [g] : tests)
  {
    std::cout << "---\ngrid: ";
    printM(g);
    std::cout << "\nfindColumnWidth: ";
    printV(Solution().findColumnWidth(g));
    std::cout << std::endl;
  }
  return 0;
}
