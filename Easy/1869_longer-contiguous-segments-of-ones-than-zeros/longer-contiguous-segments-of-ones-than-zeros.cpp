#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	bool checkZeroOnes(std::string s)
	{
		int maxOnes = 0, maxZeros = 0;
		int count = 1;

		for (size_t i = 1; i <= s.size(); i++)
		{
			if (i < s.size() && s[i] == s[i - 1])
			{
				count++;
			}
			else
			{
				if (s[i - 1] == '1')
					maxOnes = std::max(maxOnes, count);
				else
					maxZeros = std::max(maxZeros, count);
				count = 1;
			}
		}
		return maxOnes > maxZeros;
	}
};

typedef struct testCase
{
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"1101"},
		{"111000"},
		{"110100010"},
	};

	for (auto& [s] : tests)
	{
		std::cout << "---\ns: '" << s << "'\ncheckZeroOnes: ";
		std::cout << (Solution().checkZeroOnes(s) ? "True" : "False") << std::endl;
	}
	return 0;
}
