#include <iostream>
#include <vector>

class Solution
{
public:
	bool lemonadeChange(std::vector<int>& bills)
	{
		int five = 0, ten = 0;

		for (int bill : bills)
		{
			if (bill == 5)
				five++;
			else if (bill == 10)
			{
				if (five == 0) return false;
				five--;
				ten++;
			}
			else
			{
				if (ten > 0 && five > 0)
				{
					ten--;
					five--;
				}
				else if (five >= 3)
					five -= 3;
				else
					return false;
			}
		}
		return true;
	}
};

template <typename T>
void printVector(const std::vector<T>& vec)
{
	std::cout << "{";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i != vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{5,5,5,10,20},
			{5,5,10,10,20},
			{10,5},
		};

	for (auto& bills : tests)
	{
		std::cout << "---\nbills: ";
		printVector(bills);
		std::cout << " => change: " << (Solution().lemonadeChange(bills) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
