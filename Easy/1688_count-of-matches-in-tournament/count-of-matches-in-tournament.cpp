#include <vector>
#include <iostream>

class Solution
{
public:
  int numberOfMatches(int n)
  {
    return n - 1;
  }
};

int main()
{
  std::vector<int> tests = {
    7, 14
  };

  for (int n : tests)
  {
    std::cout << "---\nn: " << n << "\nnumberOfMatches: ";
    std::cout << Solution().numberOfMatches(n) << std::endl;
  }
  return 0;
}
