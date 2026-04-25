#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
	int countGoodSubstrings(std::string s)
	{
		int count = 0;
		for (int i = 0; i + 2 < s.size(); i++)
		{
			std::unordered_set<char> window = {s[i], s[i+1], s[i+2]};
			if (window.size() == 3)
				count++;
		}
		return count;
	}
};


typedef struct testCase
{
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"xyzzaz"},
		{"aababcabc"},
	};

	for (auto& [s] : tests)
	{
		std::cout << "---\ns: '" << s << "'\ncountGoodSubstrings: ";
		std::cout << Solution().countGoodSubstrings(s) << std::endl;
	}
	return 0;
}
