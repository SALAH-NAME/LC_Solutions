#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
private:
  int getMaxDigit(int num)
  {
    int max_d = 0;

    while (num > 0)
    {
      max_d = std::max(max_d, num % 10);
      num /= 10;
    }
    return max_d;
  }
public:
  int maxSum(std::vector<int>& nums)
  {
    std::vector<int> max_num(10, -1);
    int ans = -1;

    for (int num : nums)
    {
      int d = getMaxDigit(num);
      if (max_num[d] != -1)
      {
        ans = std::max(ans, num + max_num[d]);
      }
      max_num[d] = std::max(max_num[d], num);
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
    if ( i < v.size() - 1)
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
    {{112,131,411}},
    {{2536,1613,3366,162}},
    {{51,71,17,24,42}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmaxSum: " << Solution().maxSum(n) << std::endl;
  }
  return 0;
}
