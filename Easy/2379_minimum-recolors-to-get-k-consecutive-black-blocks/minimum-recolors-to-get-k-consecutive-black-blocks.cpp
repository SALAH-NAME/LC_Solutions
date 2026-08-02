#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minimumRecolors(std::string blocks, int k)
  {
    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
      if (blocks[i] == 'W') cnt++;
    }

    int ans = cnt;

    for (int i = k; i < blocks.length(); i++)
    {
      if (blocks[i] == 'W') cnt++;
      if (blocks[i - k] == 'W') cnt--;

      ans = std::min(ans, cnt);
    }
    return ans;
  }
};

typedef struct testCase
{
  std::string b;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"WBBWWBBWBW", 7},
    {"WBWBBBW", 2},
  };

  for (auto& [b, k] : tests)
  {
    std::cout << "---\nblocks: " << b << ", k: " << k << "\nminimumRecolors: ";
    std::cout << Solution().minimumRecolors(b, k) << std::endl;
  }
  return 0;
}
