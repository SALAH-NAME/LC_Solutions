#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countAsterisks(std::string s)
  {
    bool inside_bars = false;
    int count = 0;

    for (char c : s)
    {
      if (c == '|')
      {
        inside_bars = !inside_bars;
      }
      else if (c == '*' && !inside_bars)
      {
        count++;
      }
    }
    return count;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"l|*e*et|c**o|*de|"},
    {"iamprogrammer"},
    {"yo|uar|e**|b|e***au|tifu|l"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\ncountAsterisks: ";
    std::cout << Solution().countAsterisks(s) << std::endl;
  }
  return 0;
}
