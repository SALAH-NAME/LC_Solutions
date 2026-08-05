#include <sched.h>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool findSubarrays(std::vector<int>& nums)
  {
    std::unordered_set<int> seen;

    for (int i = 0; i < nums.size() - 1; i++)
    {
      int current_sum = nums[i] + nums[i + 1];
      if (seen.count(current_sum))
      {
        return true;
      }
      seen.insert(current_sum);
    }
    return false;
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
    {{4,2,4}},
    {{1,2,3,4,5}},
    {{0,0,0}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums:";
    printV(n);
    std::cout << "\nfindSubarrays: ";
    std::cout << (Solution().findSubarrays(n) ? "True" : "False") << std::endl;
  }
  return 0;
}
