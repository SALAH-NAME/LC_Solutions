#include <vector>
#include <iostream>

class Solution
{
public:
	int countOdds(int low, int high)
	{
		int diff = high - low;
		if (low % 2 == 1 || high % 2 == 1)
			return diff / 2 + 1;
		else
			return diff / 2;
	}
};

typedef struct testCase
{
	int l;
	int h;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{3, 7},
		{8, 10},
	};

	for (auto& [l, h] : tests)
	{
		std::cout << "---\nlow: " << l << ", high: " << h << "\ncountOdds: ";
		std::cout << Solution().countOdds(l, h) << std::endl;
	}
	return 0;
}
