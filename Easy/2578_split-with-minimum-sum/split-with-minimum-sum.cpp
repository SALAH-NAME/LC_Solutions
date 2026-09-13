#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int splitNum(int num)
  {
    std::string s = std::to_string(num);
    std::sort(s.begin(), s.end());

    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (i % 2 == 0)
      {
        num1 = num1 * 10 + (s[i] - '0');
      }
      else
      {
        num2 = num2 * 10 + (s[i] - '0');
      }
    }
    return num1 + num2;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {4325},
    {687},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\nsplitNum: " << Solution().splitNum(n);
    std::cout << std::endl;
  }
  return 0;
}
