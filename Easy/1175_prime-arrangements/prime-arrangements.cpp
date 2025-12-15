#include <vector>
#include <iostream>

class Solution
{
	static const int MOD = 1e9 + 7;

	bool isPrime(int x)
	{
		if (x < 2) return false;
		for (int i = 2; i <= std::sqrt(x); ++i)
				if (x % i == 0) return false;
		return true;
	}

	long long factorial(int n)
	{
		long long res = 1;
		for (int i = 2; i <= n; ++i)
			res = (res * i) % MOD;
		return res;
	}

public:
	int numPrimeArrangements(int n)
	{
		int primeCount = 0;
		for (int i = 1; i <= n; ++i)
			if (isPrime(i)) primeCount++;

		int nonPrimeCount = n - primeCount;

		long long result = (factorial(primeCount) * factorial(nonPrimeCount)) % MOD;
		return static_cast<int>(result);
	}
};

int main()
{
	std::vector<int> tests = {
		5,
		100,
	};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\nnumPrimeArrangements: ";
		std::cout << Solution().numPrimeArrangements(n) << std::endl;
	}
	return 0;
}
