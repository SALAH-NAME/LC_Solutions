#include <climits>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	int majorityElement(std::vector<int>& nums)
	{
		std::unordered_map<int, int> data;

		for (int num : nums)
			data[num] += 1;

		int maxValue = INT_MIN;
		int keyValue;
		for (const auto& pair : data)
		{
			if (pair.second > maxValue)
			{
				maxValue = pair.second;
				keyValue = pair.first;
			}
		}
		return keyValue;
	}
};
