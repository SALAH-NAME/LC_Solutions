#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countSymmetricIntegers(int low, int high)
  {
    int count = 0;
    for (int x = low; x <= high; x++)
    {
      std::string s = std::to_string(x);
      int n = s.length();

      if (n % 2 != 0) continue;

      int mid = n / 2;
      int leftSum = 0, rightSum = 0;

      for (int i = 0; i < mid; i++)
      {
        leftSum += s[i] - '0';
        rightSum += s[i + mid] - '0';
      }

      if (leftSum == rightSum)
      {
        count++;
      }
    }
    return count;
  }
};

typedef struct testCase
{
  int l;
  int h;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {1, 100},
    {1200, 1230},
  };

  for (auto& [l, h] : tests)
  {
    std::cout << "---\nlow: " << l << ", high: " << h << "\ncountSymmetricIntegers: ";
    std::cout << Solution().countSymmetricIntegers(l, h) << std::endl;
  }
  return 0;
}
