#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minLength(std::string s)
  {
    std::string stack = "";
    for (char c : s)
    {
      if (!stack.empty() && 
          ((stack.back() == 'A' && c == 'B') || 
           (stack.back() == 'C' && c == 'D')))
      {
        stack.pop_back();
      }
      else
      {
        stack.push_back(c);
      }
    }
    return stack.length();
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
    {"ABFCACDB"},
    {"ACBBD"},
  };

  for (auto& tc : tests)
  {
    std::cout << "---\ns: ";
    printS(tc.s);
    std::cout << "\nminLength: " << Solution().minLength(tc.s) << "\n";
  }
  return 0;
}
