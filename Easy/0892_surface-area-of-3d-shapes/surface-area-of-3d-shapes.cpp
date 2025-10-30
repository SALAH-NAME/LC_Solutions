#include <iostream>
#include <vector>

class Solution
{
public:
	int surfaceArea(std::vector<std::vector<int>>& grid)
	{
		int result = 0;
		int n = grid.size();

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid.size(); j++)
			{
				if (grid[i][j] > 0)
				{
					result += 2 + grid[i][j] * 4;

					if (i + 1 < n) result -= 2 * std::min(grid[i][j], grid[i + 1][j]);
					if (j + 1 < n) result -= 2 * std::min(grid[i][j], grid[i][j + 1]);
				}
			}
		}
		return result;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
			{{1,2}, {3,4}},
			{{1,1,1}, {1,0,1}, {1,1,1}},
			{{2,2,2}, {2,1,2}, {2,2,2}},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\ngrid=[";
		for (auto& v : tc)
			printVector(v);
		std::cout << "]\nArea: " << Solution().surfaceArea(tc) << std::endl;
	}

	return 0;
}
