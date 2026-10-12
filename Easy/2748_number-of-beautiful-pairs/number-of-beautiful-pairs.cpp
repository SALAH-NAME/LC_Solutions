#include <numeric>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countBeautifulPairs(std::vector<int>& nums)
  {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
      int first_digit = std::stoi(std::to_string(nums[i]).substr(0, 1));
      for (int j = i + 1; j < n; j++)
      {
        int last_digit = nums[j] % 10;
        if (std::gcd(first_digit, last_digit) == 1)
        {
          count++;
        }
      }
    }
    return count;
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
    {{2,5,1,4}},
    {{11,21,12}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ncountBeautifulPairs: ";
    std::cout << Solution().countBeautifulPairs(n) << std::endl;
  }
  return 0;
}
