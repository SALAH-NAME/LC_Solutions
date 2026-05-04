#include <cmath>
#include <vector>
#include <iostream>

class Solution
{
public:
	int countTriples(int n)
	{
		int count = 0;
		for (int a = 1; a <= n; ++a)
		{
			for (int b = 1; b <= n; ++b)
			{
				int squareSum = a * a + b * b;
				int c = std::sqrt(squareSum);
				if (c <= n && c * c == squareSum)
				{
					count++;
				}
			}
		}
		return count;
	}
};

typedef struct testCase
{
	int n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{5},
		{10},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nn: " << n << "\ncountTriples: ";
		std::cout << Solution().countTriples(n) << std::endl;
	}
	return 0;
}
