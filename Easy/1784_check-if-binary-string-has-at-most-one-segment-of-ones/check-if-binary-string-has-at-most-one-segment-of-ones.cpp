#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool checkOnesSegment(std::string s)
  {
    return s.find("01") == std::string::npos;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"1001"},
    {"110"},
    {"1111"},
    {"101"}
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\nstring: '" << s << "'\n";
    std::cout << "checkOnesSegment: ";
    std::cout << (Solution().checkOnesSegment(s) ? "true" : "false") << std::endl;
  }

  return 0;
}

