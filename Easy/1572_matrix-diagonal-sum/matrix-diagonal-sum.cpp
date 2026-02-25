#include <vector>
#include <iostream>

class Solution
{
public:
	int diagonalSum(std::vector<std::vector<int>>& mat)
	{
		int n = mat.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += mat[i][i];
			sum += mat[i][n - i - 1];
		}
		if (n % 2 == 1)
			sum -= mat[n / 2][n / 2];
		return sum;
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
		{{1,2,3},{4,5,6},{7,8,9}},
		{{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}},
		{{5}},
	};

	for (auto& m : tests)
	{
		std::cout << "---\nmat: ";
		printMat(m);
		std::cout << "\ndiagonalSum: " << Solution().diagonalSum(m) << std::endl;
	}
	return 0;
}
