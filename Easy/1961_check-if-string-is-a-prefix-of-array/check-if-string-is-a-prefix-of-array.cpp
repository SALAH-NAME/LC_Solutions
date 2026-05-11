#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool isPrefixString(std::string s, std::vector<std::string>& words)
  {
    std::string prefix = "";

    for (const std::string& word : words)
    {
      prefix += word;
      if (prefix == s)
      {
        return true;
      }
      if (prefix.length() > s.length())
      {
        return false;
      }
    }
    return false;
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
  std::string s;
  std::vector<std::string> w;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"iloveleetcode", {"i","love","leetcode","apples"}},
    {"iloveleetcode", {"apples","i","love","leetcode"}},
  };

  for (auto& [s, w] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nwords: ";
    printV(w);
    std::cout << "\nisPrefixString: ";
    std::cout << (Solution().isPrefixString(s, w) ? "True" : "False") << std::endl;
  }
  return 0;
}
