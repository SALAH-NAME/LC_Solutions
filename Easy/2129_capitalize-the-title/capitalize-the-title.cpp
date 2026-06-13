#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string capitalizeTitle(std::string title)
  {
    int n = title.length();
    int i = 0;

    while (i < n)
    {
      int start = i;
      while (i < n && title[i] != ' ')
      {
        title[i] = std::tolower(static_cast<unsigned char>(title[i]));
        i++;
      }
      int end = i;

      if (end - start > 2)
      {
        title[start] = std::toupper(static_cast<unsigned char>(title[start]));
      }
      i++;
    }
    return title;
  }
};

typedef struct testCase
{
  std::string t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"capiTalIze tHe titLe"},
    {"First leTTeR of EACH Word"},
    {"i lOve leetcode"},
  };

  for (auto& [t] : tests)
  {
    std::cout << "---\ntitle: '" << t << "\ncapitalizeTitle: '";
    std::cout << Solution().capitalizeTitle(t) << "'" << std::endl;
  }
  return 0;
}
