#include <climits>
#include <vector>
#include <iostream>

class Solution
{
public:
	int maxProductDifference(std::vector<int>& nums)
	{
		int max1 = INT_MIN, max2 = INT_MIN;
		int min1 = INT_MAX, min2 = INT_MAX;

		for (int n : nums)
		{
			if (n > max1)
			{
				max2 = max1;
				max1 = n;
			}
			else if (n > max2)
			{
				max2 = n;
			}

			if (n < min1)
			{
				min2 = min1;
				min1 = n;
			}
			else if (n < min2)
			{
				min2 = n;
			}
		}

		return (max1 * max2) - (min1 * min2);
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

typedef struct testCase
{
	std::vector<int> n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{5,6,2,7,4}},
		{{4,2,5,9,7,4,8}},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\nmaxProductDifference: ";
		std::cout << Solution().maxProductDifference(n) << std::endl;
	}
	return 0;
}
