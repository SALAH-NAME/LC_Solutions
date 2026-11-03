#include <vector>
#include <iostream>

class Solution
{
public:
  int differenceOfSums(int n, int m)
  {
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      if (i % m == 0)
      {
        ans -= i;
      }
      else
      {
        ans += i;
      }
    }
    return ans;
  }
};

typedef struct testCase
{
  int n;
  int m;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {10, 3},
    {5, 6},
    {5, 1},
  };

  for (auto& [n, m] : tests)
  {
    std::cout << "---\nn: " << n << ", m: " << m << "\ndifferenceOfSums: ";
    std::cout << Solution().differenceOfSums(n, m) << std::endl;
  }
  return 0;
}
