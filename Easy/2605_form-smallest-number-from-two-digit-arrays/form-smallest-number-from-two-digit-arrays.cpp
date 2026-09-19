#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minNumber(std::vector<int>& nums1, std::vector<int>& nums2)
  {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());

    int min1 = 10;
    int min2 = 10;
    int common_min = 10;

    for (int num : nums1)
    {
      min1 = std::min(min1, num);
    }

    for (int num : nums2)
    {
      min2 = std::min(min2, num);
      if (set1.count(num))
      {
        common_min = std::min(common_min, num);
      }
    }

    if (common_min != 10)
    {
      return common_min;
    }

    int tens = std::min(min1, min2);
    int ones = std::max(min1, min2);
    return tens * 10 + ones;
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
  std::vector<int> n1;
  std::vector<int> n2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{4,1,3}, {5,7}},
    {{3,5,2,6}, {3,1,7}},
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nnums1: ";
    printV(n1);
    std::cout << ", nums2: ";
    printV(n2);
    std::cout << "\nminNumber: " << Solution().minNumber(n1, n2) << std::endl;
  }
  return 0;
}
