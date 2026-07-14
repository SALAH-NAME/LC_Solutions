#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int percentageLetter(std::string s, char letter)
  {
    int count = 0;

    for (char c : s)
    {
      if (c == letter)
      {
        count++;
      }
    }
    return (count * 100) / s.length();
  }
};

typedef struct testCase
{
  std::string s;
  char l;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"foobar", 'o'},
    {"jjjj", 'k'},
  };

  for (auto& [s, l] : tests)
  {
    std::cout << "---\ns: '" << s << "', letter: " << l << "\npercentageLetter: ";
    std::cout << Solution().percentageLetter(s, l) << std::endl;
  }
  return 0;
}
