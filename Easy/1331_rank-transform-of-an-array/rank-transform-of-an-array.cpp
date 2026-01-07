#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> arrayRankTransform(std::vector<int>& arr)
	{
		std::vector<int> sorted = arr;
		std::sort(sorted.begin(), sorted.end());
		sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());

		std::unordered_map<int, int> rank;
		for (int i = 0; i < sorted.size(); i++)
			rank[sorted[i]] = i + 1;

		for (int& num : arr)
			num = rank[num];
		return arr;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
		{40,10,20,30},
		{100,100,100},
		{37,12,28,9,100,56,80,5,12},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\narrayRankTransform: ";
		printV(Solution().arrayRankTransform(arr));
		std::cout << std::endl;
	}
	return 0;
}
