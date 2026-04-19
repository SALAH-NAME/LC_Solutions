#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string replaceDigits(std::string s)
	{
		for (int i = 1; i < s.size(); i += 2)
		{
			s[i] = s[i - 1] + (s[i] - '0');
		}
		return s;
	}
};

typedef struct testCase
{
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"a1c1e1"},
		{"a1b2c3d4e"},
	};

	for (auto& [s] : tests)
	{
		std::cout << "---\ns: '" << s << "'\nreplaceDigits: '";
		std::cout << Solution().replaceDigits(s) << "'" << std::endl;
	}
	return 0;
}
