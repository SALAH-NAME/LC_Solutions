#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int largestAltitude(std::vector<int>& gain)
  {
    int altitude = 0;
    int maxAltitude = 0;
    for (int g : gain)
    {
      altitude += g;
      maxAltitude = std::max(maxAltitude, altitude);
    }
    return maxAltitude;
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

int main()
{
  std::vector<std::vector<int>> tests = {
    {-5,1,5,0,-7},
    {-4,-3,-2,-1,4,3,2},
  };

  for (auto& g : tests)
  {
    std::cout << "---\ngain: ";
    printV(g);
    std::cout << "\nlargestAltitude: ";
    std::cout << Solution().largestAltitude(g) << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
