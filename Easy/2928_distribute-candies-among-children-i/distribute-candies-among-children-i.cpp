#include <vector>
#include <iostream>

class Solution
{
public:
  int distributeCandies(int n, int limit)
  {
    int count = 0;
    for (int i = 0; i <= limit; i++)
    {
      for (int j = 0; j <= limit; j++)
      {
        int k = n - i - j;
        if (k >= 0 && k <= limit)
        {
          count++;
        }
      }
    }
    return count;
  }
};

typedef struct testCase
{
  int n;
  int l;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {5, 2},
    {3, 3},
  };

  for (auto& [n, l] : tests)
  {
    std::cout << "---\nn: " << n << ", limit: " << l << "\ndistributeCandies: ";
    std::cout << Solution().distributeCandies(n, l) << std::endl;
  }
  return 0;
}
