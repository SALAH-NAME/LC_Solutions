#include <vector>
#include <iostream>

class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    return __builtin_popcount(start ^ goal);
  }
};

typedef struct testCase
{
  int s;
  int g;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {10, 7},
    {3, 7},
  };

  for (auto& [s, g] : tests)
  {
    std::cout << "---\nstart: " << s << ", goal: " << g << "\nminBitFlips: ";
    std::cout << Solution().minBitFlips(s, g) << std::endl;
  }
  return 0;
}
