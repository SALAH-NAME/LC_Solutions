#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

class Solution
{
public:
	bool isPalindrome(std::string s)
	{
		s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) { return !std::isalnum(c); }), s.end());
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });

		return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
	}
};
