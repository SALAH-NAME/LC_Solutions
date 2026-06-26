#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::string> cellsInRange(std::string s)
  {
    std::vector<std::string> result;
    char start_col = s[0];
    char start_row = s[1];
    char end_col   = s[3];
    char end_row   = s[4];

    for (char col = start_col; col <= end_col; col++)
    {
      for (char row = start_row; row <= end_row; row++)
      {
        result.push_back({col, row});
      }
    }
    return result;
  }
};

void printV(const std::vector<std::string>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"K1:L2"},
    {"A1:F1"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\ns: '" << s << "'\ncellsInRangel: ";
    printV(Solution().cellsInRange(s));
    std::cout << std::endl;
  }
  return 0;
}
