#include <vector>
#include <iostream>

class Solution
{
public:
  int totalMoney(int n)
  {
    int weeks = n / 7;
    int days = n % 7;
    int total = 0;

    for (int w = 0; w < weeks; ++w)
      total += 7 * (w + 1) + 21;

    for (int d = 0; d < days; ++d)
      total += (weeks + 1) + d;

    return total;
  }
};

int main()
{
  std::vector<int> tests = {
    4, 10, 20,
  };

  for (auto& n : tests)
  {
    std::cout << "---\nn: " << n << "\ntotalMoney: ";
    std::cout << Solution().totalMoney(n) << std::endl;
  }
  return 0;
}
