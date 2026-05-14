#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minTimeToType(std::string word)
  {
    char pointer = 'a';
    int totalTime = 0;
    for (char c : word)
    {
      int diff = std::abs(c- pointer);
      int moveTime = std::min(diff, 26 - diff);
      totalTime += moveTime + 1;
      pointer = c;
    }
    return totalTime;
  }
};

typedef struct testCase
{
  std::string word;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abc"},
    {"bza"},
    {"zjpc"},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nword: '" << w << "'\nminTimeToType: ";
    std::cout << Solution().minTimeToType(w) << std::endl;
  }
  return 0;
}
