#include <algorithm>
#include <vector>

class Solution
{
public:
	int maxCount(int m, int n, std::vector<std::vector<int>>& ops)
	{
		for (auto& op: ops)
		{
			m = std::min(m, op[0]);
			n = std::min(n, op[1]);
		}
		return m * n;
	}
};
