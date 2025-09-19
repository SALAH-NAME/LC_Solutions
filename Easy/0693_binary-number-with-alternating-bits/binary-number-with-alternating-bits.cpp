class Solution
{
public:
	bool hasAlternatingBits(int n)
	{
		unsigned char prev = n & 1;
		n >>= 1;
		while (n > 0)
		{
			unsigned char curr = n & 1;
			if (curr == prev) return false;
			prev = curr;
			n >>= 1;
		}
		return true;
	}
};
