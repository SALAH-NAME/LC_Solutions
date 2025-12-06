#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Solution
{
public:
	std::vector<std::string> findOcurrences(std::string text, std::string first, std::string second)
	{
		std::vector<std::string> result;
		std::vector<std::string> words;
		std::istringstream iss(text);
		std::string word;

		while (iss >> word)
			words.push_back(word);
		for (size_t i = 0; i + 2 < words.size(); ++i)
		{
			if (words[i] == first && words[i + 1] == second)
				result.push_back(words[i + 2]);
		}
		return result;
	}
};

typedef struct testCase
{
	std::string t;
	std::string f;
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"alice is a good girl she is a good student", "a", "good"},
		{"we will we will rock you", "we", "will"},
	};

	for (auto &tc : tests)
	{
		auto res = Solution().findOcurrences(tc.t, tc.f, tc.s);
		std::cout << "Results: ";
		for (auto &w : res)
			std::cout << w << " ";
		std::cout << "\n";
	}
}
