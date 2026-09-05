#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int alternateDigitSum(int n)
  {
    int ans = 0;
    int sign = 1;
    std::string num_str  = std::to_string(n);
    for (char c : num_str)
    {
      ans += sign * (c - '0');
      sign *= -1;
    }
    return ans;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {521},
    {111},
    {886996},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nalternateDigitSum: ";
    std::cout << Solution().alternateDigitSum(n) << std::endl;
  }
  return 0;
}
