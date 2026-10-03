#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string makeSmallestPalindrome(std::string s)
  {
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
      if (s[left] != s[right])
      {
        char smaller = std::min(s[left], s[right]);
        s[left] = smaller;
        s[right] = smaller;
      }
      left++;
      right--;
    }
    return s;
  }
};

void printS(const std::string& s)
{
  std::cout << "\"" << s << "\"";
}

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"egcfe"},
    {"abcd"},
    {"seven"},
  };

  for (auto& tc : tests)
  {
    std::cout << "---\ns: ";
    printS(tc.s);
    std::cout << "\nResult: ";
    printS(Solution().makeSmallestPalindrome(tc.s));
    std::cout << "\n";
  }
  return 0;
}
