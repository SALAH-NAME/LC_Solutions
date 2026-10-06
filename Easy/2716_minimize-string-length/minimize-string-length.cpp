#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int minimizedStringLength(std::string s)
  {
    int mask = 0;
    for (char c : s)
    {
      mask |= (1 << (c - 'a'));
    }
    return __builtin_popcount(mask);
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"aaabc"},
    {"cbbd"},
    {"baadccab"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nminimizedStringLength: ";
    std::cout << Solution().minimizedStringLength(s) << std::endl;
  }
  return 0;
}
