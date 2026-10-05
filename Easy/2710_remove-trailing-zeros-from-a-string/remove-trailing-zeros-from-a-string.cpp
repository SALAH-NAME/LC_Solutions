#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string removeTrailingZeros(std::string num)
  {
    int i = num.length() - 1;
    while (i >= 0 && num[i] == '0')
    {
      i--;
    }
    num.resize(i + 1);
    return num;
  }
};

typedef struct testCase
{
  std::string n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"51230100"},
    {"123"},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\nremoveTrailingZeros: ";
    std::cout << Solution().removeTrailingZeros(n) << std::endl;
  }
  return 0;
}
