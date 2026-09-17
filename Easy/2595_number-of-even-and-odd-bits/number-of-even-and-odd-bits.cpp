#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> evenOddBit(int n)
  {
    int even_count = 0;
    int odd_count = 0;
    int i = 0;

    while (n > 0)
    {
      if (n & 1)
      {
        if (i % 2 == 0)
        {
          even_count++;
        }
        else
        {
          odd_count++;
        }
      }
      n >>= 1;
      i++;
    }
    return {even_count, odd_count};
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
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {50},
    {2},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nn: " << n << "\nevenOddBit: ";
    printV(Solution().evenOddBit(n));
    std::cout << std::endl;
  }
  return 0;
}
