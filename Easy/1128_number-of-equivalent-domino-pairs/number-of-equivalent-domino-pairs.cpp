#include <vector>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
	int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes)
	{
		std::unordered_map<int, int> count;
		int res = 0;

		for (auto& d : dominoes)
		{
			int a = d[0], b = d[1];
			if (a > b) std::swap(a, b);

			int key = a * 10 + b;

			res += count[key];
			count[key]++;
		}
		return res;
	}
};

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); i++)
	{
		std::cout << "{";
		for (int j = 0; j < m[i].size() ; j++)
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
		{{1,2},{2,1},{3,4},{5,6}},
		{{1,2},{1,2},{1,1},{1,2},{2,2}},
	};

	for (auto& d : tests)
	{
		std::cout << "---\ndominoes: ";
		printMat(d);
		std::cout << "\nnumEquivDominoPairs: ";
		std::cout << Solution().numEquivDominoPairs(d);
		std::cout << std::endl;
	}
	return 0;
}
