#include <iostream>
#include <string>
#include <vector>

class Solution
{
private:
	std::string build(const std::string& str)
	{
		std::string result;
		for (char c : str)
		{
			if (c == '#')
			{
				if (!result.empty())
					result.pop_back();
			}
			else
			{
				result.push_back(c);
			}
		}
		return result;
	}

public:
	bool backspaceCompare(std::string s, std::string t)
	{
		return build(s) == build(t);
	}
};

typedef struct testCase
{
	std::string s;
	std::string t;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{"ab#c", "ad#c"},
			{"ab##", "c#d#"},
			{"a#c", "b"},
			{"###c", "c"},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\ns=\"" << tc.s << "\" t=\"" << tc.t << "\" => ";
		std::cout << (Solution().backspaceCompare(tc.s, tc.t) ? "True" : "False") << std::endl;
	}

	return 0;
}
