#include <vector>

class Solution
{
public:
	bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix)
	{
		for (int r = 1; r < matrix.size(); ++r)
		{
			for (int c = 1; c < matrix[r].size(); ++c)
			{
				if (matrix[r][c] != matrix[r-1][c-1])
					return false;
			}
		}
		return true;
	}
};
