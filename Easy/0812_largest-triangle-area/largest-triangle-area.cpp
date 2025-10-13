#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

class Solution
{
private:
	double triangleArea(const std::vector<int>& p1, const std::vector<int>& p2, const std::vector<int>& p3) {
		return 0.5 * std::fabs(
			p1[0] * (p2[1] - p3[1]) +
			p2[0] * (p3[1] - p1[1]) +
			p3[0] * (p1[1] - p2[1])
		);
	}
	
public:
	double largestTriangleArea(std::vector<std::vector<int>>& points)
	{
		int n = points.size();
		double maxArea = 0.0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					double area = triangleArea(points[i], points[j], points[k]);
					maxArea = std::max(maxArea, area);
				}
			}
		}
		return maxArea;
	}
};
