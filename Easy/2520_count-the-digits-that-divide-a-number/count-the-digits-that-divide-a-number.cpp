#include <vector>
#include <iostream>

class Solution
{
public:
  int countDigits(int num)
  {
    int count = 0;
    int temp = num;
    
    while (temp > 0)
    {
      int digit = temp % 10;
      if (digit != 0 && num % digit == 0)
      {
        count++;
      }
      temp /= 10;
    }
    return count;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {7},
    {121},
    {1248},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\ncountDigits: ";
    std::cout << Solution().countDigits(n) << std::endl;
  }
  return 0;
}
