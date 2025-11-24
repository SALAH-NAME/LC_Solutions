#include <iostream>
#include <vector>

class Solution
{
public:
	int bitwiseComplement(int n)
	{
		if (n == 0) return 1;

		int mask = 1;
		while (mask <= n)
			mask <<= 1;
		return (mask - 1) ^ n;
	}
};

int main()
{
	std::vector<int> tests = {
		5,
		7,
		10,
	};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\nbitwiseComplement: ";
		std::cout << Solution().bitwiseComplement(n);
		std::cout << std::endl;
	}
	return 0;
}
