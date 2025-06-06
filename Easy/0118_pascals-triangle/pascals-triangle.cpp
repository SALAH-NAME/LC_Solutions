#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> generate(int numRows)
	{
		std::vector<std::vector<int>> triangle(numRows);

		triangle[0] = {1};
		for (int i = 1; i < numRows; ++i)
		{
			std::vector<int> row(i + 1);
			row[0] = 1, row[i] = 1;
			for (int j = 1; j < i; ++j)
				row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
			triangle[i] = row;
		}
		return triangle;
	}
};
