#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int buyChoco(std::vector<int>& prices, int money)
  {
    std::sort(prices.begin(), prices.end());

    int cost = prices[0] + prices[1];

    if (cost <= money)
    {
      return money - cost;
    }
    return money;
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

typedef struct testCase
{
  std::vector<int> p;
  int m;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,2}, 4},
    {{3,2,3}, 3},
  };

  for (auto& [p, m] : tests)
  {
    std::cout << "---\nprices: ";
    printV(p);
    std::cout << "\nmooney: " << m << "\nbuyChoco: ";
    std::cout << Solution().buyChoco(p, m) << std::endl;
  }
  return 0;
}
