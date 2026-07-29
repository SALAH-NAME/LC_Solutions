#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minimumOperations(std::vector<int>& nums)
  {
    std::unordered_set<int> unique_elements;

    for (int num : nums)
    {
      if (num > 0)
      {
        unique_elements.insert(num);
      }
    }
    return unique_elements.size();
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
    {{1,5,0,3,5}},
    {{0}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nminimumOperations: ";
    std::cout << Solution().minimumOperations(n) << std::endl;
  }
  return 0;
}
