#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
	int getMinDistance(std::vector<int>& nums, int target, int start)
	{
		int min_dist = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				int current_dist = std::abs(i - start);
				if (current_dist < min_dist)
				{
					min_dist = current_dist;
				}
			}
		}
		return min_dist;
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

typedef struct testCase
{
	std::vector<int> n;
	int t;
	int s;
}  testCase;

int main()
{
	std::vector<testCase> tests = {
		{{1,2,3,4,5}, 5, 3},
		{{1}, 1, 0},
		{{1,1,1,1,1,1,1,1,1,1}, 1, 0},
	};

	for (auto& [n, t, s] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << ", target: " << t << ", start: " << s << "\ngetMinDistance: ";
		std::cout << Solution().getMinDistance(n, t, s) << std::endl;
	}
	return 0;
}
