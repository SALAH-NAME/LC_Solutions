#include <algorithm>
#include <string>

class Solution
{
public:
	std::string convertToBase7(int num)
	{
		if (num == 0) return "0";

		char sign = num < 0;
		if (sign) num = -num;

		std::string result;
		while (num)
		{
			result.push_back('0' + (num % 7));
			num /= 7;
		}
		if (sign) result.push_back('-');
		std::reverse(result.begin(), result.end());
		return result;
	}
};
