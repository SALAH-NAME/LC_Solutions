#include <vector>
#include <string>

class Solution
{
public:
	bool repeatedSubstringPattern(std::string s)
	{
		short n = s.size();
		if (n < 2) return false;
		std::vector<short> lps(n);

		for (short i = 1, len = 0; i < n;)
		{
			if (s[i] == s[len]) lps[i++] = ++len;
			else if (len > 0) len = lps[len - 1];
			else lps[i++] = 0;
 		}
		int l = lps[n - 1];
		if (l > 0 && n % (n - l) == 0) return true;
		std::string t = (s + s).substr(1, 2 * n - 2);
		return t.find(s) != std::string::npos;
	}
};
