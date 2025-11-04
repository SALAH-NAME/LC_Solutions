#include <climits>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	bool hasGroupsSizeX(std::vector<int>& deck)
	{
		std::unordered_map<int, int> freq;
		for (int n : deck)
			freq[n]++;

		int g = 0;
		for (auto it : freq)
			g = std::gcd(g, it.second);
		return g >= 2;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{1,2,3,4,4,3,2,1},
			{1,1,1,2,2,2,3,3},
			{1,1,1,1,2,2,2,2,3,3},
			{1,1,1,1,2,2,2,3,3,3},
			{1,1,1,2,2,2,3,3,3},
			{1,1,2,2,2,2},
			{1},
			{1,1,1,1,2,2,2,2,2,2},
		};

	for (auto& deck : tests)
	{
		std::cout << "---\ndeck: ";
		printVector(deck);
		std::cout << "\nhasGroupSizeX: ";
		std::cout << (Solution().hasGroupsSizeX(deck) ? "True" : "False");
		std::cout << std::endl;
	}
}
