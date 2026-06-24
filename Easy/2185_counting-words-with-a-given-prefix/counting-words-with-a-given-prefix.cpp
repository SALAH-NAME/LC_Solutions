#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int prefixCount(std::vector<std::string>& words, std::string pref)
  {
    int count = 0;
    for (auto& w : words)
    {
      if (w.rfind(pref, 0) == 0)
        count++;
    }
    return count;
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
  std::string p;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"pay","attention","practice","attend"}, "at"},
    {{"leetcode","win","loops","success"}, "code"},
  };

  for (auto& [w, p] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << ", pref: '" << p << "'\nprefixCount: ";
    std::cout << Solution().prefixCount(w, p) << std::endl;
  }
  return 0;
}
