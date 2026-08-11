#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  bool equalFrequency(std::string word)
  {
    for (int i = 0; i < word.length(); ++i)
    {
      std::unordered_map<char, int> freq;

      for (int j = 0; j < word.length(); j++)
      {
        if (i == j) continue;
        freq[word[j]]++;
      }

      int common_freq = -1;
      bool all_equal = true;
      for (const auto& pair : freq)
      {
        if(common_freq == -1)
        {
          common_freq = pair.second;
        }
        else if (pair.second != common_freq)
        {
          all_equal = false;
          break;
        }
      }
      if (all_equal) return true;
    }
    return false;
  }
};

typedef struct testCase
{
  std::string w;
} testCase;

int main()
{
  std::vector<std::string> tests = {
    {"abcc"},
    {"aazz"},
  };

  for (auto& w : tests)
  {
    std::cout << "---\nword: '" << w << "'\nequalFrequency: ";
    std::cout << (Solution().equalFrequency(w) ? "True" : "False") << std::endl;
  }
  return 0;
}
