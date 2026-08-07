#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  int mostFrequentEven(std::vector<int>& nums)
  {
    std::unordered_map<int, int> freq;

    for (int n : nums)
    {
      if (n % 2 == 0) freq[n]++;
    }

    int ans = -1;
    int max_freq = 0;
    for (const auto& [val, count] : freq)
    {
      if (count > max_freq || (count == max_freq && (ans == -1 || val < ans)))
      {
        max_freq = count;
        ans = val;
      }
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
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{0,1,2,2,4,4,1}},
    {{4,4,4,9,2,4}},
    {{29,47,21,41,13,37,25,7}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nmostFrequentEven: ";
    std::cout << Solution().mostFrequentEven(n) << std::endl;
  }
  return 0;
}
