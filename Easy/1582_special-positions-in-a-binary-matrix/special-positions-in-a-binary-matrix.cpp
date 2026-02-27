#include <vector>
#include <iostream>

class Solution
{
public:
	int numSpecial(std::vector<std::vector<int>>& mat)
	{
		int rows = mat.size();
		int cols = mat[0].size();

		std::vector<int> rowSum(rows, 0);
		std::vector<int> colSum(cols, 0);

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (mat[i][j] == 1)
				{
					rowSum[i]++;
					colSum[j]++;
				}
			}
		}

		int count = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1)
					count++;
			}
		}
		return count;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
	{
		printV(m[i]);
		if (i < m.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
		{{1,0,0},{0,0,1},{1,0,0}},
		{{1,0,0},{0,1,0},{0,0,1}},
	};

	for (auto& m : tests)
	{
		std::cout << "---\nmat: ";
		printMat(m);
		std::cout << "\nnumSpecial: " << Solution().numSpecial(m) << std::endl;
	}
	return 0;
}
