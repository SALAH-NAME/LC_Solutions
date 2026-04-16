#include <iostream>
#include <vector>

class Solution
{
public:
  int minOperations(std::vector<int>& nums)
  {
    int operations = 0;
    for (size_t i = 1; i < nums.size(); ++i)
    {
      if (nums[i] <= nums[i - 1])
      {
        int needed = nums[i - 1] + 1 - nums[i];
        operations += needed;
        nums[i] += needed;
      }
    }
    return operations;
  }
};

typedef struct testCase
{
  std::vector<int> nums;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,1,1}},
    {{1,5,2,4,1}},
    {{8}},
    {{3,3,3,3}},
    {{1,2,3,4,5}}
  };

  for (auto& [nums] : tests)
  {
    std::cout << "---\nnums: [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
      std::cout << nums[i];
      if (i + 1 < nums.size()) std::cout << ", ";
    }
    std::cout << "]\n";
    std::cout << "minOperations: " << Solution().minOperations(nums) << std::endl;
  }

  return 0;
}
