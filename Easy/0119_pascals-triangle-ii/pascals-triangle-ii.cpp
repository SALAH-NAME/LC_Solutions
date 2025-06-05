#include <vector>

class Solution
{
public:
	std::vector<int> getRow(int rowIndex)
	{
		std::vector<std::vector<int>> triangle(rowIndex + 1);

		if (rowIndex < 0)
			return {};
		triangle[0] = {1};
		for (int i = 1; i < rowIndex + 1; ++i)
		{
			triangle[i] = std::vector<int>(i + 1);
			triangle[i][0] = 1;
			triangle[i][i] = 1;
			for (int j = 1; j < i; ++j)
				triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
		}
		return triangle[rowIndex];
	}
};
