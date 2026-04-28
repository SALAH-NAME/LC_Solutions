#include <vector>
#include <iostream>

class Solution
{
public:
	bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right)
	{
		for (int i = left; i <= right; ++i)
		{
			bool covered = false;
			for (const auto& range : ranges)
			{
				if (i >= range[0] && i <= range[1])
				{
					covered = true;
					break;
				}
			}
			if (!covered) return false;
		}
		return true;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
	{
		printV(m[i]);
		if (i < m.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<std::vector<int>> ranges;
	int l;
	int r;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{{1,2},{3,4},{5,6}}, 2, 5},
		{{{1,10},{10,20}}, 21, 21},
	};

	for (auto& [ranges, l, r] : tests)
	{
		std::cout << "---\nranges: ";
		printMat(ranges);
		std::cout << ", left: " << l << ", right: " << r << "\nisCovered: ";
		std::cout << (Solution().isCovered(ranges, l, r) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
