#include <string>

class Solution
{
public:
	int longestPalindrome(std::string s)
	{
		short freq[128] = {0};

		for (char c : s)
			freq[static_cast<unsigned char>(c)]++;

		short len = 0;
		bool  odd = false;
		for (auto x : freq)
		{
			len += (x / 2) * 2;
			if (x % 2 == 1) odd = true;
		}
		len += (odd ? 1 : 0);
		return static_cast<int>(len);
	}
};
