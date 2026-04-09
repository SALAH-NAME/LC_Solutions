#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int findCenter(std::vector<std::vector<int>>& edges)
  {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
      return edges[0][0];
    return edges[0][1];
  }
};

typedef struct testCase
{
  std::vector<std::vector<int>> edges;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{1,2},{2,3},{4,2}}},
    {{{1,2},{5,1},{1,3},{1,4}}},
    {{{2,1},{3,2},{4,2}}}
  };

  for (auto& [edges] : tests)
  {
    std::cout << "---\nedges: ";
    for (auto& e : edges)
    {
      std::cout << "(" << e[0] << "," << e[1] << ") ";
    }
    std::cout << "\nfindCenter: ";
    std::cout << Solution().findCenter(edges) << std::endl;
  }

  return 0;
}
