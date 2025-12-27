#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string tictactoe(std::vector<std::vector<int>>& moves)
	{
		std::vector<int> rows(3, 0), cols(3, 0);
		int diag = 0, antiDiag = 0;
		
		for (int i = 0; i < moves.size(); ++i)
		{
			int r =moves[i][0], c = moves[i][1];
			int player = (i % 2 == 0) ? 1 : -1;

			rows[r] += player;
			cols[c] += player;
			if (r == c) diag += player;
			if (r + c == 2) antiDiag += player;

			if (abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diag)== 3 || abs(antiDiag) == 3)
				return player == 1 ? "A" : "B";
		}
		return moves.size() == 9 ? "Draw" : "Pending";
	}
};

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
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
		{{0,0},{2,0},{1,1},{2,1},{2,2}},
		{{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}},
		{{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}},
	};

	for (auto& moves : tests)
	{
		std::cout << "---\nmoves: ";
		printMat(moves);
		std::cout << "\ntictactoe: "  << Solution().tictactoe(moves);
		std::cout << std::endl;
	}
	return 0;
}
