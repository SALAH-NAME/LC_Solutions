#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int deleteGreatestValue(std::vector<std::vector<int>>& grid)
  {
    for (auto& row : grid)
    {
      std::sort(row.begin(), row.end());
    }

    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int j = 0; j < n; j++)
    {
      int max_column = 0;
      for (int i = 0; i < m; i++)
      {
        max_column = std::max(max_column, grid[i][j]);
      }
      ans += max_column;
    }
    return ans;
  }
};

typedef struct testCase
{
  std::vector<std::vector<int>> g;
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

int main()
{
  std::vector<testCase> tests = {
    {{{1,2,4},{3,3,1}}},
    {{{10}}},
  };

  for (auto& [g] : tests)
  {
    std::cout << "---\ngrid: ";
    printM(g);
    std::cout << "\ndeleteGreatestValue: ";
    std::cout << Solution().deleteGreatestValue(g) << std::endl;
  }
  return 0;
}
