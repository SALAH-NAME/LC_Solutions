#include <string>

class Solution
{
public:
	int findLUSlength(std::string a, std::string b)
	{
		return (a != b) ? std::max(a.size(), b.size()) : -1;
	}
};
