#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  bool haveConflict(std::vector<std::string>& event1, std::vector<std::string>& event2)
  {
    return event1[0] <= event2[1] && event2[0] <= event1[1];
  }
};

typedef struct testCase
{
  std::vector<std::string> e1;
  std::vector<std::string> e2;
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
    {{"01:15","02:00"}, {"02:00","03:00"}},
    {{"01:00","02:00"}, {"01:20","03:00"}},
    {{"10:00","11:00"}, {"14:00","15:00"}},
  };

  for (auto& [e1, e2] : tests)
  {
    std::cout << "---\nevent1: ";
    printV(e1);
    std::cout << "\nevent2: ";
    printV(e2);
    std::cout << "\nhaveConflict: ";
    std::cout << (Solution().haveConflict(e1, e2) ? "True" : "False") << std::endl;
  }
  return 0;
}
