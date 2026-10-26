#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool canBeEqual(std::string s1, std::string s2)
  {
    bool even_match = (s1[0] == s2[0] && s1[2] == s2[2]) || 
      (s1[0] == s2[2] && s1[2] == s2[0]);
    bool odd_match = (s1[1] == s2[1] && s1[3] == s2[3]) || 
      (s1[1] == s2[3] && s1[3] == s2[1]);
    return even_match && odd_match;
  }
};

typedef struct testCase
{
  std::string s1;
  std::string s2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abcd", "cdab"},
    {"abcd", "dacb"},
  };

  for (auto& [s1, s2] : tests)
  {
    std::cout << "---\ns1: '" << s1 << "', s2: '" << s2 << "'\ncanBeEqual: ";
    std::cout << (Solution().canBeEqual(s1, s2) ? "True" : "False" ) << std::endl;
  }
  return 0;
}
