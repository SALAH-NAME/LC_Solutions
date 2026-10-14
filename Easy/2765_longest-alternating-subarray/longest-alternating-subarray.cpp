#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int alternatingSubarray(std::vector<int>& nums)
  {
    int ans = 1;
    int dp = 1;
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
      int target_diff = (dp % 2 == 0) ? -1 : 1;
      
      if (nums[i] - nums[i - 1] == target_diff)
      {
        dp++;
      }
      else if (nums[i] - nums[i - 1] == 1)
      {
        dp = 2;
      }
      else
      {
        dp = 1;
      }
      ans = std::max(ans, dp);
    }
    return (ans == 1) ? -1 : ans;
  }
};

typedef struct testCase
{
  std::vector<int> n;
} testCase;

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

int main()
{
  std::vector<testCase> tests = {
    {{2,3,4,3,4}},
    {{4,5,6}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nalternatingSubarray: ";
    std::cout << Solution().alternatingSubarray(n) << std::endl;
  }
  return 0;
}
