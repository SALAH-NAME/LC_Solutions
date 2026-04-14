#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution 
{
public:
	std::string truncateSentence(std::string s, int k)
	{
		std::istringstream iss(s);
		std::string word;
		std::string result;
		int count = 0;

		while (iss >> word)
		{
			if (count == k) break;
			if (!result.empty()) result += " ";
			result += word;
			++count;
		}

		return result;
	}
};

typedef struct testCase
{
	std::string s;
	int k;
} testCase;

int main() {
	std::vector<testCase> tests = {
		{"Hello world this is Copilot", 2},
		{"The quick brown fox jumps over the lazy dog", 4},
		{"Coding in C++ is fun", 3},
		{"SingleWord", 1},
		{"Multiple words but only two", 2}
	};

	for (auto& [s, k] : tests)
	{
		std::cout << "---\ninput: '" << s << "', k=" << k << "\n";
		std::cout << "truncateSentence: ";
		std::cout << Solution().truncateSentence(s, k) << std::endl;
	}

	return 0;
}

