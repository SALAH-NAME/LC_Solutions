#include <cstddef>
#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
  bool isAcronym(std::vector<std::string>& words, std::string s)
  {
    if (words.size() != s.length())
    {
      return false;
    }
    for (size_t i = 0; i < s.length(); i++)
    {
      if (words[i][0] != s[i])
      {
        return false;
      }
    }
    return true;
  }
};

void printV(const std::vector<std::string>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::string> w;
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"alice","bob","charlie"}, "abc"},
    {{"an","apple"}, "a"},
    {{"never","gonna","give","up","on","you"}, "ngguoy"},
  };

  for (auto& [w, s] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\ns: '" << s << "'\nisAcronym: ";
    std::cout << (Solution().isAcronym(w, s) ? "True" : "False") << std::endl;
  }
  return 0;
}
