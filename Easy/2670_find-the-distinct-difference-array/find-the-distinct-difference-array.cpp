#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> distinctDifferenceArray(std::vector<int>& nums)
  {
    int n = nums.size();
    std::vector<int> suf(n + 1, 0);
    std::unordered_set<int> seen;

    for (int i = n - 1; i >= 0; i--)
    {
      seen.insert(nums[i]);
      suf[i] = seen.size();
    }

    seen.clear();
    std::vector<int> diff;
    diff.reserve(n);

    for (int i = 0; i < n; i++)
    {
      seen.insert(nums[i]);
      int prefex_distinct = seen.size();
      int suffix_distinct = suf[i + 1];
      diff.push_back(prefex_distinct - suffix_distinct);
    
    }
    return diff;
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
    {{1,2,3,4,5}},
    {{3,2,3,4,2}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ndistinctDifferenceArray: ";
    printV(Solution().distinctDifferenceArray(n));
    std::cout << std::endl;
  }
  return 0;
}
