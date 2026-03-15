#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2)
	{
		std::string s1, s2;
		for (auto& w : word1) s1 += w;
		for (auto& w : word2) s2 += w;
		return s1 == s2;
	}
};

void printV(const std::vector<std::string>& w)
{
	std::cout << "{";
	for (int i = 0; i < w.size(); i++)
	{
		std::cout << w[i];
		if (i < w.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<std::string> w1;
	std::vector<std::string> w2;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{"ab", "c"}, {"a", "bc"}},
		{{"a", "cb"}, {"ab", "c"}},
		{{"abc", "d", "defg"}, {"abcddefg"}},
	};

	for (auto& [w1, w2] : tests)
	{
		std::cout << "---\nword1: ";
		printV(w1);
		std::cout << ", word2: ";
		printV(w2);
		std::cout << "\narrayStringsAreEqual: ";
		std::cout << (Solution().arrayStringsAreEqual(w1,w2) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
