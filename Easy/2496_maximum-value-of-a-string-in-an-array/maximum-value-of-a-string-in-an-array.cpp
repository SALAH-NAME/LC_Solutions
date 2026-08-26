#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int maximumValue(std::vector<std::string>& strs)
  {
    int max_val = 0;
    for (const std::string& s : strs)
    {
      bool is_numeric = std::all_of(s.begin(), s.end(), [](unsigned char c) {
          return std::isdigit(c);
      });

      int val = is_numeric ? std::stoi(s) : s.length();
      max_val = std::max(max_val, val);
    }
    return max_val;
  }
};

typedef struct testCase
{
  std::vector<std::string> s;
} testCase;

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

int main()
{
  std::vector<testCase> tests = {
    {{"alic3","bob","3","4","00000"}},
    {{"1","01","001","0001"}},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\nstrs: ";
    printV(s);
    std::cout << "\nmaximumValue: " << Solution().maximumValue(s) << std::endl;
  }
  return 0;
}
