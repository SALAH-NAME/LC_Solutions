#include <numeric>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findMiddleIndex(std::vector<int>& nums)
  {
    int left = 0;
    int right = 0;
    int total = std::accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
      right = total - left - nums[i];
      if (left == right)
        return i;

      left += nums[i];
    }
    return -1;
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
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{2,3,-1,8,4}},
    {{1,-1,4}},
    {{2,5}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nfindMiddleIndex: ";
    std::cout << Solution().findMiddleIndex(n) << std::endl;
  }
  return 0;
}
