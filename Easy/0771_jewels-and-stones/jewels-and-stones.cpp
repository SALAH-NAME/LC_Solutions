#include <string>

class Solution
{
public:
	int numJewelsInStones(std::string jewels, std::string stones)
	{
		int freq[127] = {0};

		for (char s : stones)
			freq[s]++;

		int count = 0;
		for (char j : jewels)
			count += freq[j];
		return count;
	}
};
