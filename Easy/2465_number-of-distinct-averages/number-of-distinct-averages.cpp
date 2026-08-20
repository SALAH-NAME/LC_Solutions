#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int distinctAverages(std::vector<int>& nums)
  {
    std::sort(nums.begin(), nums.end());
    std::unordered_set<int> distinctSums;
    int n = nums.size();

    for (int i = 0; i < n / 2; i++)
    {
      distinctSums.insert(nums[i] + nums[n - 1 - i]);
    }
    return distinctSums.size();
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
    {{4,1,4,0,3,5}},
    {{1,100}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ndistinctAverages: ";
    std::cout << Solution().distinctAverages(n) << std::endl;
  }
  return 0;
}
