class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int n = x ^ y;
		unsigned char res = 0;
		for (unsigned char i = 0; i < 32; ++i)
			res += (n >> i) & 0x1;
		return res;
	}
};
