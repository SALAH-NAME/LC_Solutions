#include <string>

class Solution
{
public:
 	char findTheDifference(std::string s, std::string t)
	{
		char res = 0;
		for (char c : t) res ^= c;
		for (char c : s) res ^= c;
		return res;
	}
};
