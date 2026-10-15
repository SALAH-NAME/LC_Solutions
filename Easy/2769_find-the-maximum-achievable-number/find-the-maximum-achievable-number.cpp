#include <vector>
#include <iostream>

class Solution
{
public:
  int theMaximumAchievableX(int num, int t)
  {
    return num + (2 * t);
  }
};

typedef struct testCase
{
  int n;
  int t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {4, 1},
    {3, 2},
  };

  for (auto& [n, t] : tests)
  {
    std::cout << "---\nnum: " << n << ", t: " << t << std::endl;
    std::cout << "theMaximumAchievableX: " << Solution().theMaximumAchievableX(n, t);
    std::cout << std::endl;
  }
  return 0;
}
