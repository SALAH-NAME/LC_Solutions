#include <climits>
#include <vector>

class Solution
{
public:
	int thirdMax(std::vector<int>& nums)
	{
		long max_1 = LONG_MIN;
		long max_2 = LONG_MIN;
		long max_3 = LONG_MIN;

		for (long n : nums)
		{
			if (n > max_1)
			{
				max_3 = max_2;
				max_2 = max_1;
				max_1 = n;
			}
			else if (n > max_2 && n < max_1)
			{
				max_3 = max_2;
				max_2 = n;
			}
			else if (n > max_3 && n < max_2)
				max_3 = n;
		}
		return (max_3 == LONG_MIN ? max_1 : max_3);
	}
};
