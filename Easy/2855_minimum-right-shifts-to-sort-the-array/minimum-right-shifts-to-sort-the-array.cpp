#include <vector>
#include <iostream>

class Solution
{
public:
  int minimumRightShifts(std::vector<int>& nums)
  {
    int count = 0;
    int pivot = -1;
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] > nums[i + 1])
      {
        count++;
        pivot = i;
      }
    }

    if (count == 0)
    {
      return 0;
    }

    if (count > 1 || nums[n - 1] > nums[0])
    {
      return -1;
    }
    return n - 1 - pivot;
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
    {{3,4,5,1,2}},
    {{1,3,5}},
    {{2,1,4}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nminimumRightShifts: ";
    std::cout << Solution().minimumRightShifts(n) << std::endl;
  }
  return 0;
}
