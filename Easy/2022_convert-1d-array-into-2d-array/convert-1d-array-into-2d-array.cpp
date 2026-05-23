#include <cstddef>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n)
  {
    if (original.size() != (size_t)m * n)
    {
      return {};
    }

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < original.size(); i++)
    {
      result[i / n][i % n] = original[i];
    }
    return result;
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

void printMat(const std::vector<std::vector<int>>& m)
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
  std::vector<int> o;
  int m;
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,3,4}, 2, 2},
    {{1,2,3}, 1, 3},
    {{1, 2}, 1, 1},
  };

  for (auto& [o, m, n] : tests)
  {
    std::cout << "---\noriginal: ";
    printV(o);
    std::cout << ", m: " << m << ", n: " << n << "\nconstruct2DArray: ";
    printMat(Solution().construct2DArray(o, m, n));
    std::cout << std::endl;
  }
  return 0;
}
