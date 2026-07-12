#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int divisorSubstrings(int num, int k)
  {
    std::string num_str = std::to_string(num);
    int k_bequty = 0;
    int n = num_str.length();

    for (int i = 0; i <= n - k; i++)
    {
      std::string sub_str = num_str.substr(i, k);

      int val = std::stoi(sub_str);
      if (val != 0 && num % val == 0)
      {
        k_bequty++;
      }
    }
    return k_bequty;
  }
};

typedef struct testCase
{
  int n;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {240, 2},
    {430043, 2},
  };

  for (auto [n, k] : tests)
  {
    std::cout << "---\nnum: " << n << ", k: " << k << "\ndivisorSubstrings: ";
    std::cout << Solution().divisorSubstrings(n, k) << std::endl;
  }
  return 0;
}
