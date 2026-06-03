#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maxDistance(std::vector<int>& colors)
  {
    int n = colors.size();
    int max_dist = 0;

    for (int i = n - 1; i >= 0; --i)
    {
      if (colors[i] != colors[0])
      {
        max_dist = std::max(max_dist, i);
        break;
      }
    }

    for (int i = 0; i < n; ++i)
    {
      if (colors[i] != colors[n - 1])
      {
        max_dist = std::max(max_dist, (n - 1) - i);
        break;
      }
    }
    return max_dist;
  }
};

typedef struct testCase
{
  std::vector<int> c;
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
    {{1,1,1,6,1,1,1}},
    {{1,8,3,8,3}},
    {{0,1}},
  };

  for (auto& [c] : tests)
  {
    std::cout << "---\ncolors: ";
    printV(c);
    std::cout << "\nmaxDistance: ";
    std::cout << Solution().maxDistance(c) << std::endl;
  }
  return 0;
}
