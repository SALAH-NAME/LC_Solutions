#include <iostream>
#include <vector>

class Solution
{
public:
	bool threeConsecutiveOdds(std::vector<int>& arr)
	{
		int count = 0;
		for (int num : arr)
		{
			if (num % 2 == 1)
			{
				count++;
				if (count == 3) return true;
			}
			else
				count = 0;
		}
		return false;
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
	std::vector<std::vector<int>>	 tests = {
		{2,6,4,1},
		{1,2,34,3,4,5,7,23,12},
	};

	for (auto& a : tests)
	{
		std::cout << "---\narr: ";
		printV(a);
		std::cout << "\nthreeConsecutiveOdds: ";
		std::cout << (Solution().threeConsecutiveOdds(a) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
