#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	bool checkIfPangram(std::string sentence)
	{
		int seen = 0;
		for (char c : sentence)
		{
			seen |= (1 << (c - 'a'));
		}
		return seen == ((1 << 26) - 1);
	}
};

typedef struct testCase
{
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"thequickbrownfoxjumpsoverthelazydog"},
		{"leetcode"},
	};

	for (auto& [s] : tests)
	{
		std::cout << "---\nsentence: '" << s << "'\ncheckIfPangram: ";
		std::cout << (Solution().checkIfPangram(s) ? "True" : "False") << std::endl;
	}

	return 0;
}
