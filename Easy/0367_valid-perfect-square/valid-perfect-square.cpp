class Solution
{
public:
	bool isPerfectSquare(int num)
	{
		int n = 0;
		for (int i = 0; i <= num / i; ++i)
			if (i * i == num)
				return true;
		return false;
	}
};
