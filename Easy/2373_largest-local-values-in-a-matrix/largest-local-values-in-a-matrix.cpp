#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid)
  {
    int n = grid.size();
    std::vector<std::vector<int>> maxLocal(n - 2, std::vector<int>(n - 2, 0));

    for (int i = 1; i < n - 1; i++)
    {
      for (int j = 1; j < n - 1; j++)
      {
        int maxVal = 0;
        for (int r = i - 1; r <= i + 1; r++)
        {
          for (int c = j - 1; c <= j +1; c++)
          {
            maxVal = std::max(maxVal, grid[r][c]);
          }
        }
        maxLocal[i - 1][j - 1] = maxVal;
      }
    }
    return maxLocal;
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
    {{{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}}},
    {{{1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}}},
  };

  for (auto& [g] : tests)
  {
    std::cout << "---\ngrid: ";
    printM(g);
    std::cout << "\nlargestLocal: ";
    printM(Solution().largestLocal(g));
    std::cout << std::endl;
  }
  return 0;
}
