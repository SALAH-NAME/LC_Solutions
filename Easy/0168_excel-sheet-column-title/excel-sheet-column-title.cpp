#include <string>
#include <algorithm>

class Solution
{
public:
	std::string convertToTitle(int columnNumber)
	{
		std::string result;
		int mod;

		while (columnNumber)
		{
			columnNumber--;
			mod = columnNumber % 26;
			columnNumber /= 26;
			result += ('A' + mod);
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
};
