#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int semiOrderedPermutation(std::vector<int>& nums)
  {
    int n = nums.size();

    int index1 = std::find(nums.begin(), nums.end(), 1) - nums.begin();
    int indexN = std::find(nums.begin(), nums.end(), n) - nums.begin();

    int swaps = index1 + (n - 1 - indexN);

    if (index1 > indexN)
    {
      swaps -= 1;
    }
    return swaps;
  }
};

typedef struct testCase
{
  std::vector<int> n;
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

int main()
{
  std::vector<testCase> tests = {
    {{2,1,4,3}},
    {{2,4,1,3}},
    {{1,3,4,2,5}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nsemiOrderedPermutation: ";
    std::cout << Solution().semiOrderedPermutation(n) << std::endl;
  }
  return 0;
}
