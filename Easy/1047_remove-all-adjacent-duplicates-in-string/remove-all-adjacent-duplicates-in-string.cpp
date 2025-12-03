#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	std::string removeDuplicates(std::string s)
	{
		std::string result;
		for (char c : s)
		{
			if (!result.empty() && result.back() == c)
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
			"abbaca",
			"azxxzy",
		};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\n";
		std::cout << "removeDuplicates: '" << Solution().removeDuplicates(s) << "'";
		std::cout << std::endl;
	}
}
