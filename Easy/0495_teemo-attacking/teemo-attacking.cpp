#include <algorithm>
#include <vector>

class Solution
{
public:
	int findPoisonedDuration(std::vector<int>& timeSeries, int duration)
	{
		if (duration == 0) return 0;
		int res = duration;
		short n = timeSeries.size();
		for (short i = 1; i < n; ++i)
			res += std::min(duration, timeSeries[i] - timeSeries[i - 1]);
		return res;
	}
};
