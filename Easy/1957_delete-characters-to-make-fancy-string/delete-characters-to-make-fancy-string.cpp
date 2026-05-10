#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string makeFancyString(std::string s)
  {
    std::string result = "";

    for (char c : s)
    {
      int n = result.length();
      if (n >= 2 && result[n - 1] == c && result[n - 2] == c)
      {
        continue;
      }
      result += c;
    }
    return result;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"leeetcode"},
    {"aaabaaaa"},
    {"aab"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: " << s << "'\nmakeFancyString: '";
    std::cout << Solution().makeFancyString(s) << "'" << std::endl;
  }
  return 0;
}
