#include <vector>
#include <iostream>

class Solution
{
public:
  int sum(int num1, int num2)
  {
    return num1 + num2;
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
    {12, 5},
    {-10, 4},
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nnum1: " << n1 << ", num2: " << n2 << "\nsum: ";
    std::cout << Solution().sum(n1, n2) << std::endl;
  }
  return 0;
}
