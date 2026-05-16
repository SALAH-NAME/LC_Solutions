#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

class Solution
{
public:
  int minimumDifference(std::vector<int>& nums, int k)
  {
    if (k <= 1) return 0;
    std::sort(nums.begin(), nums.end());
    int min = INT_MAX;
    for (int i = 0; i <= nums.size() - k; i++)
    {
      int current = nums[i + k - 1] - nums[i];
      if (current < min)
        min = current;
    }
    return min;
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
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{90}, 1},
    {{9,4,1,7}, 2},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\nminimumDifference: ";
    std::cout << Solution().minimumDifference(n, k) << std::endl;
  }
  return 0;
}
