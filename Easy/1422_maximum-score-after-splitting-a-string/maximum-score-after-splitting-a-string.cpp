#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int maxScore(std::string s)
	{
		int totalOnes = 0;
		for (char c : s)
			if (c == '1') totalOnes++;

		int leftZeros = 0;
		int rightOnes = totalOnes;
		int maxScore = 0;

		for (int i = 0; i < s.size() - 1; i++)
		{
			if (s[i] == '0') leftZeros++;
			else rightOnes--;

			maxScore = std::max(maxScore, leftZeros + rightOnes);
		}
		return maxScore;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"011101",
		"00111",
		"1111",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nmaxScore: ";
		std::cout << Solution().maxScore(s) << std::endl;
	}
	return 0;
}
