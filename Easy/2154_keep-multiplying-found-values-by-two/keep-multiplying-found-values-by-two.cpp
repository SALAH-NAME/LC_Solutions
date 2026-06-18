#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int findFinalValue(std::vector<int>& nums, int original)
  {
    std::unordered_set<int> num_set(nums.begin(), nums.end());

    while (num_set.count(original))
    {
      original *= 2;
    }
    return original;
  }
};

typedef struct testCase
{
  std::vector<int> n;
  int o;
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
    {{5,3,6,1,12}, 3},
    {{2,7,9}, 4},
  };

  for (auto& [n, o] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", original: " << o << "\nfindFinalValue: ";
    std::cout << Solution().findFinalValue(n, o) << std::endl;
  }
  return 0;
}
