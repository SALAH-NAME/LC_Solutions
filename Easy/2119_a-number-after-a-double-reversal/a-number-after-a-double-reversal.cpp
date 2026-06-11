#include <vector>
#include <iostream>

class Solution
{
public:
  bool isSameAfterReversals(int num)
  {
    return num == 0 || num % 10 != 0;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {526},
    {1800},
    {0},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\nisSameAfterReversals: ";
    std::cout << (Solution().isSameAfterReversals(n) ? "True" : "False") << std::endl;
  }
  return 0;
}
