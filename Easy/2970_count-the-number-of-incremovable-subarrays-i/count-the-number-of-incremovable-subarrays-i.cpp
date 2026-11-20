#include <vector>
#include <iostream>

class Solution
{
public:
  int incremovableSubarrayCount(std::vector<int>& nums)
  {
    int n = static_cast<int>(nums.size());

    int i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1])
    {
      i++;
    }
    if (i == n - 1)
    {
      return (n * (n + 1) / 2);
    }
    int ans = i + 2;
    for (int j = n - 1; j > 0; j--)
    {
      while (i >= 0 && nums[i] >= nums[j])
      {
        i--;
      }
      ans += i + 2;
      if (nums[j - 1] >= nums[j])
      {
        break;
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
    {{1,2,3,4}},
    {{6,5,7,8}},
    {{8,7,6,6}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nincremovableSubarrayCount: ";
    std::cout << Solution().incremovableSubarrayCount(n) << std::endl;
  }
  return 0;
}
