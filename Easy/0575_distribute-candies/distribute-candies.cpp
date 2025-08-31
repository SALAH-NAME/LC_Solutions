#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
	int distributeCandies(std::vector<int>& candyType)
	{
		unsigned short n = candyType.size() / 2;
		unsigned short count = 0;
		int prev = INT_MIN;
    std::sort(candyType.begin(), candyType.end());
		for (int type : candyType)
		{
			if (type != prev)
			{
				prev = type;
				count++;
				if (--n <= 0) break;
			}
		}
		return count;
	}
};


/*class Solution*/
/*{*/
/*public:*/
/*	int distributeCandies(std::vector<int>& candyType)*/
/*	{*/
/*		std::unordered_set<int> uniqueTypes(candyType.begin(), candyType.end());*/
/*		return std::min(static_cast<int>(uniqueTypes.size()), static_cast<int>(candyType.size())/2);*/
/*	}*/
/*};*/
