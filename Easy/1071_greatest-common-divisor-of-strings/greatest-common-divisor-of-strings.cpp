#include <string>
#include <vector>
#include <iostream>
#include <numeric>

class Solution
{
public:
	std::string gcdOfStrings(std::string str1, std::string str2)
	{
		if (str1 + str2 != str2 + str1)
			return "";
		int len = std::gcd(str1.size(), str2.size());
		return str1.substr(0, len);
	}
};

typedef struct testCase
{
	std::string s1;
	std::string s2;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"ABCABC", "ABC"},
		{"ABABAB", "ABAB"},
		{"LEET","CODE"},
	};

	for (auto& tc : tests)
	{
		std::cout << "---\nstr1: '" << tc.s1 << "', str2: '" << tc.s2 << "'\n";
		std::cout << "gcdOfStrings: '" << Solution().gcdOfStrings(tc.s1, tc.s2) << "'";
		std::cout << std::endl;
	}
	return 0;
}
