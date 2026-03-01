#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
	std::string reorderSpaces(std::string text)
	{
		int spaceCount = 0;
		for (char c : text)
			if (c == ' ') spaceCount++;

		std::vector<std::string> words;
		std::istringstream iss(text);
		std::string word;
		while (iss >> word)
			words.push_back(word);

		int n = words.size();
		if (n == 1)
			return words[0] + std::string(spaceCount, ' ');

		int spaceBetween = spaceCount / (n - 1);
		int extraSpace = spaceCount % (n - 1);

		std::string result;
		for (int i = 0; i < n; i++)
		{
			result += words[i];
			if (i < n - 1)
				result += std::string(spaceBetween, ' ');
		}
		result += std::string(extraSpace, ' ');
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"  this   is  a sentence ",
		" practice   makes   perfect",
	};

	for (auto& t : tests)
	{
		std::cout << "---\ntext: '" << t << "'\nreorderSpaces: '";
		std::cout << Solution().reorderSpaces(t) << "'" << std::endl;
	}
	return 0;
}
