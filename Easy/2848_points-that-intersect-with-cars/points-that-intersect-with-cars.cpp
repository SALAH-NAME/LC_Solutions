#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int numberOfPoints(std::vector<std::vector<int>>& nums)
  {
    std::unordered_set<int> covered;
    for (const auto& interval : nums)
    {
      for (int i = interval[0]; i <= interval[1]; i++)
      {
        covered.insert(i);
      }
    }
    return covered.size();
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0;i < v.size(); i++)
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
  for (int i = 0;i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{3,6},{1,5},{4,7}}},
    {{{1,3},{5,8}}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printM(n);
    std::cout << "\nnumberOfPoints: " << Solution().numberOfPoints(n) << std::endl;
  }
  return 0;
}
