#include <bitset>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool checkValid(std::vector<std::vector<int>>& matrix)
  {
    size_t n = matrix.size();

    for (int x = 0; x < n; x++)
    {
      std::bitset<101> row;
      std::bitset<101> col;
      for (int y = 0; y < n; y++)
      {
        if (row.test(matrix[y][x])) return false;
        row.set(matrix[y][x]);
        if (col.test(matrix[x][y])) return false;
        col.set(matrix[x][y]);
      }
    }
    return true;
  }
};

typedef struct testCase
{
  std::vector<std::vector<int>> m;
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

void printMat(std::vector<std::vector<int>>& m)
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

int main()
{
  std::vector<testCase> tests = {
    {{{1,2,3},{3,1,2},{2,3,1}}},
    {{{1,1,1},{1,2,3},{1,2,3}}},
  };

  for (auto& [m] : tests)
  {
    std::cout << "---\nmatrix: ";
    printMat(m);
    std::cout << "\ncheckValid: ";
    std::cout << (Solution().checkValid(m) ? "True" : "False") << std::endl;
  }
  return 0;
}
