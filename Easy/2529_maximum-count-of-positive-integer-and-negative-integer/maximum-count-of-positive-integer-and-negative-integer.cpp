#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maximumCount(std::vector<int>& nums)
  {
    int p_max = 0;
    int n_max = 0;

    for (int n : nums)
    {
      if (n > 0)
        p_max++;
      else if (n < 0)
        n_max++;
    }
    return std::max(p_max, n_max);
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
    {{-2,-1,-1,1,2,3}},
    {{-3,-2,-1,0,0,1,2}},
    {{5,20,66,1314}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmaximumCount: " << Solution().maximumCount(n) << std::endl;
  }
}
