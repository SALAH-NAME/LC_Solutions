#include <algorithm>
#include <functional>
#include <vector>
#include <iostream> 

class Solution
{
public:
  std::vector<int> sortEvenOdd(std::vector<int>& nums)
  {
    std::vector<int> evens, odds;

    for (int i = 0; i < nums.size(); i++)
    {
      if (i % 2 == 0)
      {
        evens.push_back(nums[i]);
      }
      else
      {
        odds.push_back(nums[i]);
      }
    }

    std::sort(evens.begin(), evens.end());
    std::sort(odds.begin(), odds.end(), std::greater<>());

    int evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i % 2 == 0)
      {
        nums[i] = evens[evenIdx++];
      }
      else
      {
        nums[i] = odds[oddIdx++];
      }
    }
    return nums;
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
    {{4,1,2,3}},
    {{2,1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nsortEvenOdd: ";
    printV(Solution().sortEvenOdd(n));
    std::cout << std::endl;
  }
  return 0;
}
