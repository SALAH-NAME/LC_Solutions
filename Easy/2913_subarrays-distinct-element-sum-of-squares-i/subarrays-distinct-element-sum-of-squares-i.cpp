#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int sumCounts(std::vector<int>& nums)
  {
    int total_sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      std::unordered_set<int> distinct_elements;
      for (int j = i; j < n; j++)
      {
        distinct_elements.insert(nums[j]);
        int count = distinct_elements.size();
        total_sum += count * count;
      }
    }
    return total_sum;
  }
};

typedef struct testCase
{
  std::vector<int> n;
} testCase;

void printV(const std::vector<int> v)
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
  return 0;
}
