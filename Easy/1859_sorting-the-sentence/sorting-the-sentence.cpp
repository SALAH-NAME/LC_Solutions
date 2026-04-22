#include <sstream>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	std::string sortSentence(std::string s)
	{
		std::stringstream ss(s);
		std::string word;
		std::vector<std::string> words(10);

		while (ss >> word)
		{
			int pos = word.back() - '0';
			word.pop_back();
			words[pos] = word;
		}

		std::string result;
		for (int i = 1; i < words.size(); i++)
		{
			if (!words[i].empty())
			{
				if (!result.empty()) result += " ";
				result += words[i];
			}
		}
		return result;
	}
};

typedef struct testCase
{
	std::string s;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"is2 sentence4 This1 a3"},
		{"Myself2 Me1 I4 and3"},
	};

	for (auto& [s] : tests)
	{
		std::cout << "---\ns: '" << s << "'\nsortSentence: '";
		std::cout << Solution().sortSentence(s) << "'" << std::endl;
	}
	return {};
}
