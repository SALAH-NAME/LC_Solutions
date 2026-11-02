#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  long long maximumTripletValue(std::vector<int>& nums)
  {
    long long ans = 0;
    long long max_diff = 0;
    long long max_val = 0;

    for (int x : nums)
    {
      ans = std::max(ans, max_diff * x);
      max_diff = std::max(max_diff, max_val - x);
      max_val = std::max(max_val, (long long)x);
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
    {{12,6,1,2,7}},
    {{1,10,3,4,19}},
    {{1,2,3}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmaximumTripletValue: ";
    std::cout << Solution().maximumTripletValue(n) << std::endl;
  }
  return 0;
}
