#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countQuadruplets(std::vector<int>& nums)
  {
    int ans = 0;
    int n = nums.size();
    nums.pop_back();
    std::unordered_map<int, int> count;

    for (int b = n - 3; b >= 1; b--)
    {
      int c = b + 1;
      for (int d = c + 1; d < n; ++d)
        count[nums[d] - nums[c]]++;

      for (int a = 0; a < b; a++)
        ans += count[nums[a] + nums[b]];
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
    {{1,2,3,6}},
    {{3,3,6,4,5}},
    {{1,1,1,3,5}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ncountQuadruplets: ";
    std::cout << Solution().countQuadruplets(n) << std::endl;
  }
  return 0;
}
