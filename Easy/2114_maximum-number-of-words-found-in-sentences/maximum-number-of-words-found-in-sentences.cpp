#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int mostWordsFound(std::vector<std::string>& sentences)
  {
    int max_words = 0;
    for (auto& s : sentences)
    {
      int spaces = std::count(s.begin(), s.end(), ' ');
      max_words = std::max(max_words, spaces + 1);
    }
    return max_words;
  }
};

typedef struct testCase
{
  std::vector<std::string> s;
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
    {{"alice and bob love leetcode","i think so too","this is great thanks very much"}},
    {{"please wait","continue to fight","continue to win"}}
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\nsentences: ";
    printV(s);
    std::cout << "\nmostWordsFound: ";
    std::cout << Solution().mostWordsFound(s) << std::endl;
  }
  return 0;
}
