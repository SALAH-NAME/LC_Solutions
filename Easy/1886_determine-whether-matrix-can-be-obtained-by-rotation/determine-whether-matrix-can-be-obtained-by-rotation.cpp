#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

class Solution
{
public:
	void rotate(std::vector<std::vector<int>>& mat)
	{
		int n = mat.size();

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; ++j)
			{
				std::swap(mat[i][j], mat[j][i]);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			std::reverse(mat[i].begin(), mat[i].end());
		}
	}
	bool findRotation(std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& target)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (mat == target) return true;
			rotate(mat);
		}
		return false;
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

typedef struct testCase
{
	std::vector<std::vector<int>> m;
	std::vector<std::vector<int>> t;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{{0,1},{1,0}}, {{1,0},{0,1}}},
		{{{0,1},{1,1}}, {{1,0},{0,1}}},
		{{{0,0,0},{0,1,0},{1,1,1}}, {{1,1,1},{0,1,0},{0,0,0}}},
	};

	for (auto& [m, t] : tests)
	{
		std::cout << "---\nmat: ";
		std::cout << "\ntarget: ";
		std::cout << "\nfindRotation: ";
		std::cout << (Solution().findRotation(m,t) ? "True" : "False") << std::endl;
	}
	return 0;
}
