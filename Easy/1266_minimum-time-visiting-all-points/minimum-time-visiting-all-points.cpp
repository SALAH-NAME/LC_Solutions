#include <vector>
#include <iostream>

class Solution 
{
public:
	int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points)
	{
		int total = 0;
		for (int i = 1; i < points.size(); ++i)
		{
			int dx = std::abs(points[i][0] - points[i - 1][0]);
			int dy = std::abs(points[i][1] - points[i - 1][1]);
			total += std::max(dx, dy);
		}
		return total;
	}
};

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
	{
		std::cout << "{";
		for (int j = 0; j < m[i].size(); ++j)
		{
			std::cout << m[i][j];
			if (j < m[i].size() - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		if (i < m.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
		{{1,1},{3,4},{-1,0}},
		{{3,2},{-2,2}}
	};

	for (auto& p : tests)
	{
		std::cout << "---\npoints: ";
		printMat(p);
		std::cout << "\nminTimeToVisitAllPoints: ";
		std::cout << Solution().minTimeToVisitAllPoints(p) << std::endl;
	}
	return 0;
}
