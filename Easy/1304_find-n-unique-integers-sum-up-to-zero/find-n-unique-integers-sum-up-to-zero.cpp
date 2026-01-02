#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> sumZero(int n)
	{
		std::vector<int> res;
		res.reserve(n);
		if (n % 2 == 1)
			res.push_back(0);

		for (int i = 1; i <= n / 2; ++i)
		{
			res.push_back(-i);
			res.push_back(i);
		}
		return res;
	}
};

int main()
{
	std::vector<int> tests = {
		5,
		3,
		1,
	};

	for (auto& n : tests)
	{
		std::cout << "---\nn: " << n << "\nsumZero: ";
		std::vector<int> res = Solution().sumZero(n);
		std::cout << "{";
		for (int i = 0; i < res.size(); i++)
		{
			std::cout << res[i];
			if (i < res.size() - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		std::cout << std::endl;
	}
	return 0;
}
