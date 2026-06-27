#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k)
  {
    std::vector<int> result;
    int n = nums.size();
    int last_visited = -1;


    for (int j = 0; j < n; j++)
    {
      if (nums[j] == key)
      {
        int start = std::max(0, j - k);
        int end = std::min(n - 1, j + k);

        for (int i = std::max(start, last_visited + 1); i <= end; i++)
        {
          result.push_back(i);
        }
        last_visited = end;
      }
    }
    return result;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size())
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<int> n;
  int ke;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{3,4,9,1,3,9,5}, 9, 1},
    {{2,2,2,2,2}, 2, 2},
  };

  for (auto& [n, ke, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", key: " << ke << ", k: " << k << "\nfindKDistantIndices: ";
    printV(Solution().findKDistantIndices(n, ke, k));
    std::cout << std::endl;
  }
  return 0;
}
