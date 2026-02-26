#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	std::string modifyString(std::string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '?')
			{
				for (char c = 'a'; c <= 'c'; c++)
				{
					if ((i > 0 && s[i - 1] == c) || (i + 1 < s.size() && s[i + 1] == c))
						continue;
					s[i] = c;
					break;
				}
			}
		}
		return s;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"?zs",
		"ubv?w",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nmodifyString: '";
		std::cout << Solution().modifyString(s) << "'" << std::endl;
	}
	return 0;
}
