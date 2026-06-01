#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool checkAlmostEquivalent(std::string word1, std::string word2)
  {
    int freq_diff[26] = {0};

    for (char c : word1)
    {
      freq_diff[c - 'a']++;
    }
    for (char c : word2)
    {
      freq_diff[c - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
      if (std::abs(freq_diff[i]) > 3)
      {
        return false;
      }
    }
    return true;
  }
};

typedef struct testCase
{
  std::string w1;
  std::string w2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"aaaa", "bccb"},
    {"abcdeef", "abaaacc"},
    {"cccddabba", "babababab"},
  };

  for (auto& [w1, w2] : tests)
  {
    std::cout << "---\nword1: '" << w1 << "'\nword2: '" << w2 << "'\n";
    std::cout << "checkAlmostEquivalent: ";
    std::cout << (Solution().checkAlmostEquivalent(w1, w2) ? "True" : "False");
    std::cout << std::endl;
  }
  return 0;
}
