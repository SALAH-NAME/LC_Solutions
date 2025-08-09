#include <vector>

class Solution
{
public:
	int findMaxConsecutiveOnes(std::vector<int>& nums)
	{
		int count = 0;
		int max = 0;
		
		for (int n : nums)
		{
			if (n == 0) count = 0;
			else 
			{
				if (count >= max) max++;
				count++;
			}
		}
		return max;
	}
};
