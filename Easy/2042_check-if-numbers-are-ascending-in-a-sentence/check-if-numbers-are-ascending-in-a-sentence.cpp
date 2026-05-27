#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool areNumbersAscending(std::string s)
  {
    int last_number = 0;
    std::istringstream iss(s);
    std::string word;
    while (iss >> word)
    {
      int n = std::atoi(word.c_str());
      if (n > 0)
      {
        if (n > last_number)
        {
          last_number = n;
        }
        else
        {
          return false;
        }
      }
    }
    return true;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;


int main()
{
  std::vector<testCase> tests = {
    {"1 box has 3 blue 4 red 6 green and 12 yellow marbles"},
    {"hello world 5 x 5"},
    {"sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\nareNumbersAscending: ";
    std::cout << (Solution().areNumbersAscending(s) ? "True" : "False") << std::endl;
  }
  return 0;
}
