#include <vector>
#include <iostream>

class Solution
{
public:
	int numberOfSteps(int num)
	{
		int steps = 0;
		while (num > 0)
		{
			if (num % 2 == 0)
				num /= 2;
			else
				num -= 1;
			steps++;
		}
		return steps;
	}
};


int main()
{
	std::vector<int> tests = {
		14,
		8,
		123,
	};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\nnumberOfSteps: ";
		std::cout << Solution().numberOfSteps(n) << std::endl;
	}
	return 0;
}
