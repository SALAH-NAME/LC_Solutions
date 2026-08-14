#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countTime(std::string time)
  {
    int ans = 1;
    if (time[3] == '?') ans *= 6;
    if (time[4] == '?') ans *= 10;

    if (time[0] == '?' && time[1] == '?')
    {
      ans *= 24;
    }
    else if (time[0] == '?')
    {
      ans *= (time[1] < '4' ? 3 : 2);
    }
    else if (time[1] == '?')
    {
      ans *= (time[0] == '2' ? 4 : 10);
    }
    return ans;
  }
};

typedef struct testCase
{
  std::string t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"?5:00"},
    {"0?:0?"},
    {"??:??"},
  };

  for (auto& [t] : tests)
  {
    std::cout << "---\ntime: " << t << "\ncountTime: ";
    std::cout << Solution().countTime(t) << std::endl;
  }
  return 0;
}
