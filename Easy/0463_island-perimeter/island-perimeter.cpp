#include <vector>

class Solution
{
private:
	short dfs(std::vector<std::vector<int> >& grid, short r, short c)
	{
		if (r < 0 || r >= static_cast<short>(grid.size())
			|| c < 0 || c >= static_cast<short>(grid[r].size()))
			return 1;

		if (grid[r][c] == 0) return 1;
		if (grid[r][c] == -1) return 0;
		grid[r][c] = -1;

		short res = 0;
		res += dfs(grid, r - 1, c);
		res += dfs(grid, r + 1, c);
		res += dfs(grid, r, c - 1);
		res += dfs(grid, r, c + 1);
		return res;
	}

public:
	int islandPerimeter(std::vector<std::vector<int>>& grid)
	{
		short rows = grid.size();
		if (rows == 0) return 0;
		short cols = grid[0].size();

		for (int r = 0; r < rows; ++r)
			for (int c = 0; c < cols; ++c)
				if (grid[r][c] == 1)
					return dfs(grid, r, c);
		return 0;
	}
};
