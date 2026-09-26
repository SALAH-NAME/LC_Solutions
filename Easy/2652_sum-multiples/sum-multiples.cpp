#include <vector>
#include <iostream>
#include <iostream>

class Solution
{
public:
  int sumOfMultiples(int n)
  {
    int total_sum = 0;
    for (int i = 1; i <= n; i++)
    {
      if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
      {
        total_sum += i;
      }
    }
    return total_sum;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {7},
    {10},
    {9},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nsumOfMultiples: ";
    std::cout << Solution().sumOfMultiples(n) << std::endl;
  }
  return 0;
}
