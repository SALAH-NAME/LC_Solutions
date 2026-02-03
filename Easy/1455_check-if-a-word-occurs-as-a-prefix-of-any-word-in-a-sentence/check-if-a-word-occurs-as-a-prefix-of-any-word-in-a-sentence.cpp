#include <sstream>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int isPrefixOfWord(std::string sentence, std::string searchWord)
	{
		std::istringstream iss(sentence);
		std::string word;
		int index = 1;
		while (iss >> word)
		{
			if (word.rfind(searchWord, 0) == 0)
				return index;
			index++;
		}
		return -1;
	}
};

typedef struct testCase {
	std::string s;
	std::string w;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"i love eating burger", "burg"},
		{"this problem is an easy problem", "pro"},
		{"i am tired", "you"},
	};

	for (auto& [s, w] : tests)
	{
		std::cout << "---\nsentence: '" << s << "'\nsearchWord: '" << w << "'";
		std::cout << "\nisPrefixOfWord: " << Solution().isPrefixOfWord(s, w);
		std::cout << std::endl;
	}
	return 0;
}
