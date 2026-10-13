#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int longestAlternatingSubarray(std::vector<int>& nums, int threshold)
  {
    int ans = 0;
    int n = nums.size();
    int l = 0;

    while (l < n)
    {
      if (nums[l] % 2 == 0 && nums[l] <= threshold)
      {
        int r = l + 1;
        while (r < n && (nums[r] % 2 != nums[r - 1] % 2) && nums[r] <= threshold)
        {
          r++;
        }
        ans = std::max(ans, r - l);
        l = r;
      }
      else
      {
        l++;
      }
    }
    return ans;
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
    {{3,2,5,4}, 5},
    {{1,2}, 2},
    {{2,3,4,5}, 4},
  };

  for (auto& [n, t] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", threshold: " << t << "\nlongestAlternatingSubarray: ";
    std::cout << Solution().longestAlternatingSubarray(n, t) << std::endl;
  }
  return 0;
}
