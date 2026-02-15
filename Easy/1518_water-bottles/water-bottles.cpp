#include <vector>
#include <iostream>

class Solution
{
public:
	int numWaterBottles(int numBottles, int numExchange)
	{
		int total = numBottles;
		int empty = numBottles;

		while (empty >= numExchange)
		{
			int newBotteles = empty /numExchange;
			total += newBotteles;
			empty = empty % numExchange + newBotteles;
		}
		return total;
	}
};

typedef struct testCase
{
	int b;
	int e;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{9,3},
		{15,4},
	};

	for (auto& [b, e] : tests)
	{
		std::cout << "---\nnumBottles: " << b << ", numExchange: " << e << "\n";
		std::cout << "numWaterBottles: " << Solution().numWaterBottles(b, e);
		std::cout << std::endl;
	}
	return 0;
}
