#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution
{
public:
	bool buddyStrings(std::string s, std::string goal)
	{
		if (s.size() != goal.size())
			return false;

		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				std::swap(s[i], s[j]);
				if (s == goal)
					return true;
				std::swap(s[i], s[j]);
			}
		}
		return false;
	}
};

bool buddyStrings(std::string s, std::string goal)
{
	if (s.size() != goal.size()) return false;

	if (s == goal)
	{
		int freq[26] = {0};
		for (char c : s)
			if (++freq[c - 'a'] > 1) return true;
		return false;
	}

	std::vector<int> diff;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != goal[i]) diff.push_back(i);

	return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
}

typedef struct testCase
{
	std::string s;
	std::string g;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"ab", "ba"},
		{"ab", "ab"},
		{"aa", "aa"},
	};

	for (auto& tc : tests)
	{
		std::cout << "---\ns='" << tc.s << "' goal='" << tc.g << "' => ";
		std::cout << (Solution().buddyStrings(tc.s, tc.g) ? "True" : "False") << std::endl;
	}
	return 0;
}
