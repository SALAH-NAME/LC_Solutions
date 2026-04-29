#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	bool makeEqual(std::vector<std::string>& words)
	{
		int n = words.size();
		if (n <= 1) return true;

		int counts[26] = {0};
		for (const std::string& word : words)
		{
			for (char c : word)
			{
				counts[c - 'a']++;
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			if (counts[i] % n != 0)
			{
				return false;
			}
		}
		return true;
	}
};

void printV(const std::vector<std::string>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<std::string> w;
}	testCase;

int main()
{
	std::vector<testCase> tests = {
		{{"abc","aabc","bc"}},
		{{"ab","a"}},
	};

	for (auto& [words] : tests)
	{
		std::cout << "---\nwords: ";
		printV(words);
		std::cout << "\nmakeEqual: ";
		std::cout << (Solution().makeEqual(words) ? "True" : "False") << std::endl;
	}
	return 0;
}
