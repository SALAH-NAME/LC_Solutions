#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string maximumTime(std::string time)
  {
    if (time[0] == '?')
    {
      if (time[1] == '?' || time[1] <= '3')
        time[0] = '2';
      else
        time[0] = '1';
    }
    if (time[1] == '?')
    {
      if (time[0] == '2')
        time[1] = '3';
      else
        time[1] = '9';
    }

    if (time[3] == '?')
      time[3] = '5';
    if (time[4] == '?')
      time[4] = '9';

    return time;
  }
};

int main()
{
  std::vector<std::string> tests = {
    "2?:?0",
    "0?:3?",
    "1?:22",
  };

  for (auto& t : tests)
  {
    std::cout << "---\ntime: '" << t << "'\nmaximumTime: '";
    std::cout << Solution().maximumTime(t) << "'" << std::endl;
  }
  return 0;
}
