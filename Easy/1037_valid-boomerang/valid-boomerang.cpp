#include <iostream>
#include <vector>

class Solution
{
public:
	bool isBoomerang(std::vector<std::vector<int>>& points)
	{
    int x1 = points[0][0], y1 = points[0][1];
    int x2 = points[1][0], y2 = points[1][1];
    int x3 = points[2][0], y3 = points[2][1];

    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
			return false;

    return (y2 - y1) * (x3 - x1) != (y3 - y1) * (x2 - x1);
	}
};

void printMat(const std::vector<std::vector<int>>& mat)
{
	std::cout << "{";
	for (int i = 0; i < mat.size(); i++)
	{
		std::cout << "{";
		for (int j = 0; j < mat[i].size(); j++)
		{
			std::cout << mat[i][j];
			if (j < mat[i].size() - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		if (i < mat.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
			{{1,1},{2,3},{3,2}},
			{{1,1},{2,2},{3,3}},
		};

	for (auto& points : tests)
	{
		std::cout << "---\npoints: ";
		printMat(points);
		std::cout << "\nisBoomerang: " << (Solution().isBoomerang(points) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
