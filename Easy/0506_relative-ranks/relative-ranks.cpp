#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> findRelativeRanks(std::vector<int>& score)
	{
		short n = score.size();
		std::vector<std::pair<int, int>> arr;
		arr.reserve(n);

		for (short i = 0; i < n; ++i)
			arr.push_back({score[i], i});

		std::sort(arr.begin(), arr.end(), std::greater<std::pair<int,int>>());

		std::vector<std::string> result(n);

		for (short i = 0; i < n; ++i)
		{
			if (i == 0) result[arr[i].second] = "Gold Medal";
			else if (i == 1) result[arr[i].second] = "Silver Medal";
			else if (i == 2) result[arr[i].second] = "Bronze Medal";
			else result[arr[i].second] = std::to_string(i + 1);
		}

		return result;
	}
};

