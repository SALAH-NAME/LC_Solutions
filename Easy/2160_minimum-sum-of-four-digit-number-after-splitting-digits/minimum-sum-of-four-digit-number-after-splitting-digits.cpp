#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minimumSum(int num)
  {
    std::vector<int> digits;
    digits.reserve(4);

    while (num > 0)
    {
      digits.push_back(num % 10);
      num /= 10;
    }
    std::sort(digits.begin(), digits.end());
    return 10 * (digits[0] + digits[1]) + digits[2] + digits[3];
  }
};

typedef struct testCase
{
  int s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {2932},
    {4009},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnum: " << n << "\nminimumSum: ";
    std::cout << Solution().minimumSum(n) << std::endl;
  }
  return 0;
}
