#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int distinctIntegers(int n)
  {
    return std::max(1, n - 1);
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {5},
    {3},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\ndistinctIntegers: ";
    std::cout << Solution().distinctIntegers(n) << std::endl;
  }
  return 0;
}
