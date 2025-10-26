#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
	int projectionArea(std::vector<std::vector<int>>& grid)
	{
		int n = grid.size();
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			int maxInCol = 0;
			int maxInRow = 0;
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] > 0) sum++;
				maxInRow = std::max(maxInRow, grid[i][j]);
				maxInCol = std::max(maxInCol, grid[j][i]);
			}
			sum += maxInRow + maxInCol;
		}
		return sum;
	}
};

template<typename	T>
void printVector(const std::vector<T>& vec)
{
	std::cout << "[";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
		{{1,2}, {3,4}},
		{{2}},
		{{1,0}, {0,2}},
	};

	for (auto& tc : tests)
	{
		std::cout << "---\ngrid= [";
		for (auto& v : tc)
			printVector(v);
		std::cout << "]\nArea: " << Solution().projectionArea(tc);
		std::cout << std::endl;
	}
	return 0;
}
