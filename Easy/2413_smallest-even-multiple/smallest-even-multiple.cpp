#include <vector>
#include <iostream>

class Solution
{
public:
  int smallestEvenMultiple(int n)
  {
    return (n % 2 == 0) ? n : n * 2;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {5},
    {6},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nsmallestEvenMultiple: ";
    std::cout << Solution().smallestEvenMultiple(n) << std::endl;
  }
  return 0;
}
