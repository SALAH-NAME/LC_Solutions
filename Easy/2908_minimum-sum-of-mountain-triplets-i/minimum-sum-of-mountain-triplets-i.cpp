#include <algorithm>
#include <vector>
#include <iostream>


class Solution
{
public:
  int minimumSum(std::vector<int>& nums)
  {
    int n = nums.size();
    if (n < 3) return -1;

    std::vector<int> right(n + 1, 1e9);
    for (int i = n - 1; i >= 0; i--)
    {
      right[i] = std::min(right[i + 1], nums[i]);
    }

    int ans = 1e9;
    int left = 1e9;

    for (int i = 0; i < n; i++)
    {
      int x = nums[i];
      if (left < x && right[i + 1] < x)
      {
        ans = std::min(ans, left + x + right[i + 1]);
      }
      left = std::min(left, x);
    }
    return ans == 1e9 ? -1 : ans;
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
    {{8,6,1,5,3}},
    {{5,4,8,7,10,2}},
    {{6,5,4,3,4,5}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nminimumSum: " << Solution().minimumSum(n) << std::endl;
  }
  return 0;
}
