#include <vector>
#include <iostream>

class Solution
{
public:
  int commonFactors(int a, int b)
  {
    int count = 0;
    int limit = std::min(a, b);
    for (int i = 1; i <= limit; i++)
    {
      if (a % i == 0 && b % i == 0) count++;
    }
    return count;
  }
};

typedef struct testCase
{
  int a;
  int b;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {12, 6},
    {25, 30},
  };

  for (auto& [a, b] : tests)
  {
    std::cout << "---\na: " << a << ", b: " << b << "\ncommonFactors: ";
    std::cout << Solution().commonFactors(a, b) << std::endl;
  }
  return 0;
}
