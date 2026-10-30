#include <vector>
#include <iostream>
#include <bit>

class Solution
{
public:
  int sumIndicesWithKSetBits(std::vector<int>& nums, int k)
  {
    int ans = 0;
    for (unsigned i = 0; i < nums.size(); i++)
    {
      if (std::__popcount(i) == k)
      {
        ans += nums[i];
      }
    }
    return ans;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if ( i < v.size() - 1 )
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
    {{5,10,1,5,2}, 1},
    {{4,3,2,1}, 2},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\nsumIndicesWithKSetBits: ";
    std::cout << Solution().sumIndicesWithKSetBits(n, k) << std::endl;
  }
  return 0;
}
