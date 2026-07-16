#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int rearrangeCharacters(std::string s, std::string target)
  {
    std::vector<int> sCounts(26, 0);
    std::vector<int> tCounts(26, 0);

    for (char c : s)
    {
      sCounts[c - 'a']++;
    }
    for (char c : target)
    {
      tCounts[c - 'a']++;
    }

    int maxCopies = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
      if (tCounts[i] > 0)
      {
        maxCopies = std::min(maxCopies, sCounts[i] / tCounts[i]);
      }
    }
    return maxCopies;
  }
};

typedef struct testCase
{
  std::string s;
  std::string t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"ilovecodingonleetcode", "code"},
    {"abcba", "abc"},
    {"abbaccaddaeea", "aaaaa"},
  };

  for (auto& [s, t] : tests)
  {
    std::cout << "---\ns: '" << s << "', target: '" << t << "'\n";
    std::cout << "rearrangeCharacters: ";
    std::cout << Solution().rearrangeCharacters(s, t) << std::endl;
  }
  return 0;
}
