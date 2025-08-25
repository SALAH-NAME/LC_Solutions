#include <algorithm>
#include <cctype>
#include <string>

class Solution
{
public:
  std::string reverseWords(std::string s)
	{
		auto start = s.begin();
		while (start < s.end())
		{
			auto it = std::find_if(start, s.end(), [](unsigned char c){ return std::isspace(c); });
			std::reverse(start, it);
			if (it == s.end()) break;
			start = it + 1;
		}
		return s;
	}
};
