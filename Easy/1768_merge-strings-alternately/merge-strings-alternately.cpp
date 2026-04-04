#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string mergeAlternately(std::string word1, std::string word2)
	{
		std::string result;
		int i = 0;
		int j = 0;

		while (i < word1.size() || j < word2.size())
		{
			if (i < word1.size())
				result.push_back(word1[i++]);
			if (j < word2.size())
				result.push_back(word2[j++]);
		}
		return result;
	}
};

typedef struct testCase
{
	std::string w1;
	std::string w2;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"abc", "pqr"},
		{"ab", "pqrs"},
		{"abcd", "pq"},
	};

	for (auto& [w1, w2] : tests)
	{
		std::cout << "---\nword1: '" << w1 << "', w2: '" << w2 << "'\n";
		std::cout << "mergeAlternately: '";
		std::cout << Solution().mergeAlternately(w1, w2) << "'" << std::endl;
	}
	return 0;
}
