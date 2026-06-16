#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minimumCost(std::vector<int>& cost)
  {
    std::sort(cost.begin(), cost.end(), std::greater<>());

    int total_cost = 0;
    for (int i = 0; i < cost.size(); i++)
    {
      if ((i + 1) % 3 == 0)
        continue;
      total_cost += cost[i];
    }

    return total_cost;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size())
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<int> c;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,3}},
    {{6,5,7,9,2,2}},
    {{5,5}},
  };

  for (auto& [c] : tests)
  {
    std::cout << "---\ncoast: ";
    printV(c);
    std::cout << "\nminimumCost: ";
    std::cout << Solution().minimumCost(c) << std::endl;
  }
  return 0;
}
