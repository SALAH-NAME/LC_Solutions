#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maxFrequencyElements(std::vector<int>& nums)
  {
    std::unordered_map<int, int> freq;
    int max_freq = 0;
    int total = 0;

    for (int num : nums)
    {
      int count = ++freq[num];

      if (count > max_freq)
      {
        max_freq = count;
        total = count;
      }
      else if (count == max_freq)
      {
        total += count;
      }
    }
    return total;
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
    {{1,2,2,3,1,4}},
    {{1,2,3,4,5}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmaxFrequencyElements: ";
    std::cout << Solution().maxFrequencyElements(n) << std::endl;
  }
  return 0;
}
