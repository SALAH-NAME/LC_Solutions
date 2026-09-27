#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maximizeSum(std::vector<int>& nums, int k)
  {
    int x = *std::max_element(nums.begin(), nums.end());
    return x * k + k * (k - 1) / 2;
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

typedef struct testCase
{
  std::vector<int> n;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,3,4,5}, 3},
    {{5,5,5}, 2},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nk: " << k << "\nmaximizeSum: ";
    std::cout << Solution().maximizeSum(n, k) << std::endl;
  }
  return 0;
}
