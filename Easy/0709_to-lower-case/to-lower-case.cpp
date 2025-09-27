#include <algorithm>
#include <cctype>
#include <string>

class Solution
{
public:
	std::string toLowerCase(std::string s)
	{
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
		return s;
	}
};
