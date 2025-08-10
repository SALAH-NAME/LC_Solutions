#include <cmath>
#include <vector>

class Solution
{
public:
	std::vector<int> constructRectangle(int area)
	{
		int l;
		int w = std::sqrt(area);

		while (w > 0)
		{
			l = area / w;
			if (l * w == area)
				return {l, w};
			w--;
		}
		return {area, 1};
	}
};
