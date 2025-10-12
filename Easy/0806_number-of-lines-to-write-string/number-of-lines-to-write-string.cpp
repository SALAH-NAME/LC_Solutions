#include <vector>
#include <string>

class Solution
{
public:
	std::vector<int> numberOfLines(std::vector<int>& widths, std::string s)
	{
		int len = 0;
		int lines = 1;
		for (char c : s)
		{
			len += widths[c - 'a'];
			if (len > 100)
				len = widths[c - 'a'], lines++;
		}
		return {lines, len};
	}
};
