#include <vector>
#include <iostream>

class Solution
{
public:
  int passThePillow(int n, int time)
  {
    int cycle = 2 * (n - 1);
    int rem = time % cycle;

    if (rem < n)
    {
      return 1 + rem;
    }
    return n - (rem - (n - 1));
  }
};

typedef struct testCase
{
  int n;
  int t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {4, 5},
    {3, 2},
  };

  for (auto& [n, t] : tests)
  {
    std::cout << "---\nn: " << n << ", time: " << t << "\npassThePillow: ";
    std::cout << Solution().passThePillow(n, t) << std::endl;
  }
  return 0;
}
