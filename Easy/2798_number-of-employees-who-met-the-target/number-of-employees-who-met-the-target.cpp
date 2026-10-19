#include <vector>
#include <iostream>

class Solution
{
public:
  int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target)
  {
    int count = 0;
    for (int h : hours)
    {
      if (h >= target)
      {
        count++;
      }
    }
    return count;
  }
};

typedef struct testCase
{
  std::vector<int> h;
  int t;
} testCase;

void printV(const std::vector<int>& v)
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
    {{0,1,2,3,4}, 2},
    {{5,1,4,2,2}, 6},
  };

  for (auto& [h, t] : tests)
  {
    std::cout << "---\nhours: ";
    printV(h);
    std::cout << "\ntarget: " << Solution().numberOfEmployeesWhoMetTarget(h, t) << std::endl;
  }
  return 0;
}
