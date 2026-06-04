#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2)
  {
    std::unordered_map<std::string, int> count1;
    std::unordered_map<std::string, int> count2;

    for (auto& w : words1)
      count1[w]++;
    for (auto& w : words2)
      count2[w]++;

    int common = 0;
    for (auto const& [w, f] : count1)
    {
      if (f == 1 && count2[w] == 1) common++;
    }
    return common;
  }
};

typedef struct testCase
{
  std::vector<std::string> w1;
  std::vector<std::string> w2;
} testCase;

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

int main()
{
  std::vector<testCase> tests = {
    {{"leetcode","is","amazing","as","is"}, {"amazing","leetcode","is"}},
    {{"b","bb","bbb"}, {"a","aa","aaa"}},
    {{"a","ab"}, {"a","a","a","ab"}},
  };

  for (auto& [w1, w2] : tests)
  {
    std::cout << "---\nwords1: ";
    printV(w1);
    std::cout << "\nwords2: ";
    printV(w2);
    std::cout << "\ncountWords: ";
    std::cout << Solution().countWords(w1, w2) << std::endl;
  }
  return 0;
}
