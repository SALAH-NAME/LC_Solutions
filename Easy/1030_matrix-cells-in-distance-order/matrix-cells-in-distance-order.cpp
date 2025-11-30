#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
	{
		std::vector<std::vector<int>> result;
		std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
		std::queue<std::pair<int, int>> q;

		q.push({rCenter, cCenter});
		visited[rCenter][cCenter] = true;

		int dirs[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
		while (!q.empty())
		{
			auto [r, c] = q.front();
			q.pop();
			result.push_back({r,c});
			for (auto &d : dirs)
			{
				int nr = r + d[0], nc = c + d[1];
				if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc])
				{
					visited[nr][nc] = true;
					q.push({nr, nc});
				}
			}
		}
		return result;
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

typedef struct testCase
{
	int r;
	int c;
	int rc;
	int cc;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{1, 2, 0, 0},
			{2, 2, 0, 1},
			{2, 3, 1, 2},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\nrows: " << tc.r << ", cols: " << tc.c ;
		std::cout << ", rCenter: " << tc.rc << ", rCenter: " << tc.cc << std::endl;
		std::cout << "allCellsDistOrder: ";
		printMat(Solution().allCellsDistOrder(tc.r, tc.c, tc.rc, tc.cc));
		std::cout << std::endl;
	}
	return 0;
}
