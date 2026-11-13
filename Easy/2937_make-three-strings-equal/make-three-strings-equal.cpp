#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findMinimumOperations(std::string s1, std::string s2, std::string s3)
  {
    int minLength = std::min({s1.length(), s2.length(), s3.length()});
    int i = 0;

    while (i < minLength && s1[i] == s2[i] && s2[i] == s3[i])
    {
      i++;
    }
    if (i == 0) return -1;
    return s1.length() + s2.length() + s3.length() - 3 * i;
  }
};

typedef struct testCase
{
  std::string s1;
  std::string s2;
  std::string s3;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abc", "abb", "ab"},
    {"dac", "bac", "cac"},
  };

  for (auto& [s1, s2, s3] : tests)
  {
    std::cout << "---\ns1: '" << s1 << "',s2: '" << s2 << "',s3: " << s3 << "'";
    std::cout << "\nfindMinimumOperations: ";
    std::cout << Solution().findMinimumOperations(s1, s2, s3) << std::endl;
  }
  return 0;
}
