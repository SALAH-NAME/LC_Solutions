#include <vector>
#include <iostream>

class Solution
{
public:
  int countTestedDevices(std::vector<int>& batteryPercentages)
  {
    int count = 0;
    for (int battery : batteryPercentages)
    {
      if (battery - count > 0)
      {
        count++;
      }
    }
    return count;
  }
};

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

typedef struct testCase
{
  std::vector<int> b;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,1,2,1,3}},
    {{0,1,2}},
  };

  for (auto& [b] : tests)
  {
    std::cout << "---\nbatteryPercentages: ";
    printV(b);
    std::cout << "\ncountTestedDevices: ";
    std::cout << Solution().countTestedDevices(b) << std::endl;
  }
  return 0;
}
