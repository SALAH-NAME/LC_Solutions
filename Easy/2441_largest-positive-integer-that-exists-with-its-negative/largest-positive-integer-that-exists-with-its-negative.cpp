#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findMaxK(std::vector<int>& nums)
  {
    std::unordered_set<int> seen(nums.begin(), nums.end());
    int ans = -1;

    for (int x : seen)
    {
      if (x > 0 && seen.count(-x))
      {
        ans = std::max(ans, x);
      }
    }
    return ans;
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
    {{-1,2,-3,3}},
    {{-1,10,6,7,-7,1}},
    {{-10,8,6,7,-2,-3}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nfindMaxK: " << Solution().findMaxK(n) << std::endl;
  }
  return 0;;
}
