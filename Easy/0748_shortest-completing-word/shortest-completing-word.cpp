#include <cctype>
#include <climits>
#include <string>
#include <vector>

class Solution
{
public:
	std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string>& words)
	{
		std::vector<int> plate(26, 0);
		for (char c : licensePlate)
			if (std::isalpha(c))
				plate[std::tolower(c) - 'a']++;

		std::string result;
		int sl = INT_MAX;

		for (auto& w : words)
		{
			std::vector<int> freq(26, 0);
			for (char c : w)
				freq[c - 'a']++;

			bool valid = true;
			for (int i = 0; i < 26; ++i)
			{
				if (plate[i] > freq[i])
				{
					valid = false;
					break;
				}
			}

			if (valid && w.size() < sl)
			{
				sl = w.size();
				result = w;
			}
		}
		return result;
	}
};
