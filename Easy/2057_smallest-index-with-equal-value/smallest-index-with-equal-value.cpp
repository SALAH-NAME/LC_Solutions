#include <vector>
#include <iostream>

class Solution
{
public:
  int smallestEqual(std::vector<int>& nums)
  {
    for (int i = 0; i < nums.size(); ++i)
    {
      if (i % 10 == nums[i])
        return i;
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
    {{0,1,2}},
    {{4,3,2,1}},
    {{1,2,3,4,5,6,7,8,9,0}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nsmallestEqual: ";
    std::cout << Solution().smallestEqual(n) << std::endl;
  }
  return 0;
}
