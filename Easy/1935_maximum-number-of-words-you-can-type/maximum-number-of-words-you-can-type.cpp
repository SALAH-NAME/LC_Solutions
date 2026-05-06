#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	int canBeTypedWords(std::string text, std::string brokenLetters)
	{
		bool isBroken[26] = {false};
		for (char c : brokenLetters)
		{
			isBroken[c - 'a'] = true;
		}

		int count = 0;
		std::stringstream ss(text);
		std::string word;
		while (ss >> word)
		{
			bool canType = true;
			for (char c : word)
			{
				if (isBroken[c - 'a'])
				{
					canType = false;
					break;
				}
			}
			if (canType)
			{
				count++;
			}
		}

		return count; 
	}
};

typedef struct testCase
{
	std::string t;
	std::string b;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"hello world", "ad"},
		{"leet code", "lt"},
		{"leet code", "e"},
	};

	for (auto& [t, b] : tests)
	{
		std::cout << "---\ntext: '" << t << "', brokenLetters: '" << b << "'\n";
		std::cout << "canBeTypedWords: " << Solution().canBeTypedWords(t, b);
		std::cout << std::endl;
	}
	return 0;
}
