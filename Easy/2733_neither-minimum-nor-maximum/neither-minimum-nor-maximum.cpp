#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findNonMinOrMax(std::vector<int>& nums)
  {
    if (nums.size() < 3) return -1;

    std::vector<int> temp = {nums[0], nums[1], nums[2]};
    std::sort(temp.begin(), temp.end());
    return temp[1];
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
    {{3,2,1,4}},
    {{1,2}},
    {{2,1,3}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nfindNonMinOrMax: " << Solution().findNonMinOrMax(n) << std::endl;
  }
  return 0;
}
