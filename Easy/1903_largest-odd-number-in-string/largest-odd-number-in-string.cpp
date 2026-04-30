#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string largestOddNumber(std::string num)
	{
		for (int i = num.size() - 1; i >= 0; --i)
		{
			if ((num[i] % 2) != 0)
			{
				return num.substr(0, i + 1);
			}
		}
		return "";
	}
};

typedef struct testCase
{
	std::string n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"52"},
		{"4206"},
		{"35427"},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nnum: " << n << "\nlargestOddNumber: ";
		std::cout << Solution().largestOddNumber(n) << std::endl;
	}
	return 0;
}
