#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions)
  {
    int max_diag_sq = 0;
    int max_area = 0;

    for (const auto& rect : dimensions)
    {
      int l = rect[0], w = rect[1];
      int diag_sq = l * l + w * w;
      int area = l * w;

      if (diag_sq > max_diag_sq)
      {
        max_diag_sq = diag_sq;
        max_area = area;
      }
      else if (diag_sq == max_diag_sq)
      {
        max_area = std::max(max_area, area);
      }
    }
    return max_area;
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

void printM(const std::vector<std::vector<int>>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> d;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{9,3},{8,6}}},
    {{{3,4},{4,3}}},
  };

  for (auto& [d] : tests)
  {
    std::cout << "---\ndimensions: ";
    printM(d);
    std::cout << "\nareaOfMaxDiagonal: " << Solution().areaOfMaxDiagonal(d);
    std::cout << std::endl;
  }
}
