#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	int balancedStringSplit(std::string s)
	{
		int balance = 0;
		int count = 0;
		for (char c : s)
		{
			if (c == 'R')
				balance++;
			else if (c == 'L')
				balance--;

			if (balance == 0)
				count++;
		}
		return count;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"RLRRLLRLRL",
		"RLRRRLLRLL",
		"LLLLRRRR",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nbalancedStringSplit: ";
		std::cout << Solution().balancedStringSplit(s) << std::endl;
	}
	return 0;
}
