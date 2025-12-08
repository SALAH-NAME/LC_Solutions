#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> distributeCandies(int candies, int num_people)
	{
		std::vector<int> result(num_people, 0);
		int give = 1;
		int i = 0;

		while (candies > 0)
		{
			int toGive = std::min(give, candies);
			result[i % num_people] += toGive;
			candies -= toGive;
			give++;
			i++;
		}
		return result;
	}
};

void printVec(const std::vector<int>& v)
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

typedef struct testCase
{
	int c;
	int n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{7, 4},
		{10, 3},
	};

	for (auto& [c, n] : tests)
	{
		std::cout << "---\ncandies: " << c << ", num_people: " << n << std::endl;
		std::cout << "distributeCandies: ";
		printVec(Solution().distributeCandies(c, n));
		std::cout << std::endl;
	}
	return 0;
}
