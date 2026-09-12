#include <cstdlib>
#include <numeric>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> leftRightDifference(std::vector<int>& nums)
  {
    int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;
    std::vector<int> answer;
    answer.reserve(nums.size());

    for (int num : nums)
    {
      int right_sum = total_sum - left_sum - num;
      answer.push_back(std::abs(left_sum - right_sum));
      left_sum += num;
    }
    return answer;
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
    {{10,4,8,3}},
    {{1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nleftRightDifference: ";
    printV(n);
    std::cout << std::endl;
  }
  return 0;
}
