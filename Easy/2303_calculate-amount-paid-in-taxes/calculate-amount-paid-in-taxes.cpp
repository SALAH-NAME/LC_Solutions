#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  double calculateTax(std::vector<std::vector<int>>& brackets, int income)
  {
    double tax = 0;
    int prev = 0;

    for (std::vector<int>& b : brackets)
    {
      int upper = b[0];
      int percent = b[1];

      if (income <= prev)
      {
        break;
      }
      int taxable_income = std::min(income, upper) - prev;
      tax += taxable_income * (percent / 100.0);

      prev = upper;
    }
    return tax;
  }
};

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

void printMat(const std::vector<std::vector<int>>& m)
{
  std::cout << "{";
  for (int i = 0; i < m.size(); i++)
  {
    printV(m[i]);
    if (i < m.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> b;
  int i;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{3,50},{7,10},{12,25}}, 10},
    {{{1,0},{4,25},{5,50}}, 2},
    {{{2,50}}, 0},
  };
  
  for (auto& [b, i] : tests)
  {
    std::cout << "---\nbrackets: ";
    printMat(b);
    std::cout << ", income: " << i << "\ncalculateTax: ";
    std::cout << Solution().calculateTax(b, i) << std::endl;
  }
  return 0;
}
