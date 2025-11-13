#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
private:
	bool compare(std::string& w1, const std::string& w2, std::unordered_map<char, int>& rank)
	{
		int n = std::min(w1.size(), w2.size());
		for (int i = 0; i < n; i++)
		{
			if (rank[w1[i]] < rank[w2[i]])
				return true;
			else if (rank[w1[i]] > rank[w2[i]])
				return false;
		}
		return w1.size() <= w2.size();
	}

public:
	bool isAlienSorted(std::vector<std::string>& words, std::string order)
	{
		std::unordered_map<char, int> rank(26);

		for (int i = 0; i < order.size(); i++)
			rank[order[i]] = i;

		for (int i = 0; i < words.size() - 1; i++)
		{
			if (!compare(words[i], words[i + 1], rank))
				return false;
		}
		return true;
	
};

void printVecotr(const std::vector<std::string>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase {
	std::vector<std::string> words;
	std::string order;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{{"hello","leetcode"}, "hlabcdefgijkmnopqrstuvwxyz"},
			{{"word","world","row"}, "worldabcefghijkmnpqstuvxyz"},
			{{"apple","app"}, "abcdefghijklmnopqrstuvwxyz"},
			{{"app","apple"}, "abcdefghijklmnopqrstuvwxyz"},
			{{"appz","apple"}, "abcdefghijklmnopqrstuvwxyz"},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\nwods: ";
		printVecotr(tc.words);
		std::cout << "\norder: '" << tc.order << "'\nisAlienSorted: ";
		std::cout << (Solution().isAlienSorted(tc.words, tc.order) ? "True" : "False");
		std::cout << std::endl;
	}
}
