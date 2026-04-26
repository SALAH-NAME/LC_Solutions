#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
	int getNumericalValue(std::string word)
	{
		int value = 0;
		for (char c : word)
		{
			value = value * 10 + (c - 'a');
		}
		return value;
	}
	bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord)
	{
		return getNumericalValue(firstWord) + getNumericalValue(secondWord) == getNumericalValue(targetWord);
	}
};

typedef struct testCase
{
	std::string f;
	std::string s;
	std::string t;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"acb", "cba", "cdb"},
		{"aaa", "a", "aab"},
		{"aaa", "a", "aaaa"},
	};

	for (auto& [f, s, t] : tests)
	{
		std::cout << "---\nfirstWord: '" << f << "', secondWord: '" << s << "'\n";
		std::cout << "targetWord: '" << t << "'" << "\nisSumEqual: " << std::endl;
		std::cout << (Solution().isSumEqual(f, s, t) ? "True" : "False") << std::endl;
	}
	return 0;
}
