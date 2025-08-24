#include <string>

class Solution
{
public:
	bool checkRecord(std::string s)
	{
		short A = 0;
		short L = 0;
		for (char c : s)
		{
			if (c == 'A' && ++A >= 2) return false;
			if (c == 'L')
			{
				if (++L >= 3)	return false;
			}
			else
				L = 0;
		}
		return true;
	}
};
