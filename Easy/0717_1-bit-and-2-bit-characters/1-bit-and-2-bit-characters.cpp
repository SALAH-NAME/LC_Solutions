#include <vector>

class Solution
{
public:
	bool isOneBitCharacter(std::vector<int>& bits)
	{
		short last = 0;
		short i = 0;
		while (i < bits.size())
		{
			if (bits[i] == 0)
			{
				last = 1;
				i++;
			}
			else
			{
				i += 2;
				last = 2;
			}
		}
		return last == 1;
	}
};
