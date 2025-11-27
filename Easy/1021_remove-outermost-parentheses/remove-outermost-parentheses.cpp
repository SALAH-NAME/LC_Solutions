#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	std::string removeOuterParentheses(std::string s)
	{
		std::string result;
		int p = 0;
		for (char c : s)
		{
			if (c == '(')
			{
				if (p++ > 0) result.push_back(c);
			}
			else
				if (--p > 0) result.push_back(c);
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
			"(()())(())",
			"(()())(())(()(()))",
			"()()",
		};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nremoveOuterParentheses: '";
		std::cout << Solution().removeOuterParentheses(s) << "'";
		std::cout << std::endl;
	}
	return 0;
}
