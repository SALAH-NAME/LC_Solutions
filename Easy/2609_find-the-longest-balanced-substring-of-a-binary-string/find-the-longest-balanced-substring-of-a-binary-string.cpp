#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findTheLongestBalancedSubstring(std::string s)
  {
    int ans = 0;
    int i = 0;
    int n = s.length();

    while (i < n)
    {
      int zeros = 0;
      int ones = 0;

      while (i < n && s[i] == '0')
      {
        zeros++;
        i++;
      }

      while (i < n && s[i] == '1')
      {
        ones++;
        i++;
      }
      ans = std::max(ans, std::min(zeros, ones));
    }
    return ans * 2;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"01000111"},
    {"00111"},
    {"111"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nfindTheLongestBalancedSubstring: ";
    std::cout << Solution().findTheLongestBalancedSubstring(s) << std::endl;
  }
  return 0;
}
