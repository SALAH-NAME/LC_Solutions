#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countHillValley(std::vector<int>& nums)
  {
    int n = nums.size();
    int count = 0;
    int left = 0;

    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] == nums[i + 1])
      {
        continue;
      }

      if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) || 
          (nums[i] < nums[left] && nums[i] < nums[i + 1]))
      {
        count++;
      }
      left = i;
    }
    return count;
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
    {{2,4,1,1,6,5}},
    {{6,6,5,5,4,1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ncountHillValley: ";
    std::cout << Solution().countHillValley(n) << std::endl;
  }
  return 0;
}
