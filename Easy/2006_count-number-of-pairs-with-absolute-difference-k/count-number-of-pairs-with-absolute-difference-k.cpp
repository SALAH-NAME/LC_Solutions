#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countKDifference(std::vector<int>& nums, int k)
  {
    int freq[101] = {0};
    int count = 0;

    for (int num : nums)
    {
      freq[num]++;
    }
    for (int i = 1; i <= 100 - k; ++i)
    {
      count += freq[i] * freq[i + k];
    }
    return count;
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
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,2,1}, 1},
    {{1,3}, 3},
    {{3,2,1,5,4}, 2},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\ncountKDifference: ";
    std::cout << Solution().countKDifference(n, k) << std::endl;
  }
  return 0;
}
