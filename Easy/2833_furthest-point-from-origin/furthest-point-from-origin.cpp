#include <string>
#include <vector>
#include <iostream>
#include <cmath>

class Solution
{
public:
  int furthestDistanceFromOrigin(std::string moves)
  {
    int countL = 0;
    int countR = 0;
    int countUnderline = 0;

    for (char c : moves)
    {
      if (c == 'L')
      {
        countL++;
      }
      else if (c == 'R')
      {
        countR++;
      }
      else
      {
        countUnderline++;
      }
    }

    return std::abs(countL - countR) + countUnderline;
  }
};

typedef struct testCase
{
  std::string moves;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"L_RL__R"},
    {"_R__LL_"},
    {"_______"}
  };

  for (auto& tc : tests)
  {
    std::cout << "---\nmoves: " << tc.moves;
    std::cout << "\nfurthestDistanceFromOrigin: ";
    std::cout << Solution().furthestDistanceFromOrigin(tc.moves) << std::endl;
  }
  return 0;
}
