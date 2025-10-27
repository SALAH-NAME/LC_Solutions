#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2)
	{
		std::unordered_map<std::string, int>	freq;
		std::vector<std::string> result;

		auto process = [&](const std::string& s) {
			std::istringstream iss(s);
			std::string word;
			while (iss >> word)
				freq[word]++;	
		};

		process(s1);
		process(s2);

		for (auto& [word, count] : freq)
		{
			if (count == 1)
				result.push_back(word);
		}

		return result;
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
		{"this apple is sweet", "this apple is sour"},
		{"apple apple", "banana"},
		{"test this apple is sweet", "this apple is sour"},
	};

	for (auto& tc : tests)
	{
		std::cout << "---\ns1='" << tc.s1 << "' s2='" << tc.s2 << "'\nresult: ";
		std::vector<std::string> res = Solution().uncommonFromSentences(tc.s1, tc.s2);
		for (auto& s : res)
			std::cout << "'" << s << "', ";
		std::cout << std::endl;
	}
	return 0;
}
