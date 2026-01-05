#include <vector>
#include <iostream>

class Solution
{
public:
	bool hasZero(int x)
	{
		while (x > 0)
		{
			if (x % 10 == 0)
				return true;
			x /= 10;
		}
		return false;
	}
	std::vector<int> getNoZeroIntegers(int n)
	{
		for (int i = 1; i < n; i++)
		{
			int b = n - i;
			if (!hasZero(i) && !hasZero(b))
				return {i, b};
		}
		return {};
  }
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<int> tests = {
		2,
		11,
	};

	for (int n : tests)
	{
		std::cout << "---\nn: " << n << "\ngetNoZeroIntegers: ";
		printV(Solution().getNoZeroIntegers(n));
		std::cout << std::endl;
	}
	return 0;
}
