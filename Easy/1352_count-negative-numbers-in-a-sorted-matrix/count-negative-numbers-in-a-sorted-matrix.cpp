#include <vector>
#include <iostream>

class Solution
{
public:
	int countNegatives(std::vector<std::vector<int>>& grid)
	{
		int count = 0;
		for (const auto& r : grid)
		{
			for (int v : r)
			{
				if (v < 0)
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
		{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}},
		{{3,2},{1,0}},
	};

	for (auto& g : tests)
	{
		std::cout << "---\ngrid: ";
		printMat(g);
		std::cout << "\ncountNegatives: " << Solution().countNegatives(g);
		std::cout << std::endl;
	}
	return 0;
}
