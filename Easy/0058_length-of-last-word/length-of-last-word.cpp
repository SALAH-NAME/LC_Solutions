#include <string>
#include <cctype>

class Solution {
public:
	int lengthOfLastWord(std::string s)
	{
		size_t len = 0;
		int i = s.size() - 1;
		while (i >= 0 && std::isspace(s[i]))
			i--;
		while (i >= 0 && std::isalpha(s[i]))
			i--, len++;

		return len;
	}
};
