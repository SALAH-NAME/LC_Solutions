#include <vector>
#include <iostream>

class Solution
{
public:
	int oddCells(int m, int n, std::vector<std::vector<int>>& indices)
	{
		std::vector<int> row(m, 0), col(n, 0);

		for (auto& idx : indices)
		{
			row[idx[0]]++;
			col[idx[1]]++;
		}

		int count = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if ((row[i] + col[j]) % 2 == 1)
					count++;
			}
		}
		return count;
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

typedef struct testCase
{
	int m;
	int n;
	std::vector<std::vector<int>> i;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{2, 3, {{0, 1}, {1, 1}}},
		{2, 3, {{0, 1}, {1, 1}}},
	};

	for (auto& [m, n, i] : tests)
	{
		std::cout << "---\nm: " << m << ", n: " << n << ", indices: ";
		printMat(i);
		std::cout << "\noddCells: " << Solution().oddCells(m, n, i);
		std::cout << std::endl;
	}
	return 0;
}
