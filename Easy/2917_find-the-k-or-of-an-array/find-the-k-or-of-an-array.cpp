#include <vector>
#include <iostream>

class Solution
{
public:
  int findKOr(std::vector<int>& nums, int k)
  {
    int ans = 0;
    for (int i = 0; i < 32; ++i)
    {
      int count = 0;
      for (int num : nums)
      {
        if ((num >> i) & 1)
        {
          count++;
        }
      }
      if (count >= k)
      {
        ans |= (1 << i);
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
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{7,12,9,8,9,15}, 4},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << ", k: " << k << "\nfindKOr: ";
    std::cout << Solution().findKOr(n, k) << std::endl;
  }
  return 0;
}
