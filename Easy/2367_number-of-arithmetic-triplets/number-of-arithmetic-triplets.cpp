#include <features.h>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int arithmeticTriplets(std::vector<int>& nums, int diff)
  {
    std::unordered_set<int> vis(nums.begin(), nums.end());
    int answer = 0;

    for (int x : nums)
    {
      if (vis.count(x + diff) && vis.count(x + 2 * diff))
      {
        answer++;
      }
    }

    return answer;
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
  int d;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{0,1,4,6,7,10}, 3},
    {{4,5,6,7,8,9}, 2},
  };

  for (auto& [n, d] : tests)
  {
    std::cout << "---\nnums:";
    printV(n);
    std::cout << ", diff: " << d << "\narithmeticTriplets: ";
    std::cout << Solution().arithmeticTriplets(n, d) << std::endl;
  }
  return 0;
}
