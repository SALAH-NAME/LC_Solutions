#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	std::string makeGood(std::string s)
	{
		std::string result;
		for (char c : s)
		{
			if (!result.empty() && std::abs(result.back() - c) == 32)
				result.pop_back();
			else
				result.push_back(c);
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"leEeetcode",
		"abBAcC",
		"s",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nmakeGood: '";
		std::cout << Solution().makeGood(s) << "'" << std::endl;
	}
	return 0;
}
