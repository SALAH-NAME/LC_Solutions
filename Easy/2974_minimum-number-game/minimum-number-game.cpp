#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> numberGame(std::vector<int>& nums)
  {
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < static_cast<int>(nums.size()); i += 2)
    {
      std::swap(nums[i], nums[i + 1]);
    }
    return nums;
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
    {{5,4,2,3}},
    {{2,5}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nnumberGame: ";
    printV(Solution().numberGame(n));
    std::cout << std::endl;
  }
  return 0;
}
