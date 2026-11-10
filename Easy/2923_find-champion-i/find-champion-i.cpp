#include <vector>
#include <iostream>

class Solution
{
public:
  int findChampion(std::vector<std::vector<int>>& grid)
  {
    int n = grid.size();
    int champion = 0;

    for (int i = 0; i < n; i++)
    {
      int wins = 0;
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          wins++;
        }
      }
      if (wins == n - 1)
      {
        return i;
      }
    }
    return -1;
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
    {{{0,1},{0,0}}},
    {{{0,0,1},{1,0,1},{0,0,0}}},
  };

  for (auto& [g] : tests)
  {
    std::cout << "---\ngrid: ";
    printM(g);
    std::cout << "\nfindChampion: " << Solution().findChampion(g) << std::endl;
  }
  return 0;
}
