#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
	int countCharacters(std::vector<std::string>& words, std::string chars)
	{
		std::vector<int> charCount(26, 0);
		for (char ch : chars)
			charCount[ch - 'a']++;

		int totalLength = 0;
		for (auto& word : words)
		{
			std::vector<int> wordCount(26, 0);
			for (char ch : word)
				wordCount[ch - 'a']++;

			bool canForm = true;
			for (int i = 0; i < 26; i++)
			{
				if (wordCount[i] > charCount[i])
				{
					canForm = false;
					break;
				}
			}
			if (canForm)
				totalLength += word.size();
		}
		return totalLength;
	}
};

typedef struct testCase
{
	std::vector<std::string> w;
	std::string c;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{"cat","bt","hat","tree"}, "atach"},
		{{"hello","world","leetcode"}, "welldonehoneyr"},
	};

	for (auto& [w, c] : tests)
	{
		std::cout << "---\nwords: {";
		for (auto& s : w)
			std::cout << "'" << s << "' ";
		std::cout << "}  chars: '" << c << "'\ncountCharacters: ";
		std::cout << Solution().countCharacters(w, c) << std::endl;
	}
	return 0;
}
