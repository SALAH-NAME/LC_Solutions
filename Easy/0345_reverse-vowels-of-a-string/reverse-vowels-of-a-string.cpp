#include <string>
#include <utility>

class Solution
{
private:
	bool isVowel(unsigned char c)
	{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
					 c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}

public:
	std::string reverseVowels(std::string s)
	{
		int last = s.size();
		int first = 0;

		while (first < last)
		{
			while (!isVowel(s[first]) && first < last)
				first++;
			while (!isVowel(s[last]) && first < last)
				last--;
			std::swap(s[first], s[last]);
			first++;
			last--;
		}
		return s;
	}
};
