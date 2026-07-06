#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findClosestNumber(std::vector<int>& nums)
  {
    int closest = nums[0];

    for (int n : nums)
    {
      if (std::abs(n) < std::abs(closest))
      {
        closest = n;
      }
      else if (std::abs(n) == std::abs(closest) && n > closest)
      {
        closest = n;
      }
    }
    return closest;
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
    {{-4,-2,1,4,8}},
    {{2,-1,1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nfindClosestNumber: ";
    std::cout << Solution().findClosestNumber(n) << std::endl;
  }
  return 0;
}
