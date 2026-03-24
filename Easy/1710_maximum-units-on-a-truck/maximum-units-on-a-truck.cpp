#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize)
  {
    std::sort(boxTypes.begin(), boxTypes.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
          return a[1] > b[1];
        });

    int totalUnits = 0;
    for (auto& box : boxTypes)
    {
      int count = std::min(truckSize, box[0]);
      totalUnits += count * box[1];
      truckSize -= count;
      if (truckSize == 0) break;
    }
    return totalUnits;
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

typedef struct testCase
{
  std::vector<std::vector<int>> b;
  int t;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{1,3},{2,2},{3,1}}, 4},
    {{{5,10},{2,5},{4,7},{3,9}}, 10},
  };

  for (auto& [b, t] : tests)
  {
    std::cout << "---\nboxTypes: ";
    printMat(b);
    std::cout << ", truckSize: " << t << "\nmaximumUnits: ";
    std::cout << Solution().maximumUnits(b, t) << std::endl;
  }
  return 0;
}
