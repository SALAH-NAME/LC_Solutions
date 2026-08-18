#include <vector>
#include <iostream>

class Solution
{
public:
  int averageValue(std::vector<int>& nums)
  {
    int sum = 0;
    int count = 0;

    for (int num : nums)
    {
      if (num % 6 == 0)
      {
        sum += num;
        count++;
      }
    }
    return count == 0 ? 0 : sum / count;
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
    {{1,3,6,10,12,15}},
    {{1,2,4,7,10}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\naverageValue: " << Solution().averageValue(n) << std::endl;
  }
  return 0;
}
