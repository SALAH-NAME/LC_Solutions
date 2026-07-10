#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string removeDigit(std::string number, char digit)
  {
    int last_idx = -1;
    int n = number.size();

    for (int i = 0; i < n; i++)
    {
      if (number[i] == digit)
      {
        last_idx = i;
        if (i + 1 < n && number[i + 1] > digit)
        {
          return number.erase(i, 1);
        }
      }
    }
    return number.erase(last_idx, 1);
  }
};

typedef struct testCase
{
  std::string n;
  char d;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"123", '3'},
    {"1231", '1'},
    {"551", '5'},
  };

  for (auto& [n, d] : tests)
  {
    std::cout << "---\nnumber: '" << n << "', digit: `" << d << "`\nremoveDigit: ";
    std::cout << Solution().removeDigit(n, d) << std::endl;
  }
  return 0;
}
