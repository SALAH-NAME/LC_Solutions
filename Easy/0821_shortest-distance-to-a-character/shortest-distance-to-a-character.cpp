#include <climits>
#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<int> shortestToChar(std::string s, char c)
	{
		int n = s.size();
		std::vector<int> result (n, INT_MAX);

		int pos = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == c) pos = i;
			result[i] = std::abs(i - pos);
		}

		pos = INT_MAX;
		for (int i = n - 1; i >= 0; --i)
		{
			if (s[i] == c) pos = i;
			result[i] = std::min(result[i], std::abs(i - pos));
		}
		return result;
	}
};

int main()
{
	std::vector<std::pair<std::string, char>> tests = {
		{"loveleetcode", 'e'},
		{"aaab", 'b'}
	};

	for (const auto& [s, c] : tests)
	{
		std::cout << "---\ns= " << s << "\nc= " << c << "shortestToChar:\n[";
		std::vector<int> res = Solution().shortestToChar(s, c);
		for (int i = 0; i < res.size(); i++)
			std::cout << res[i] << ( i < res.size() - 1 ? ", " : "");
		std::cout << "]" << std::endl;
	}
	return 0;
}
