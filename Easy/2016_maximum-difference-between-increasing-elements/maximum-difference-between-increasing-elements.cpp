#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maximumDifference(std::vector<int>& nums)
  {
    int max = -1;
    int min = nums[0];
    for (int i = 0; i < nums.size(); ++i)
    {
      if (nums[i] > min)
        max = std::max(max, nums[i] - min);
      else
        min = nums[i];
    }
    return max;
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
    {{7,1,5,4}},
    {{9,4,3,2}},
    {{1,5,2,10}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmaximumDifference: ";
    std::cout << Solution().maximumDifference(n) << std::endl;
  }
  return 0;
}
