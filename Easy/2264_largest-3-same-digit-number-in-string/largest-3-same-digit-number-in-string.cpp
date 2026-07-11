#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string largestGoodInteger(std::string num)
  {
    for (int i = 9; i >= 0; --i)
    {
      std::string sub(3, '0' + i);
      if (num.find(sub) != std::string::npos)
      {
        return sub;
      }
    }
    return "";
  }
};

typedef struct testCase
{
  std::string n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"6777133339"},
    {"2300019"},
    {"42352338"},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: '" << n << "'\nlargestGoodInteger: '";
    std::cout << Solution().largestGoodInteger(n) << "'" << std::endl;
  }
  return 0;
}
