#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minMaxGame(std::vector<int>& nums)
  {
    int n = nums.size();

    while (n > 1)
    {
      n /= 2;
      for (int i = 0; i < n; i++)
      {
        if (i % 2 == 0)
        {
          nums[i] = std::min(nums[2 * i], nums[2 * i + 1]);
        }
        else
        {
          nums[i] = std::max(nums[2 * i], nums[2 * i + 1]);
        }
      }
    }
    return nums[0];
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
    {{1,3,5,2,4,8,2,2}},
    {{3}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nminMaxGame: " << Solution().minMaxGame(n) << std::endl;
  }
  return 0;
}
