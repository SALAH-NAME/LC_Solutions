#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	bool areOccurrencesEqual(std::string s)
	{
		std::unordered_map<char, int> counts;
		for (char c : s)
		{
			counts[c]++;
		}

		int targetFreq = counts.begin()->second;
		for (auto const& [key, val] : counts)
		{
			if (val != targetFreq)
			{
				return false;
			}
		}
		return true;
	}
};

typedef struct testCase
{
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"abacbc"},
		{"aaabb"},
	};

	for (auto& [s] : tests)
	{
		std::cout << "---\ns: '" << s << "'\nareOccurrencesEqual: ";
		std::cout << (Solution().areOccurrencesEqual(s) ? "True" : "False") << std::endl;
	}
	return 0;
}
