#include <utility>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> applyOperations(std::vector<int>& nums)
  {
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      if (i + 1 < n && nums[i] == nums[i + 1])
      {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }

      if (nums[i] != 0)
      {
        std::swap(nums[i], nums[j]);
        j++;
      }
    }
    return nums;
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
    {{1,2,2,1,1,0}},
    {{0,1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\napplyOperations: ";
    printV(Solution().applyOperations(n));
    std::cout << std::endl;
  }
  return 0;
}
