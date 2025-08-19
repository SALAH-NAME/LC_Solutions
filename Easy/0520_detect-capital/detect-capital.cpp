#include <string>

class Solution
{
public:
	bool detectCapitalUse(std::string word)
	{
		unsigned char i = 0;
		unsigned char n = word.size();

		while (word[i] >= 'A' && word[i] <= 'Z')
			i++;
		if (i > 1 && i != n)
			return false;
	
		while (word[i] >= 'a' && word[i] <= 'z')
			i++;
		return i == n;
	}
};
