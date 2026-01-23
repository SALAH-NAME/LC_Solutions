#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
private:
	int digitSum(int x)
	{
		int sum = 0;
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}

public:
	int countLargestGroup(int n)
	{
		std::unordered_map<int, int> freq;

		for (int i = 1; i <= n; ++i)
		{
			int sum = digitSum(i);
			freq[sum]++;
		}

		int maxSize = 0;
		for (auto& [sum, count] : freq)
		{
			if (count > maxSize)
				maxSize = count;
		}

		int result = 0;
		for (auto& [sum, count] : freq)
		{
			if (count == maxSize)
				result++;
		}
		return result;
	}
};

int main()
{
	std::vector<int> tests = {
		13,
		2,
	};

	for (auto& n : tests)
	{
		std::cout << "---\nn: " << n << "\ncountLargestGroup: ";
		std::cout << Solution().countLargestGroup(n) << std::endl;
	}
	return 0;
}
