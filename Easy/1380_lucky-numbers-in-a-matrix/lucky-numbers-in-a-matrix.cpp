#include <vector>
#include <iostream>
#include <climits>

class Solution
{
public:
	std::vector<int> luckyNumbers(std::vector<std::vector<int>>& matrix)
	{
		std::vector<int> result;
		int rows = matrix.size();
		int cols = matrix[0].size();

		for (int i = 0; i < rows; i++)
		{
			int minVal = INT_MAX;
			int minCol = -1;
			for (int j = 0; j < cols; ++j)
			{
				if (matrix[i][j] < minVal)
				{
					minVal = matrix[i][j];
					minCol = j;
				}
			}

			bool isMaxInCol = true;
			for (int k = 0; k < rows; ++k)
			{
				if (matrix[k][minCol] > minVal)
				{
					isMaxInCol = false;
					break;
				}
			}
			if (isMaxInCol)
				result.push_back(minVal);
		}
		return result; 
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
		{{3,7,8},{9,11,13},{15,16,17}},
		{{1,10,4,2},{9,3,8,7},{15,16,17,12}},
		{{7,8},{1,2}},
	};

	for (auto& m : tests)
	{
std::cout << "---\nmatrix: ";
		printMat(m);
		std::cout << "\nluckyNumbers: ";
		printV(Solution().luckyNumbers(m));
		std::cout << std::endl;
	}
	return 0;
}
