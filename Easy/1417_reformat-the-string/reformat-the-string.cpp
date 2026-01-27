#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	std::string reformat(std::string s)
	{
		std::string letters, digits;
		for (char c : s)
		{
			if (std::isdigit(c))
				digits.push_back(c);
			else
				letters.push_back(c);
		}

		if (std::abs((int)letters.size() - (int)digits.size()) > 1)
			return "";

		std::string result;
		bool letterFirst = letters.size() >= digits.size();

		int i = 0, j = 0;
		while (i < letters.size() || j < digits.size())
		{
			if (letterFirst && i < letters.size())
				result.push_back(letters[i++]);
			else if (!letterFirst && j < digits.size())
				result.push_back(digits[j++]);
			letterFirst = !letterFirst;
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"a0b1c2",
		"leetcode",
		"1229857369",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nreformat: '";
		std::cout << Solution().reformat(s) << "'" << std::endl;
	}
	return 0;
}
