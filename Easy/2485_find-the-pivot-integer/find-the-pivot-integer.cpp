#include <cmath>
#include <vector>
#include <iostream>

class Solution
{
public:
  int pivotInteger(int n)
  {
    int total_sum = n * (n + 1) / 2;
    int x = std::sqrt(total_sum);

    if (x * x == total_sum)
    {
      return x;
    }
    return -1;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {8},
    {1},
    {4},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\npivotInteger: ";
    std::cout << Solution().pivotInteger(n) << std::endl;
  }
  return 0;
}
