#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string maximumOddBinaryNumber(std::string s)
  {
    int ones = 0, zeros = 0;

    for (char c : s)
    {
      if (c == '1')
        ones++;
      else
        zeros++;
    }
    return std::string(ones-1, '1') + std::string(zeros, '0') + "1";
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"010"},
    {"0101"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nmaximumOddBinaryNumber: '";
    std::cout << Solution().maximumOddBinaryNumber(s) << "'" << std::endl;
  }
  return 0;
}
