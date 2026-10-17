#include <vector>
#include <iostream>

class Solution
{
public:
  bool isGood(std::vector<int>& nums)
  {
    int n = nums.size() - 1;

    std::vector<int> count(n + 1, 0);
    for (int num : nums)
    {
      if (num > n || num < 1) return false;
      count[num]++;
    }
    if (count[n] != 2) return false;
    for (int i = 1; i < n; i++)
    {
      if (count[i] != 1) return false;
    }
    return true;
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
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{2, 1, 3}},
    {{1, 3, 3, 2}},
    {{1, 1}},
    {{3, 4, 4, 1, 2, 1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nisGood: " << (Solution().isGood(n) ? "True" : "False");
    std::cout << std::endl;
  }
  return 0;
}
