#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> targetIndices(std::vector<int>& nums, int target)
  {
    int less_than_target = 0;
    int equal_to_target = 0;

    for (int num : nums)
    {
      if (num < target)
      {
        less_than_target++;
      }
      else if (num == target)
      {
        equal_to_target++;
      }
    }

    std::vector<int> result;
    result.reserve(equal_to_target);

    for (int i = 0; i < equal_to_target; ++i)
    {
      result.push_back(less_than_target + i);
    }
    return result;
  }
};

typedef struct testCase
{
  std::vector<int> n;
  int t;
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
    {{1,2,5,2,3}, 2},
    {{1,2,5,2,3}, 3},
    {{1,2,5,2,3}, 5},
  };

  for (auto& [n, t] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", target: " << t << "\ntargetIndices: ";
    printV(Solution().targetIndices(n, t));
    std::cout << std::endl;
  }
  return 0;
}
