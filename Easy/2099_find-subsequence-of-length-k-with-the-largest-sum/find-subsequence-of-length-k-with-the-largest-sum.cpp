#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> maxSubsequence(std::vector<int>& nums, int k)
  {
    std::vector<std::pair<int, int>> nums_with_index;
    nums_with_index.reserve(nums.size());

    for (int i = 0; i < nums.size(); ++i)
      nums_with_index.push_back({nums[i], i});

    std::sort(nums_with_index.begin(), nums_with_index.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
        });
    nums_with_index.resize(k);
    std::sort(nums_with_index.begin(), nums_with_index.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });
    std::vector<int> result;
    result.reserve(k);
    for (const auto& p : nums_with_index)
      result.push_back(p.first);
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
    {{2,1,3,3}, 2},
    {{-1,-2,3,4}, 3},
    {{3,4,3,3}, 2},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\nmaxSubsequence: ";
    printV(Solution().maxSubsequence(n, k));
    std::cout << std::endl;
  }
  return 0;
}
