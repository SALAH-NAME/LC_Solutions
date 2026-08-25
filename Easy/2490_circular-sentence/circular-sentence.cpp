#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool isCircularSentence(std::string sentence)
  {
    for (int i = 0; i < sentence.length(); i++)
    {
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
      {
        return false;
      }
    }
    return sentence.front() == sentence.back();
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"leetcode exercises sound delightful"},
    {"eetcode"},
    {"Leetcode is cool"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nisCircularSentence: ";
    std::cout << (Solution().isCircularSentence(s) ? "True" : "False") << std::endl;
  }
  return 0;
}
