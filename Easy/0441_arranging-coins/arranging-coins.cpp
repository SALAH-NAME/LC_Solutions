
#include <cmath>
class Solution
{
public:
	int arrangeCoins(int n)
	{
		long double d = std::sqrt(static_cast<long double>(1) + 8.0L * n);
		long long k = static_cast<long long>((d - 1) / 2);
		return static_cast<int>(k);
	}
};
