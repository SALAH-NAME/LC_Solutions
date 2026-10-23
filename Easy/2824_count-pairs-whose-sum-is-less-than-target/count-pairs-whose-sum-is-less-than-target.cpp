#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countPairs(std::vector<int>& nums, int target)
  {
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int count = 0;

    while (left < right)
    {
      if (nums[left] + nums[right] < target)
      {
        count += (right - left);
        left++;
      }
      else
      {
        right--;
      }
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
  int t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{-1,1,2,3,1}, 2},
    {{-6,2,5,-2,-7,-1,3}, -2},
  };

  for (auto& [n, t] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", target: " << t << "\ncountPairs: ";
    std::cout << Solution().countPairs(n, t) << std::endl;
  }
  return 0;
}
