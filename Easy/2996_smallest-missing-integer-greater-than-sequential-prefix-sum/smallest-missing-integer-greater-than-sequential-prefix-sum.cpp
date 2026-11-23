#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int missingInteger(std::vector<int>& nums)
  {
    int prefix_sum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] == nums[i - 1] + 1)
      {
        prefix_sum += nums[i];
      }
      else
      {
        break;
      }
    }

    std::unordered_set<int> seen(nums.begin(), nums.end());
    while (seen.count(prefix_sum))
    {
      prefix_sum++;
    }
    return prefix_sum;
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
    {{1,2,3,2,5}},
    {{3,4,5,1,12,14,13}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmissingInteger: " << Solution().missingInteger(n) << std::endl;
  }
  return 0;
}
