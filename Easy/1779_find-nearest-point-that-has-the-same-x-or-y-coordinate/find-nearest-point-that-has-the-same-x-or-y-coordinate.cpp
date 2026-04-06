#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

class Solution
{
public:
  int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points)
  {
    int bestIndex = -1;
    int bestDist = INT_MAX;

    for (int i = 0; i < points.size(); ++i)
    {
      int px = points[i][0];
      int py = points[i][1];

      if (px == x || py == y)
      {
        int dist = std::abs(px - x) + std::abs(py - y);
        if (dist < bestDist)
        {
          bestDist = dist;
          bestIndex = i;
        }
      }
    }
    return bestIndex;
  }
};

typedef struct testCase
{
  int x;
  int y;
  std::vector<std::vector<int>> points;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {3, 4, {{1,2},{3,1},{2,4},{2,3},{4,4}}},
    {3, 4, {{3,4}}},
    {3, 4, {{2,3}}}
  };

  for (auto& [x, y, points] : tests)
  {
    std::cout << "---\n(x,y): (" << x << "," << y << ")\npoints: ";
    for (auto& p : points)
    {
      std::cout << "(" << p[0] << "," << p[1] << ") ";
    }
    std::cout << "\nnearestValidPoint index: ";
    std::cout << Solution().nearestValidPoint(x, y, points) << std::endl;
  }

  return 0;
}
