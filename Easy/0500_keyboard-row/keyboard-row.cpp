#include <array>
#include <cctype>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> findWords(std::vector<std::string>& words)
	{
		std::array<int, 26> row{};
		for (char c : std::string("qwertyuiop")) row[c - 'a'] = 0;
		for (char c : std::string("asdfghjkl")) row[c - 'a'] = 1;
		for (char c : std::string("zxcvbnm")) row[c - 'a'] = 2;


		std::vector<std::string> result;
		for (const auto& w : words)
		{
			char last = -1;
			bool ok = true;
			for (unsigned char ch : w)
			{
				unsigned char r = row[std::tolower(ch) - 'a'];
				if (last != -1 && last != r)
				{
					ok = false;
					break;
				}
				last = r;
			}
			if (ok) result.push_back(w);
		}
		return result;
	}
};
