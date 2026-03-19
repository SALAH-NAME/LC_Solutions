#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countConsistentStrings(std::string allowed, std::vector<std::string>& words)
  {
    std::unordered_set<char> allowedSet(allowed.begin(), allowed.end());
    int count = 0;

    for (const auto& word : words)
    {
      bool consistent = true;
      for (char c : word)
      {
        if (allowedSet.find(c) == allowedSet.end())
        {
          consistent = false;
          break;
        }
      }
      if (consistent) count++;
    }
    return count;
  }
};

typedef struct testCase
{
  std::string a;
  std::vector<std::string> w;
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
    {"ab", {"ad","bd","aaab","baa","badab"}},
    {"abc", {"a","b","c","ab","ac","bc","abc"}},
    {"cad", {"cc","acd","b","ba","bac","bad","ac","d"}},
  };

  for (auto& [a, w] : tests)
  {
    std::cout << "---\nallowed: '" << a << "', words: ";
    printV(w);
    std::cout << "\ncountConsistentStrings: ";
    std::cout << Solution().countConsistentStrings(a, w) << std::endl;
  }
  return 0;
}
