#include <vector>
#include <iostream>

class Solution
{
public:
  bool hasTrailingZeros(std::vector<int>& nums)
  {
    int even_count = 0;
    for (int num : nums)
    {
      if ((num & 1) == 0)
      {
        if (++even_count >= 2)
        {
          return true;
        }
      }
    }
    return false;
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
    {{1,2,3,4,5}},
    {{2,4,8,16}},
    {{1,3,5,7,9}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nhasTrailingZeros: ";
    std::cout << (Solution().hasTrailingZeros(n) ? "True" : "False") << std::endl;
  }
  return 0;
}
