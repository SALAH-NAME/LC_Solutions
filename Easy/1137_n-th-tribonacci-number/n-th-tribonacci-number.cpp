#include <iostream>
#include <vector>

class Solution
{
public:
	int tribonacci(int n)
	{
		if (n == 0) return 0;
		if (n == 1 || n == 2) return 1;

		int t0 = 0, t1 = 1, t2 = 1;
		int tn = 0;

		for (int i = 3; i <= n; i++)
		{
			tn = t0 + t1 + t2;
			t0 = t1;
			t1 = t2;
			t2 = tn;
		}
		return tn;
	}
};

int main()
{
	Solution sol;
	std::vector<int> tests = {4, 25};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\ntribonacci: ";
		std::cout << sol.tribonacci(n) << std::endl;
	}
	return 0;
}
