#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool isFascinating(int n)
  {
    std::string s= std::to_string(n) + std::to_string(2 * n) + std::to_string(3 * n);
    std::sort(s.begin(), s.end());
    return s == "123456789";
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {192},
    {100},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nisFascinating: ";
    std::cout << Solution().isFascinating(n) << std::endl;
  }
  return 0;
}
