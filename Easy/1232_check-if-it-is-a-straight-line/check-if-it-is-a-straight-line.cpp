#include <vector>
#include <iostream>

class Solution
{
public:
	bool checkStraightLine(std::vector<std::vector<int>>& coordinates)
	{
		if (coordinates.size() <= 2)
			return true;

		int x1 = coordinates[0][0];
		int y1 = coordinates[0][1];
		int x2 = coordinates[1][0];
		int y2 = coordinates[1][1];

		int dx = x2 - x1;
		int dy = y2 - y1;

		for (int i = 2; i < coordinates.size(); ++i)
		{
			int x = coordinates[i][0];
			int y = coordinates[i][1];

			if (dy * (x - x1) != dx * (y - y1))
				return false;
		}
    return true;
	}
};

void printM(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); i++)
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
		{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}},
		{{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}},
	};

	for (auto& m : tests)
	{
		std::cout << "---\ncoordinates: ";
		printM(m);
		std::cout << "\ncheckStraightLine: ";
		std::cout << (Solution().checkStraightLine(m) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
