#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int maxNumberOfBalloons(std::string text)
	{
		std::vector<int> freq(26, 0);
		for (char c : text)
			freq[c - 'a']++;

		int b = freq['b' - 'a'];
		int a = freq['a' - 'a'];
		int l = freq['l' - 'a'] / 2;
		int o = freq['o' - 'a'] / 2;
		int n = freq['n' - 'a'];

		return std::min({b, a, l, o, n});
	}
};

int main()
{
	std::vector<std::string> tests = {
		"nlaebolko",
		"loonbalxballpoon",
		"leetcode",
	};

	for (auto& t : tests)
	{
		std::cout << "---\ntext: '" << t << "'\nmaxNumberOfBalloons: ";
		std::cout << Solution().maxNumberOfBalloons(t) << std::endl;
	}
	return 0;
}
