#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	int findShortestSubArray(std::vector<int>& nums)
	{
		struct Info {
			int count = 0;
			int first = -1;
			int last = -1;
		};
		std::unordered_map<int, Info> m;
		int n = nums.size();

		for (int i = 0; i < n; ++i)
		{
			int x = nums[i];
			auto &info = m[x];
			if (info.count == 0) info.first = i;
			info.last = i;
			++info.count;
		}

		int degree = 0;
		for (const auto &p : m) degree = std::max(degree, p.second.count);

		int shortLen = n;
		for (const auto &p : m)
		{
			if (p.second.count == degree)
				shortLen = std::min(shortLen, p.second.last - p.second.first + 1);
		}
		return shortLen;
	}
};
