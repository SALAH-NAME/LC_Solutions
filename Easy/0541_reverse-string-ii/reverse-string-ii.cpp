#include <algorithm>
#include <string>

class Solution
{
public:
	std::string reverseStr(std::string s, int k)
	{
		unsigned short n = s.size();
		for (unsigned short i = 0; i < n; i += 2 * k)
		{
			unsigned short end = std::min(i + k, (int)n);
			std::reverse(s.begin() + i, s.begin() + end);
		}
		return s;
	}
};
