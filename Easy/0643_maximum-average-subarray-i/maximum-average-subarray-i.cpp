#include <cfloat>
#include <vector>

class Solution
{
public:
	double findMaxAverage(std::vector<int>& nums, int k)
	{
		double windowSum = 0;
		for (int i = 0; i < k; ++i)
			windowSum += nums[i];

		double maxAvg = windowSum;

		for (int i = k; i < nums.size(); ++i)
		{
			windowSum += nums[i] - nums[i - k];
			if (windowSum > maxAvg)
				maxAvg = windowSum;
		}
		return maxAvg / k;
	}
};
