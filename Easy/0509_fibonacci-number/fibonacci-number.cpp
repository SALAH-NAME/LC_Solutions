class Solution
{
public:
	int fib(int n)
	{
		if (n <= 1) return n;

		int table[n + 1];
		table[0] = 0, table[1] = 1;
		for (unsigned char i = 2; i <= n; i++)
			table[i] = table[i - 1] + table[i - 2];
		return table[n];
	}
};
