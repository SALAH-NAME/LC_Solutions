#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool digitCount(std::string num)
  {
    int freq[10] = {0};

    for (char n : num)
    {
      freq[n - '0']++;
    }

    for (int i = 0; i < num.size(); i++)
    {
      if (num[i] - '0' != freq[i])
      {
        return false;
      }
    }
    return true;
  }
};

typedef struct testCase
{
  std::string n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"1210"},
    {"030"},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\ndigitCount: ";
    std::cout << (Solution().digitCount(n) ? "True" : "False") << std::endl;
  }
  return 0;
}
