#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int maxDivScore(std::vector<int>& nums, std::vector<int>& divisors)
  {
    int ans = divisors[0];
    int mx = -1;
    
    for (int div : divisors)
    {
      int cnt = 0;
      for (int x : nums)
      {
        if (x % div == 0)
        {
          cnt++;
        }
      }
      
      if (cnt > mx)
      {
        mx = cnt;
        ans = div;
      }
      else if (cnt == mx)
      {
        ans = std::min(ans, div);
      }
    }
    return ans;
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
  std::vector<int> nums;
  std::vector<int> divisors;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{2, 9, 15, 50}, {5, 3, 7, 2}},
    {{4, 7, 9, 3, 9}, {5, 2, 3}},
    {{20, 14, 21, 10}, {10, 16, 20}},
  };

  for (auto& [nums, divisors] : tests)
  {
    std::cout << "---\nnums: ";
    printV(nums);
    std::cout << "\ndivisors: ";
    printV(divisors);
    std::cout << "\nmaxDivScore: ";
    std::cout << Solution().maxDivScore(nums, divisors);
    std::cout << std::endl;
  }
  return 0;
}
