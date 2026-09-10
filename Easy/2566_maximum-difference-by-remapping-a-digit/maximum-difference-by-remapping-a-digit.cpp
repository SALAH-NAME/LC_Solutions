#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minMaxDifference(int num)
  {
    std::string s_max = std::to_string(num);
    std::string s_min = s_max;

    char target_max = ' ';
    for (char c : s_max)
    {
      if (c != '9')
      {
        target_max = c;
        break;
      }
    }

    if (target_max != ' ')
    {
      for (char &c : s_max)
      {
        if (c == target_max) c = '9';
      }
    }

    char target_min = s_min[0];
    for (char &c : s_min)
    {
      if (c == target_min) c = '0';
    }
    return std::stoi(s_max) - std::stoi(s_min);
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {11891},
    {90},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\nminMaxDifference: ";
    std::cout << Solution().minMaxDifference(n) << std::endl;
  }
  return 0;
}
