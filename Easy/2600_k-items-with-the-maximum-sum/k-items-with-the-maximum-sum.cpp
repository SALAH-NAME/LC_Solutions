#include <vector>
#include <iostream>

class Solution
{
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
  {
    if (k <= numOnes)
    {
      return k;
    }
    if (k <= numOnes + numZeros)
    {
      return numOnes;
    }
    return numOnes - (k - numOnes - numZeros);
  }
};

typedef struct testCase
{
  int no;
  int nz;
  int nno;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {3, 2, 0, 2},
    {3, 2, 0, 4},
  };

  for (auto& [no, nz, nno, k] : tests)
  {
    std::cout << "---\nnumOnes: " << no << ", numZeros: " << nz;
    std::cout << "\nnumNegOnes: " << nno << ", k: " << k;
    std::cout << "\nkItemsWithMaximumSum: ";
    std::cout << Solution().kItemsWithMaximumSum(no, nz, nno, k) << std::endl;
  }
  return 0;
}
