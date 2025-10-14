#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class Solution
{
public:
	std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned)
	{
		std::unordered_set<std::string> banSet(banned.begin(), banned.end());
		std::unordered_map<std::string, int> freq;

		for (int i = 0; i < paragraph.size(); ++i)
		{
			std::string buffer;
			while (i < paragraph.size() && !std::isalpha(paragraph[i]))
				i++;
			while (std::isalpha(paragraph[i]))
				buffer += std::tolower(paragraph[i++]);
			if (!buffer.empty() && !banSet.count(buffer))
				freq[buffer]++;
		}

		int max = 0;
		std::string maxKey;
		for (const auto& [word, count] : freq)
		{
			if (count > max)
			{
				max = count;
				maxKey = word;
			}
		}
		return maxKey;
	}
};
