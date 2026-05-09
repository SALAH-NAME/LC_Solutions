#include <cmath>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool isThree(int n)
  {
    if (n < 4) return false;

    int root = std::round(std::sqrt(n));
    if (root * root != n) return false;
    return isPrime(root);
  }
private:
  bool isPrime(int num)
  {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i)
    {
      if (num % i == 0) return false;
    }
    return true;
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {2},
    {4},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nisThree: ";
    std::cout << (Solution().isThree(n) ? "True" : "False") << std::endl;
  }
  return 0;
}
