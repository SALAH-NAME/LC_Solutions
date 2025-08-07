
class Solution
{
public:
	int findComplement(int num)
	{
		int mask = 0;
		for (unsigned char i = 0; i < 32 && (num >> i) > 0; i++)
			mask++;
		mask = (1L << mask) - 1;
		return mask ^ num;
	}
};
