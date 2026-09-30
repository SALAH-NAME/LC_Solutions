#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countSeniors(std::vector<std::string>& details)
  {
    int count = 0;

    for (const std::string& detail : details)
    {
      int age = std::stoi(detail.substr(11, 2));
      if (age > 60)
      {
        count++;
      }
    }
    return count;
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

typedef struct testCase
{
  std::vector<std::string> d;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"7868190130M7522","5303914400F9211","9273338290F4010"}},
    {{"1313579440F2036","2921522980M5644"}},
  };

  for (auto& [d] : tests)
  {
    std::cout << "---\ndetails: ";
    printV(d);
    std::cout << "\ncountSeniors: " << Solution().countSeniors(d) << std::endl;
  }
  return 0;
}
