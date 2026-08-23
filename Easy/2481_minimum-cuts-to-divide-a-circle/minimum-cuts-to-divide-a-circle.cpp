#include <vector>
#include <iostream>

class Solution
{
public:
  int numberOfCuts(int n)
  {
    if (n == 1) return 0;
    return n % 2 == 0 ? n / 2 : n;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {4},
    {3},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nnumberOfCuts: ";
    std::cout << Solution().numberOfCuts(n) << std::endl;
  }
  return 0;
}
