#include <vector>
#include <iostream>

class Solution
{
public:
  int sumOfSquares(std::vector<int>& nums)
  {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      if (n % (i + 1) == 0)
      {
        ans += nums[i] * nums[i];
      }
    }
    return ans;
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
    {{1,2,3,4}},
    {{2,7,1,19,18,3}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nsumOfSquares: " << Solution().sumOfSquares(n) << std::endl;
  }
  return 0;
}
