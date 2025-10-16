#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
private:
	bool isVowel(char c)
	{
		c = std::tolower(c);
		return c  == 'a' || c  == 'e' || c  == 'i' || c  == 'o' || c  == 'u';
	}

public:
	std::string toGoatLatin(std::string sentence)
	{
		std::istringstream iss(sentence);
		std::string word, result;
		int index = 1;

		while (iss >> word)
		{
			if (!isVowel(word[0]))
				word = word.substr(1) + word[0];

			word += "ma" + std::string(index, 'a');

			if (!result.empty()) result += " ";
			result += word;
			index++;
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
			"I speak Goat Latin",
			"The quick brown fox jumped over the lazy dog",
			"g",
			"I",
			"dog",
			"test"
		};

	for (const auto& t : tests) {
		std::cout << "---\nsentence=\"" << t << "\"\nresult=\"" << Solution().toGoatLatin(t) << "\"" << std::endl;
	}
	return 0;
}
