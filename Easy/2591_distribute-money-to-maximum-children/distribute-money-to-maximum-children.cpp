#include <vector>
#include <iostream>

class Solution
{
public:
  int distMoney(int money, int children)
  {
    if (money < children)
    {
      return -1;
    }
    if (money > 8 * children)
    {
      return children - 1;
    }
    if (money == 8 * children - 4)
    {
      return children - 2;
    }
    return (money - children) / 7;
  }
};

typedef struct testCase
{
  int m;
  int c;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {20, 3},
    {16, 2},
  };

  for (auto& [m, c] : tests)
  {
    std::cout << "---\nmoney: " << m << ", children: " << c << "\ndistMoney: ";
    std::cout << Solution().distMoney(m, c) << std::endl;
  }
  return 0;
}
