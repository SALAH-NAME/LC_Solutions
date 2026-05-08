#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int getLucky(std::string s, int k)
  {
    std::string numericStr = "";
    for (char ch : s)
    {
      numericStr += std::to_string(ch - 'a' + 1);
    }

    int currentSum = 0;
    while (k--)
    {
      currentSum = 0;
      for (char digit : numericStr)
      {
        currentSum += (digit - '0');
      }

      numericStr = std::to_string(currentSum);
      if (numericStr.length() == 1) break;
    }
    return currentSum;
  }
};

typedef struct testCase
{
  std::string s;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"iiii", 5},
    {"leetcode", 2},
    {"zbax", 2},
  };

  for (auto& [s, k] : tests)
  {
    std::cout << "---\ns: '" << s << "', k: " << k << "\ngetLucky: ";
    std::cout << Solution().getLucky(s, k) << std::endl;
  }
  return 0;
}
