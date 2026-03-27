#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countGoodRectangles(std::vector<std::vector<int>>& rectangles)
  {
    int maxLen = 0;
    int count = 0;

    for (auto& r : rectangles)
    {
      int side = std::min(r[0], r[1]);
      if (side > maxLen)
      {
        maxLen = side;
        count = 1;
      }
      else if (side == maxLen)
      {
        count++;
      }
    }
    return count;
  }
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
	{
		printV(m[i]);
		if (i < m.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
  std::vector<std::vector<std::vector<int>>> tests = {
    {{5,8},{3,9},{5,12},{16,5}},
    {{2,3},{3,7},{4,3},{3,7}},
  };

  for (auto& r : tests)
  {
    std::cout << "---\nrectangles: ";
    printMat(r);
    std::cout << "\ncountGoodRectangles: ";
    std::cout << Solution().countGoodRectangles(r) << std::endl;
  }
  return 0;
}
