#include <vector>
#include <iostream>

class Solution
{
public:
  bool checkXMatrix(std::vector<std::vector<int>>& grid)
  {
    int n = grid.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j || i + j == n - 1)
        {
          if (grid[i][j] == 0) return false;
        }
        else
        {
          if (grid[i][j] != 0) return false;
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

void printM(const std::vector<std::vector<int>>& m)
{
  std::cout << "{";
  for (int i = 0; i < m.size(); i++)
  {
    printV(m[i]);
    if (i < m.size() - 1)
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
    {{{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}}},
    {{{5,7,0},{0,3,1},{0,5,0}}},
  };

  for (auto& [m] : tests)
  {
    std::cout <<  "---\ngrid: ";
    printM(m);
    std::cout <<  "\ncheckXMatrix: ";
    std::cout << (Solution().checkXMatrix(m) ? "True" : "False") << std::endl;
  }
  return 0;
}
