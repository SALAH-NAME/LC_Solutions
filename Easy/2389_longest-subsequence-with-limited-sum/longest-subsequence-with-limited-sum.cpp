#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

class Solution
{
public:
  std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries)
  {
    std::sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); i++)
    {
      nums[i] += nums[i - 1];
    }

    std::vector<int> ans;
    for (int q : queries)
    {
      auto it = std::upper_bound(nums.begin(), nums.end(), q);
      ans.push_back(std::distance(nums.begin(), it));
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
  std::vector<int> q;
} testCase;


int main()
{
  std::vector<testCase> tests = {
    {{4, 5, 2, 1}, {3, 10, 21}},
    {{2, 3, 4, 5}, {1}},
  };

  for(auto& [n, q] : tests)
  {
    std::vector<int> res = Solution().answerQueries(n, q);
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nqueries: ";
    printV(q);
    std::cout << "\nanswer: ";
    printV(res);
    std::cout << std::endl;
  }
  return 0;
}
