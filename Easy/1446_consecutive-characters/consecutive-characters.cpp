#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int maxPower(std::string s)
	{
		int maxLen = 1;
		int currLen = 1;

		for (size_t i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1])
			{
				currLen++;
				maxLen = std::max(maxLen, currLen);
			}
			else
				currLen = 1;
		}
		return maxLen;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"leetcode",
		"abbcccddddeeeeedcba",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nmaxPower: ";
		std::cout << Solution().maxPower(s) << std::endl;
	}
	return 0;
}
