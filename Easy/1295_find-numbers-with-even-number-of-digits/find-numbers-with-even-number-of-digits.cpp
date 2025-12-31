#include <iostream>
#include <vector>

class Solution
{
public:
	int findNumbers(std::vector<int>& nums)
	{
		int count = 0;

		for (int n : nums)
		{
			int digits = 0;
			while (n > 0)
			{
				n /= 10;
				digits++;
			}
			if (digits % 2 == 0)
				count++;
		}
		return count;
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
		{12,345,2,6,7896},
		{555,901,482,1771},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nfindNumbers: " << Solution().findNumbers(nums);
		std::cout << std::endl;
	}
	return 0;
}
