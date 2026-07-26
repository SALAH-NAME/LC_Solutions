#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> numberOfPairs(std::vector<int>& nums)
  {
    std::vector<int> count(101, 0);
    for (int num : nums)
    {
      count[num]++;
    }

    int pairs = 0;
    int leftovers = 0;
    for (int c : count)
    {
      pairs += c / 2;
      leftovers += c % 2;
    }
    return {pairs, leftovers};
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
    {{1,3,2,1,3,2,2}},
    {{1,1}},
    {{0}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::vector<int> result = Solution().numberOfPairs(n);
    std::cout << "\nnumberOfPairs: ";
    printV(result);
    std::cout << std::endl;
  }
  return 0;
}
