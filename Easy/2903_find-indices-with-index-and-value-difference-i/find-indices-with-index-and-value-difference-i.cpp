#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findIndices(std::vector<int>& nums, int indexDifference, int valueDifference)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (std::abs(i - j) >= indexDifference && std::abs(nums[i] - nums[j]) >= valueDifference)
        {
          return {i, j};
        }
      }
    }
    return {-1, -1};
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
  int i;
  int v;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{5,1,4,1}, 2, 4},
    {{2,1}, 0, 0},
    {{1,2,3}, 2, 4},
  };
  for (auto& [n, i, v] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nindexDifference: " << i << ", valueDifference: " << v;
    std::cout << "\nfindIndices: ";
    printV(Solution().findIndices(n, i, v));
    std::cout << std::endl;
  }
  return 0;
}
