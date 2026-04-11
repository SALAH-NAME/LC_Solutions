#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <cctype>

class Solution
{
public:
  int numDifferentIntegers(std::string word)
  {
    std::set<std::string> uniqueNums;
    int i = 0;

    while (i < word.size())
    {
      if (std::isdigit(word[i]))
      {
        int j = i;
        while (j < word.size() && std::isdigit(word[j]))
        {
          ++j;
        }
        std::string num = word.substr(i, j - i);

        int k = 0;
        while (k < num.size() && num[k] == '0')
        {
          ++k;
        }
        num = num.substr(k);

        if (num.empty())
        {
          num = "0";
        }

        uniqueNums.insert(num);
        i = j;
      }
      else
      {
        ++i;
      }
    }

    return uniqueNums.size();
  }
};

typedef struct testCase
{
  std::string word;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"a123bc34d8ef34"},
    {"leet1234code234"},
    {"a1b01c001"},
    {"abc"}
  };

  for (auto& [word] : tests)
  {
    std::cout << "---\nword: '" << word << "'\n";
    std::cout << "numDifferentIntegers: ";
    std::cout << Solution().numDifferentIntegers(word) << std::endl;
  }

  return 0;
}

