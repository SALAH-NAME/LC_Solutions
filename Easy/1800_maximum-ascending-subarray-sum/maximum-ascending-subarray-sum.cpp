#include <vector>
#include <iostream>

class Solution
{
public:
  int maxAscendingSum(std::vector<int>& nums)
  {
    int best = nums[0];
    int current = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[i] > nums[i - 1])
      {
        current += nums[i];
      }
      else
      {
        current = nums[i];
      }
      if (current > best)
      {
        best = current;
      }
    }
    return best;
  }
};

typedef struct testCase
{
  std::vector<int> nums;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{10,20,30,5,10,50}},
    {{10,20,30,40,50}},
    {{12,17,15,13,10,11,12}},
    {{100,10,1}}
  };

  for (auto& [nums] : tests)
  {
    std::cout << "---\nnums: ";
    for (auto n : nums)
    {
      std::cout << n << " ";
    }
    std::cout << "\nmaxAscendingSum: ";
    std::cout << Solution().maxAscendingSum(nums) << std::endl;
  }

  return 0;
}

