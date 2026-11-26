#include <climits>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minimumCost(std::vector<int>& nums)
  {
    int first_min = INT_MAX;
    int second_min = INT_MAX;

    for (size_t i = 1; i < nums.size(); i++)
    {
      int x = nums[i];
      if (x <= first_min)
      {
        second_min = first_min;
        first_min = x;
      }
      else if (x < second_min)
      {
        second_min = x;
      }
    }
    return nums[0] + first_min + second_min;
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
    {{1,2,3,12}},
    {{5,4,3}},
    {{10,3,1,1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nminimumCost: " << Solution().minimumCost(n) << std::endl;
  }
  return 0;
}
