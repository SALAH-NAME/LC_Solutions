#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

class Solution
{
public:
	bool wordPattern(std::string pattern, std::string s)
	{
		std::istringstream iss(s);
		std::vector<std::string> words;
		std::string w;

		while (iss >> w)
			words.push_back(w);

		if (words.size() != pattern.size())
			return false;

		std::unordered_map<char, std::string> p2w;
		std::unordered_map<std::string, char> w2p;

		for (int i = 0; i < pattern.size(); ++i)
		{
			char c = pattern[i];
			const std::string& word = words[i];

			if (p2w.count(c) && p2w[c] != word) return false;
			else if (w2p.count(word) && w2p[word] != c) return false;
			else
			{
				p2w[c] = word;
				w2p[word] = c;
			}
		}
		return true;
	}
};
