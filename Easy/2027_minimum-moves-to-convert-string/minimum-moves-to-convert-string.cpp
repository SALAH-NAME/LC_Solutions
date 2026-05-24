#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int minimumMoves(std::string s)
  {
    int n = s.size();
    int moves = 0;
    int i = 0;

    while (i < n)
    {
      if (s[i] == 'X')
      {
        moves++;
        i += 3;
      }
      else
      {
        i++;
      }
    }
    return moves;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"XXX"},
    {"XXOX"},
    {"OOOO"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nminimumMoves: ";
    std::cout << Solution().minimumMoves(s) << std::endl;
  }
  return 0;
}
