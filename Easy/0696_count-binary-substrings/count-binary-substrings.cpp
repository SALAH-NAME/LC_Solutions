#include <algorithm>
#include <string>

class Solution
{
public:
	int countBinarySubstrings(std::string s)
	{
		int prevRunLength = 0, currRunLength = 1, count = 0;
		for (unsigned int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1]) ++currRunLength;
			else
			{
				count += std::min(prevRunLength, currRunLength);
				prevRunLength = currRunLength;
				currRunLength = 1;
			}
		}
		count += std::min(prevRunLength, currRunLength);
		return count;
	}
};
