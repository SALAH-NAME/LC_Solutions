#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::vector<int>> largeGroupPositions(std::string s)
	{
		std::vector<std::vector<int>> result;
		int n = s.size();

		for (int i = 0; i < n; )
		{
			int j = i;
			
			while (j < n && s[j] == s[i])
				++j;

			if (j - i >= 3)
				result.push_back({i, j - 1});

			i = j;
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"abbxxxxzzy",
		"abc",
		"abcdddeeeeaabbbcd",
		"aaaaaaa"
	};

	for (const auto& s : tests)
	{
		std::cout << "---\ns=\"" << s << "\" => res [";
		std::vector<std::vector<int>> res = Solution().largeGroupPositions(s);
		for (int i = 0; i < res.size(); i++)
		{
			 std::cout << "[" << res[i][0] << ", " << res[i][1] << "]";
			if (i != res.size() - 1)
				std::cout << ", ";
		}
		std::cout << "]" << std::endl;
	}
	return 0;
}
