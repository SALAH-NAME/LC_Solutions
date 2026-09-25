#include <vector>
#include <iostream>

class Solution
{
public:
  int findDelayedArrivalTime(int arrivalTime, int delayedTime)
  {
    return (arrivalTime + delayedTime) % 24;
  }
};

typedef struct testCase
{
  int a;
  int d;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {15, 5},
    {13, 11},
  };

  for (auto& [a, d] : tests)
  {
    std::cout << "---\narrivalTime: " << a << ", delayedTime: " << d;
    std::cout << "\nfindDelayedArrivalTime: ";
    std::cout << Solution().findDelayedArrivalTime(a, d) << std::endl;
  }
  return 0;
}
