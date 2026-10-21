#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string finalString(std::string s)
  {
    std::string res = "";
    for (char c : s)
    {
      if (c == 'i')
      {
        std::reverse(res.begin(), res.end());
      }
      else
      {
        res += c;
      }
    }
    return res;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"string"},
    {"poiinter"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nfinalString: '";
    std::cout << Solution().finalString(s) << "'" << std::endl;
  }
  return 0;
}
