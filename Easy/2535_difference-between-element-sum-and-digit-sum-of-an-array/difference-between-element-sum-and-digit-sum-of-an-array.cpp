#include <vector>
#include <iostream>

class Solution
{
public:
  int differenceOfSum(std::vector<int>& nums)
  {
    int element_sum = 0;
    int digit_sum = 0;

    for (int num : nums)
    {
      element_sum += num;

      int temp = num;
      while (temp > 0)
      {
        digit_sum += temp % 10;
        temp /= 10;
      }
    }
    return element_sum - digit_sum;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - i)
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
    {{1,15,6,3}},
    {{1,2,3,4}},
  };

  for (auto [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ndifferenceOfSum: " << Solution().differenceOfSum(n) << std::endl;
  }
  return 0;
}
