#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
	std::string longestNiceSubstring(std::string s)
	{
		if (s.size() < 2) return "";

		std::unordered_set<char> chars(s.begin(), s.end());

		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if (chars.count(toupper(c)) && chars.count(tolower(c)))
				continue;

			std::string left = longestNiceSubstring(s.substr(0, i));
			std::string right = longestNiceSubstring(s.substr(i+1));
			return left.size() >= right.size() ? left : right;
		}
		return s;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"YazaAay",
		"Bb",
		"c",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nlongestNiceSubstring: '";
		std::cout <<  Solution().longestNiceSubstring(s) << "'" << std::endl;
	}
	return 0;
}
