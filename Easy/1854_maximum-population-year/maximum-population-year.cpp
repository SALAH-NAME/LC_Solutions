#include <map>
#include <vector>
#include <iostream>

class Solution
{
public:
	int maximumPopulation(std::vector<std::vector<int>>& logs)
	{
		std::map<int, int> changes;
		for (auto& log : logs)
		{
			changes[log[0]]++;
			changes[log[1]]--;
		}

		int maxPop = 0;
		int year = 0;
		int currPop = 0;
		for (auto& [y, delta] : changes)
		{
			currPop += delta;
			if (currPop > maxPop)
			{
				maxPop = currPop;
				year = y;
			}
		}
		return year;
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
	std::vector<std::vector<int>> l;
} testCase;


int main()
{
	std::vector<testCase> tests = {
		{{{1993,1999},{2000,2010}}},
		{{{1950,1961},{1960,1971},{1970,1981}}},
	};

	for (auto& [t] : tests)
	{
		std::cout << "---\nlogs: ";
		printMat(t);
		std::cout << "\nmaximumPopulation: ";
		std::cout << Solution().maximumPopulation(t) << std::endl;
	}
	return 0;
}
