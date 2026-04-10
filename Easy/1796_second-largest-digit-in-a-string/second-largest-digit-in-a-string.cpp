#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <climits>

class Solution
{
public:
  int secondHighest(std::string s)
  {
    int first = -1;
    int second = -1;

    for (char c : s)
    {
      if (std::isdigit(c))
      {
        int d = c - '0';
        if (d > first)
        {
          second = first;
          first = d;
        }
        else if (d < first && d > second)
        {
          second = d;
        }
      }
    }
    return second;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"dfa12321afd"},
    {"abc1111"},
    {"ckcz9"},
    {"xyz"}
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\nstring: '" << s << "'\n";
    std::cout << "secondHighest: ";
    std::cout << Solution().secondHighest(s) << std::endl;
  }

  return 0;
}
