#include <vector>
#include <iostream>

class Solution
{
public:
  int countPairs(std::vector<int>& nums, int k)
  {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] == nums[j] && (i * j) % k == 0)
        {
          count++;
        }
      }
    }
    return count;
  }
};

typedef struct testCase
{
  std::vector<int> n;
  int k;
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
    {{3,1,2,2,2,1,3}, 2},
    {{1,2,3,4}, 1},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\ncountPairs: ";
    std::cout << Solution().countPairs(n, k) << std::endl;
  }
  return 0;
}
