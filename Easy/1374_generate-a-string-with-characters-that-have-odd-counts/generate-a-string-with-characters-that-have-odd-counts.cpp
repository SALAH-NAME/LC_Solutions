#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::string generateTheString(int n)
	{
		if (n % 2 == 1)
			return std::string(n, 'a');
		else
			return std::string(n - 1, 'a') + 'b';
	}
};

int main()
{
	std::vector<int> tests = {
		4, 2, 7
	};

	for (auto& n : tests)
	{
		std::cout << "---\nn: " << n << "\ngenerateTheString: ";
		std::cout << Solution().generateTheString(n) << std::endl;
	}
	return 0;
}
