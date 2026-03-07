#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
	int maxLengthBetweenEqualCharacters(std::string s)
	{
		std::unordered_map<char, int> firstIndex;
		int maxLen = -1;

		for (int i = 0; i < s.size(); ++i)
		{
			if (firstIndex.find(s[i]) == firstIndex.end())
				firstIndex[s[i]] = i;
			else
				maxLen = std::max(maxLen, i - firstIndex[s[i]] - 1);
		}
		return maxLen;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"aa",
		"abca",
		"cbzxy",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nmaxLengthBetweenEqualCharacters: ";
		std::cout << Solution().maxLengthBetweenEqualCharacters(s) << std::endl;
	}
	return 0;
}
