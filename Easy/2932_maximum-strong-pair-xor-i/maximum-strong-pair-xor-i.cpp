#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maximumStrongPairXor(std::vector<int>& nums)
  {
    int maxXor = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int x = nums[i];
        int y = nums[j];

        if (std::abs(x - y) <= std::min(x, y))
        {
          maxXor = std::max(maxXor, x ^ y);
        }
      }
    }
    return maxXor;
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
    {{1,2,3,4,5}},
    {{10,100}},
    {{5,6,25,30}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmaximumStrongPairXor: ";
    std::cout << Solution().maximumStrongPairXor(n) << std::endl;
  }
  return 0;
}
