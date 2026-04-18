#include <vector>
#include <iostream>

class Solution
{
public:
	int sumBase(int n, int k)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += n % k;
			n /= k;
		}
		return sum;
	}
};

typedef struct testCase
{
	int n;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{34, 6},
		{10, 10},
	};

	for (auto& [n, k] : tests)
	{
		std::cout << "---\nn: " << n << ", k: " << k << "\nsumBase: ";
		std::cout << Solution().sumBase(n, k) << std::endl;
	}
	return 0;
}
