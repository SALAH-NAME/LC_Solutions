#include <string>

class Solution
{
public:
	bool validPalindrome(std::string s)
	{
		int first = 0;
		int last = s.size() - 1;
		while (first < last)
		{
			if (s[first] != s[last])
				return isPalindrom(s, first + 1, last) || isPalindrom(s, first, last - 1);
			first++;
			last--;
		}
		return true;
	}
private:
	bool isPalindrom(const std::string& s, int first, int last)
	{
		while (first < last)
		{
			if (s[first] != s[last]) return false;
			first++;
			last--;
		}
		return true;
	}
};
