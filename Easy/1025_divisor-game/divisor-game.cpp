#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
public:
	bool divisorGame(int n)
	{
		return n % 2 == 0;
	}
};

int main()
{
	std::vector<int> tests = {
		2,
		3,
	};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\ndivisorGame: ";
		std::cout << (Solution().divisorGame(n) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
