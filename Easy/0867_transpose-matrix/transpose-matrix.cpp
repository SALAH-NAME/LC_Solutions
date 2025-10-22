#include <cstddef>
#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix)
	{
		std::vector<std::vector<int>> result(matrix[0].size(), std::vector<int>(matrix.size()));

		for (size_t r = 0; r < matrix.size(); r++)
		{
			for (size_t c = 0; c < matrix[r].size(); c++)
			{
				result[c][r] = matrix[r][c];
			}
		}
		return result;
	}
};

template <typename T>
void printVector(const std::vector<T>& vec)
{
	std::cout << "{";
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
		{{1,2,3}, {4,5,6}, {7,8,9}},
		{{1,2,3}, {4,5,6}},
	};

	for (auto& matrix : tests)
	{
		std::cout << "---\nmatrix= [";
		for (auto& m : matrix)
			printVector(m);
		std::cout << "]" << std::endl;

		matrix = Solution().transpose(matrix);
		std::cout << "transpose_to= [";
		for (auto& m : matrix)
			printVector(m);
		std::cout << "]" << std::endl;

	}
	return 0;
}
