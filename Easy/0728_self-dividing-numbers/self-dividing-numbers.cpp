#include <vector>

class Solution
{
private:
	bool isSelfDeviding(int n)
	{
		short b = n;
		short res = 0;
		while (b)
		{
			res = b % 10;
			if (res == 0 || n % res != 0)
				return false;
			b /= 10;
		}
		return true;
	}

public:
	std::vector<int> selfDividingNumbers(int left, int right)
	{
		std::vector<int> result;

		for (short i = left; i <= right; ++i)
			if (isSelfDeviding(i))
				result.push_back(i);

		return result;
	}
};
