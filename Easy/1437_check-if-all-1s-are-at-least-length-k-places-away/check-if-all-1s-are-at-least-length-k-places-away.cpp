#include <vector>
#include <iostream>

class Solution
{
public:
	bool kLengthApart(std::vector<int>& nums, int k)
	{
		int prev = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				if (prev != -1 && i - prev - 1 < k)
					return false;
				prev = i;
			}
		}
		return true;
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

typedef struct testCase {
	std::vector<int> n;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{1,0,0,0,1,0,0,1}, 2},
		{{1,0,0,1,0,1}, 2},
	};

	for (auto& [n, k] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << ", k: " << k << "\nkLengthApart: ";
		std::cout << (Solution().kLengthApart(n, k) ? "True" : "False") << std::endl;
	}
	return 0;
}
