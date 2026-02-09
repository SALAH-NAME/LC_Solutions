#include <vector>
#include <iostream>

class Solution
{
public:
	int xorOperation(int n, int start)
	{
		int result = 0;
		for (int i = 0; i < n; i++)
			result ^= (start + 2 * i);
		return result;
	}
};

typedef struct testCase
{
	int n;
	int s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{5, 0},
		{4, 3},
	};

	for (auto& [n, s] : tests)
	{
		std::cout << "---\nn: " << n << ", start: " << s << "\nxorOperation: ";
		std::cout << Solution().xorOperation(n, s) << std::endl;
	}
	return 0;
}
