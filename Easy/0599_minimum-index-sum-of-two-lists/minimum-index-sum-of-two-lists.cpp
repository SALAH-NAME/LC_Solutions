#include <climits>
#include <unordered_map>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2)
	{
		std::unordered_map<std::string, short> indexMap;
		indexMap.reserve(list2.size());
		for (short i = 0; i < list2.size(); ++i)
			indexMap[list2[i]] = i;

		std::vector<std::string> result;

		short minSum = SHRT_MAX;

		for (short i = 0; i < list1.size(); i++)
		{
			if (indexMap.count(list1[i]))
			{
				short sum = i + indexMap[list1[i]];
				if (sum < minSum)
				{
					result.clear();
					result.push_back(list1[i]);
					minSum = sum;
				}
				else if ( sum == minSum )
					result.push_back(list1[i]);
			}
		}
		return result;
	}
};
