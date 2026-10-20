#include <vector>
#include <iostream>

class Solution
{
public:
  int accountBalanceAfterPurchase(int purchaseAmount)
  {
    int roundedAmount = ((purchaseAmount + 5) / 10) * 10;
    return 100 - roundedAmount;
  }
};

typedef struct testCase
{
  int p;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {9},
    {15},
    {10},
  };

  for (auto& [p] : tests)
  {
    std::cout << "---\npurchaseAmount: " << p << "\naccountBalanceAfterPurchase: ";
    std::cout << Solution().accountBalanceAfterPurchase(p) << std::endl;
  }
  return 0;
}
