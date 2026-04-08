#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool areAlmostEqual(std::string s1, std::string s2)
  {
    if (s1.size() != s2.size())
      return false;

    std::vector<int> diff;
    for (int i = 0; i < s1.size(); ++i)
    {
      if (s1[i] != s2[i])
        diff.push_back(i);
    }

    if (diff.empty())
      return true;
    if (diff.size() == 2)
      return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    return false;
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
    {"bank", "kanb"},
    {"attack", "defend"},
    {"kelb", "kelb"},
    {"abcd", "abdc"}
  };

  for (auto& [s1, s2] : tests)
  {
    std::cout << "---\ns1: '" << s1 << "', s2: '" << s2 << "'\n";
    std::cout << "areAlmostEqual: ";
    std::cout << (Solution().areAlmostEqual(s1, s2) ? "true" : "false") << std::endl;
  }

  return 0;
}

