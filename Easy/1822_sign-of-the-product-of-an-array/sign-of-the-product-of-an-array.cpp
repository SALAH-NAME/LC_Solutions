#include <iostream>
#include <vector>

class Solution
{
public:
  int arraySign(std::vector<int>& nums)
  {
    int sign = 1;
    for (int n : nums)
    {
      if (n == 0)
      {
        return 0;
      }
      else if (n < 0)
      {
        sign = -sign;
      }
    }
    return sign;
  }
};

typedef struct testCase
{
  std::vector<int> nums;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{-1, -2, -3, -4, 3, 2, 1}},
    {{1, 5, 0, 2, -3}},
    {{-1, 1, -1, 1, -1}},
    {{2, 3, 4}},
    {{0}}
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
    std::cout << "arraySign: " << Solution().arraySign(nums) << std::endl;
  }

  return 0;
}
