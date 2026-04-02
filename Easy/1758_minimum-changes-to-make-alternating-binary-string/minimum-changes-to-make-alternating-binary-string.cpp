#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minOperations(std::string s)
  {
    int n = s.size();
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
      char expected1 = (i % 2 == 0) ? '0' : '1';
      char expected2 = (i % 2 == 0) ? '1' : '0';

      if (s[i] != expected1) count1++;
      if (s[i] != expected2) count2++;
    }
    return std::min(count1, count2);
  }
};

int main()
{
  std::vector<std::string> tests = {
    "0100",
    "10",
    "1111",
  };

  for (auto& s : tests)
  {
    std::cout << "---\ns: '" << s << "'\nminOperations: \n";
    std::cout << Solution().minOperations(s) << std::endl;
  }
  return 0;
}
