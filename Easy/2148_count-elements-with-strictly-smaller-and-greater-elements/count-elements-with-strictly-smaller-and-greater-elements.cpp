#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countElements(std::vector<int>& nums)
  {
    if (nums.size() < 3) return 0;

    auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
    int min_val = *min_it;
    int max_val = *max_it;

    int count = 0;
    for (int num : nums)
    {
      if (num > min_val && num < max_val)
        count++;
    }
    return count;
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
    {{11,7,2,15}},
    {{-3,3,3,90}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ncountElements: ";
    std::cout << Solution().countElements(n) << std::endl;
  }
  return 0;
}
