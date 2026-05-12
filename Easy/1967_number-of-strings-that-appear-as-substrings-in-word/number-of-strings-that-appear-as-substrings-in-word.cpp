#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int numOfStrings(std::vector<std::string>& patterns, std::string word)
  {
    int count = 0;
    for (const std::string& p : patterns)
    {
      if (word.find(p) != std::string::npos)
      {
        count++;
      }
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
  std::vector<std::string> p;
  std::string word;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"a","abc","bc","d"}, "abc"},
    {{"a","b","c"}, "aaaaabbbbb"},
    {{"a","a","a"}, "ab"},
  };

  for (auto& [p, w] : tests)
  {
    std::cout << "---\npatterns: ";
    printV(p);
    std::cout << ", word: '" << w << "'\nnumOfStrings: ";
    std::cout << Solution().numOfStrings(p, w) << std::endl;
  }
  return 0;
}
