#include <algorithm>
#include <cctype>
#include <string>

class Solution
{
public:
	std::string licenseKeyFormatting(std::string s, int k)
	{
		std::string res;
		res.reserve(s.size());

		int count = 0;
		for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
		{
			char c = s[i];
			if (c == '-') continue;
			if (count == k)
				res.push_back('-'), count = 0;

			res.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
			++count;
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};
