#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool checkString(std::string s)
  {
    bool b_found = false;

    for (const char c : s)
    {
      if (b_found && c == 'a') return false;
      if (c == 'b') b_found = true;
    }
    return true;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"aaabbb"},
    {"abab"},
    {"bbb"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns= '" << s << "'\ncheckString: ";
    std::cout << (Solution().checkString(s) ? "True" : "False") << std::endl;
  }
  return 0;
}
