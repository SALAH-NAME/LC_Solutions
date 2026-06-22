#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countOperations(int num1, int num2)
  {
    int op = 0;

    while (num1 > 0 && num2 > 0)
    {
      if (num1 >= num2)
      {
        op += num1 / num2;
        num1 %= num2;
      }
      else
      {
        op += num2 / num1;
        num2 %= num1;
      }
    }
    return op;
  }
};

typedef struct testCase
{
  int n1;
  int n2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {2, 3},
    {5, 4},
    {10, 10},
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nnum1: " << n1 << ", num2: " << n2 << "\ncountOperations: ";
    std::cout << Solution().countOperations(n1, n2) << std::endl;
  }
  return 0;
}
