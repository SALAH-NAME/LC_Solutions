#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::vector<std::string> stringMatching(std::vector<std::string>& words)
	{
		std::vector<std::string> res;
		for (size_t i = 0; i < words.size(); ++i)
		{
			for (size_t j = 0; j < words.size(); ++j)
			{
				if (i == j) continue;
				if (words[j].find(words[i]) != std::string::npos)
				{
					res.push_back(words[i]);
					break ;
				}
			}
		}
		return res;
	}
};

void printV(const std::vector<std::string>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::string>> tests = {
		{"mass","as","hero","superhero"},
		{"leetcode","et","code"},
		{"blue","green","bu"},
	};

	for (auto& words : tests)
	{
		std::cout << "---\nwords: ";
		printV(words);
		std::cout << "\nstringMatching: ";
		printV(Solution().stringMatching(words));
		std::cout << std::endl;
	}
	return 0;
}
