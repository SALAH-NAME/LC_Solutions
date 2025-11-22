#include <climits>
#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> commonChars(std::vector<std::string>& words)
	{
		std::vector<int> minFreq(26, INT_MAX);
		for (auto& w : words)
		{
			std::vector<int> freq(26,0);
			for (char c : w)
				freq[c - 'a']++;
			for (int i = 0; i < 26; i++)
				minFreq[i] = std::min(minFreq[i], freq[i]);
		}

		std::vector<std::string> result;
		for (int i = 0; i < 26; i++)
		{
			for (int count = 0; count < minFreq[i]; count ++)
					result.push_back(std::string(1,i + 'a'));
		}
		return result;
	}
};

void printWords(const std::vector<std::string>& vec)
{
	std::cout << "[";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "'" << vec[i] << "'";
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
}

int main()
{
	std::vector<std::vector<std::string>> tests = {
			{"bella","label","roller"},
			{"cool","lock","cook"},
		};

	for (auto& words : tests)
	{
		std::cout << "---\nwords: ";
		printWords(words);
		auto result = Solution().commonChars(words);
		std::cout << "\nresult: ";
		printWords(result);
		std::cout << std::endl;
	}
	return 0;
}
