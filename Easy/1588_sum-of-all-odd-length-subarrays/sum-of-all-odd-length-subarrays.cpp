#include <vector>
#include <iostream>

class Solution
{
public:
	int sumOddLengthSubarrays(std::vector<int>& arr)
	{
		int n = arr.size();
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int total = (i + 1) * (n - i);
			int oddCount = (total + 1) / 2;
			sum += arr[i] * oddCount;
		}
		return sum;
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
	std::vector<std::vector<int>> tests = {
		{1,4,2,5,3},
		{1,2},
		{10,11,12},
	};

	for (auto& a : tests)
	{
		std::cout << "---\narr: ";
		printV(a);
		std::cout << "\nsumOddLengthSubarrays: ";
		std::cout << Solution().sumOddLengthSubarrays(a) << std::endl;
	}
	return 0;
}
