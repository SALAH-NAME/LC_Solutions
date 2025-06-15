#include <string>

class Solution
{
public:
	int titleToNumber(std::string columnTitle)
	{
		int res = 0;
		for (auto c : columnTitle)
		{
			res *= 26;
			res += (c - 'A' + 1);
		}
		return res;
	}
};
