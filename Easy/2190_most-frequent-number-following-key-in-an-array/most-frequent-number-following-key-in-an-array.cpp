#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  int mostFrequent(std::vector<int>& nums, int key)
  { 
    std::unordered_map<int, int> counts;
    int max_count = 0;
    int result = -1;


    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] == key)
      {
        int target = nums[i + 1];
        counts[target]++;

        if (counts[target] > max_count)
        {
          max_count = counts[target];
          result = target;
        }
      }
    }
    return result;
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
    {{1,100,200,1,100}, 1},
    {{2,2,2,2,3}, 2}
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\nmostFrequent: ";
    std::cout << Solution().mostFrequent(n, k) << std::endl;
  }
  return 0;
}
