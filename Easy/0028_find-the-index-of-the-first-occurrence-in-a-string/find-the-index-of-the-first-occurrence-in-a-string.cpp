#include <cstring>
#include <string>


class Solution {
public:
	int strStr(std::string haystack, std::string needle)
	{
		const char *hay = haystack.c_str();
		const char *str = std::strstr(hay, needle.c_str());
		if (!str)
			return -1;
		return str - hay;
	}
};

