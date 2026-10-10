#include <vector>
#include <iostream>

class Solution
{
public:
  int distanceTraveled(int mainTank, int additionalTank)
  {
    int distance = 0;
    while (mainTank > 0)
    {
      if (mainTank >= 5)
      {
        mainTank -= 5;
        distance += 50;
        if (additionalTank > 0)
        {
          mainTank += 1;
          additionalTank -= 1;
        }
      }
      else
      {
        distance += mainTank * 10;
        break ;
      }
    }
    return distance;
  }
};

typedef struct testCase
{
  int m;
  int a;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {5, 10},
    {1, 2},
  };

  for (auto& [m, a] : tests)
  {
    std::cout << "---\nmainTank: " << m << ",additionalTank: " << a;
    std::cout << "\ndistanceTraveled: " << Solution().distanceTraveled(m, a) << std::endl;
  }
  return 0;
}
