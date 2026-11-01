#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minOperations(std::vector<int>& nums, int k)
  {
    std::unordered_set<int> seen;
    int operations = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      operations++;
      if (nums[i] <= k)
      {
        seen.insert(nums[i]);
      }
      if (seen.size() == k)
      {
        return operations;
      }
    }
    return operations;
  }
};

typedef struct testCase
{
  std::vector<int> n;
  int k;
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
    {{3,1,5,4,2}, 2},
    {{3,1,5,4,2}, 5},
    {{3,2,5,3,1}, 3},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\nminOperations: ";
    std::cout << Solution().minOperations(n, k) << std::endl;
  }
  return 0;
}
