#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int captureForts(std::vector<int>& forts)
  {
    int ans = 0;
    for (int i = 0, j = 0; i < forts.size(); i++)
    {
      if (forts[i] != 0)
      {
        if (forts[i] == -forts[j])
        {
          ans = std::max(ans, i - j - 1);
        }
        j = i;
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
  std::vector<int> f;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,0,0,-1,0,0,0,0,1}},
    {{0,0,1,-1}},
  };

  for (auto& [f] : tests)
  {
    std::cout << "---\nforts: ";
    printV(f);
    std::cout << "\ncaptureForts: " << Solution().captureForts(f) << std::endl;
  }
  return 0;
}
