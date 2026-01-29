#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
	{
		int maxCandies = *std::max_element(candies.begin(), candies.end());

		std::vector<bool> result;
		result.reserve(candies.size());

		for (int c : candies)
			result.push_back(c + extraCandies >= maxCandies);

		return result;
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

void printB(const std::vector<bool>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << (v[i] ? "true" : "false");
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> c;
	int e;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{2,3,5,1,3}, 3},
		{{4,2,1,1,2}, 1},
		{{12,1,12}, 10},
	};

	for (auto& [c, e] : tests)
	{
		std::cout << "---\ncandies: ";
		printV(c);
		std::cout << ", extraCandies: " << e << "\nkidsWithCandies: ";
		printB(Solution().kidsWithCandies(c, e));
		std::cout << std::endl;
	}
	return 0;
}
