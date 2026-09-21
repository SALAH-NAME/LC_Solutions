#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

class Solution
{
private:
  bool isPrime(int n)
  {
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); i++)
    {
      if (n % i == 0) return false;
    }
    return true;
  }
public:
  int diagonalPrime(std::vector<std::vector<int>>& nums)
  {
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
      int val1 = nums[i][i];
      if (isPrime(val1))
      {
        ans = std::max(ans, val1);
      }

      int val2 = nums[i][n - i - 1];
      if (isPrime(val2))
      {
        ans = std::max(ans, val2);
      }
    }
    return ans;
  }
};

typedef struct testCase
{
  std::vector<std::vector<int>> n;
} testCase;

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

void printM(const std::vector<std::vector<int>>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

int main()
{
  std::vector<testCase> tests = {
    {{{1,2,3},{5,6,7},{9,10,11}}},
    {{{1,2,3},{5,17,7},{9,11,10}}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printM(n);
    std::cout << "\ndiagonalPrime: " << Solution().diagonalPrime(n) << std::endl;
  }
  return 0;
}
