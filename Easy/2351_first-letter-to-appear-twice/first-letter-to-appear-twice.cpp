#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  char repeatedCharacter(std::string s)
  {
    char freq[26] = {0};

    for (char c : s)
    {
      if (freq[c - 'a']++ == 1)
        return c;
    }
    return {};
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abccbaacz"},
    {"abcdd"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nrepeatedCharacter: ";
    std::cout << Solution().repeatedCharacter(s) << std::endl;
  }
  return 0;
}
