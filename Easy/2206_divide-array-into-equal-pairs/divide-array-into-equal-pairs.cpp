#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool divideArray(std::vector<int>& nums)
  {
    std::unordered_map<int, int> freq;

    for (int n : nums)
      freq[n]++;

    for (auto& c : freq)
    {
      if (c.second % 2 != 0)
        return false;
    }
    return true;
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
    {{3,2,3,2,2,2}},
    {{1,2,3,4}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ndivideArray: ";
    std::cout << (Solution().divideArray(n) ? "True" : "False") << std::endl;
  }
  return 0;
}
