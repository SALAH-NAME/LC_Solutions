#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int findGCD(std::vector<int>& nums)
  {
    auto [min, max] = std::minmax_element(nums.begin(),nums.end());
    return std::gcd(*min, *max);
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
  std::vector<int> n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{2,5,6,9,10}},
    {{7,5,6,8,3}},
    {{3,3}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nfindGCD: ";
    std::cout << Solution().findGCD(n) << std::endl;
  }
  return 0;
}
