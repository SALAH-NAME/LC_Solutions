#include <string_view>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int countPrefixes(std::vector<std::string>& words, std::string s)
  {
    int count = 0;
    std::string_view sv(s);

    for (const auto& w : words)
    {
      if (w.length() <= sv.length())
      {
        if (sv.substr(0, w.length()) == w)
        {
          count++;
        }
      }
    }
    return count;
  }
};

typedef struct testCase
{
  std::vector<std::string> w;
  std::string s;
} testCase;

void printV(const std::vector<std::string>& w)
{
  std::cout << "{";
  for (int i = 0; i < w.size(); i++)
  {
    std::cout << w[i];
    if (i < w.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

int main()
{
  std::vector<testCase> tests = {
    {{"a","b","c","ab","bc","abc"}, "abc"},
    {{"a","a"}, "aa"},
  };

  for (auto& [w, s] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << ", s: '" << s << "'\ncountPrefixes: ";
    std::cout << Solution().countPrefixes(w, s) << std::endl;
  }
  return 0;
}
