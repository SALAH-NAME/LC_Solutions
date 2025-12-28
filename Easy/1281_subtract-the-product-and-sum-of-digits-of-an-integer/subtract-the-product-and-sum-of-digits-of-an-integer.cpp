#include <vector>
#include <iostream>

class Solution
{
public:
	int subtractProductAndSum(int n)
	{
		int sum = 0;
		int product = 1;

		while (n > 0)
		{
			int digit = n % 10;
			product *= digit;
			sum += digit;
			n /= 10;
		}
		return product - sum;
	}
};

int main()
{
	std::vector<int> tests = {
		234,
		4421,
	};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\nsubtractProductAndSum: ";
		std::cout << Solution().subtractProductAndSum(n) << std::endl;
	}
	return 0;
}
