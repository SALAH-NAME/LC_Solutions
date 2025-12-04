#include <iostream>
#include <vector>

class Solution
{
public:
	int heightChecker(std::vector<int>& heights)
	{
		std::vector<int> count(101, 0);
		for (int h : heights)
			count[h]++;

		int result = 0;
		int currHeight = 1;
		for (int i = 0; i < heights.size(); i++)
		{
			while (count[currHeight] == 0)
				currHeight++;
			if (heights[i] != currHeight)
				result++;
			count[currHeight]--;
		}
		return result;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{1,1,4,2,1,3},
			{5,1,2,3,4},
			{1,2,3,4,5},
		};

	for (auto& heights : tests)
	{
		std::cout << "---\nheights: ";
		printVector(heights);
		std::cout << "\nheightChecker: " << Solution().heightChecker(heights);
		std::cout << std::endl;
	}
	return 0;
}
