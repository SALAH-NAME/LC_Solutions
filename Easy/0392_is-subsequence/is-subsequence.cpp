#include <string>

class Solution
{
public:
	bool isSubsequence(std::string s, std::string t)
	{
		short i = 0,j = 0, ns = s.size(), nt = t.size();
		while(i < ns && j < nt)
		{
			if (s[i] == t[j])
				i++;
			j++;
		}
		return i == ns;
	}
};
