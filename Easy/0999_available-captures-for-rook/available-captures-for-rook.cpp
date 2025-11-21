#include <iostream>
#include <vector>

class Solution
{
public:
	int numRookCaptures(std::vector<std::vector<char>>& board)
	{
		int xr = 0, yr = 0;
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board[x].size(); y++)
			{
				if (board[x][y] == 'R')
				{
					xr = x;
					yr = y;
					break;
				}
			}
		}
		
		int captures = 0;
		int dx[4] = {-1, 1, 0, 0};
		int dy[4] = {0, 0, -1, 1};

		for (int d = 0; d < 4; d++)
		{
			int x = xr, y = yr;
			while (true)
			{
				x += dx[d];
				y += dy[d];
				if (x < 0 || x >= 8 || y < 0 || y >= 8) break;
				if (board[x][y] == 'B') break;
				if (board[x][y] == 'p')
				{
					captures++;
					break;
				}
			}
		}
		return captures;
	}
};

void printBoard(const std::vector<std::vector<char>>& board)
{
	for (const auto& row : board)
	{
		for (const auto& cell : row)
			std::cout << cell << " ";
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<std::vector<std::vector<char>>> tests = {
			{{'.','.','.','.','.','.','.','.'},
			{'.','.','.','p','.','.','.','.'},
			{'.','.','.','R','.','.','.','p'},
			{'.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.'},
			{'.','.','.','p','.','.','.','.'},
			{'.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.'}},
			{{'.','.','.','.','.','.','.','.'},
			{'.','p','p','p','p','p','.','.'},
			{'.','p','p','B','p','p','.','.'},
			{'.','p','B','R','B','p','.','.'},
			{'.','p','p','B','p','p','.','.'},
			{'.','p','p','p','p','p','.','.'},
			{'.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.'}},
			{{'.','.','.','.','.','.','.','.'},
			{'.','.','.','p','.','.','.','.'},
			{'.','.','.','p','.','.','.','.'},
			{'p','p','.','R','.','p','B','.'},
			{'.','.','.','.','.','.','.','.'},
			{'.','.','.','B','.','.','.','.'},
			{'.','.','.','p','.','.','.','.'},
			{'.','.','.','.','.','.','.','.'}},
		};

	for (auto& board : tests)
	{
		std::cout << "---\nboard:\n";
		printBoard(board);
		std::cout << "\nnumRookCaptures: " << Solution().numRookCaptures(board);
		std::cout << std::endl;
	}
}
