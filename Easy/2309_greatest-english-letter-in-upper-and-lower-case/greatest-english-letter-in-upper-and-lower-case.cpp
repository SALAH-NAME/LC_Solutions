#include <cctype>
#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string greatestLetter(std::string s)
  {
    std::unordered_set<char> charSet(s.begin(), s.end());

    for (char ch = 'Z'; ch >= 'A'; --ch)
    {
      if (charSet.count(ch) && charSet.count(ch + 32))
      {
        return std::string(1, ch);
      }
    }
    return "";
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"lEeTcOdE"},
    {"arRAzFif"},
    {"AbCdEfGhIjK"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\ngreatestLetter: '";
    std::cout << Solution().greatestLetter(s) << "'" << std::endl;
  }
  return 0;
}
