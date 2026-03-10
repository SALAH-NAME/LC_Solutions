#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
	int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points)
	{
		std::vector<int> xs;
		for (auto& p : points)
			xs.push_back(p[0]);

		std::sort(xs.begin(), xs.end());

		int maxGap = 0;
		for (int i = 1; i < xs.size(); ++i)
			maxGap = std::max(maxGap, xs[i] - xs[i - 1]);
		return maxGap;
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

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
		{{8,7},{9,9},{7,4},{9,7}},
		{{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}},
	};

	for (auto& p : tests)
	{
		std::cout << "---\npoints: ";
		printMat(p);
		std::cout << "\nmaxWidthOfVerticalArea: ";
		std::cout << Solution().maxWidthOfVerticalArea(p) << std::endl;
	}
	return 0;
}
