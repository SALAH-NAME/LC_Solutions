#include <algorithm>
#include <vector>

class Solution
{
public:
	int findContentChildren(std::vector<int>& g, std::vector<int>& s)
	{
		std::sort(g.begin(), g.end());
		std::sort(s.begin(), s.end());
		short lg = g.size() - 1, ls = s.size() - 1;
		short count = 0;
		while (ls >= 0 && lg >= 0)
		{
			if (s[ls] >= g[lg])
				count++, ls--, lg--;
			else
				lg--;
		}
		return static_cast<int>(count);
	}
};
