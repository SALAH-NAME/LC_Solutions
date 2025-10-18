#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image)
	{
		for (auto& row : image)
			std::reverse(row.begin(), row.end());

		for (auto& row : image)
		{
			for (int i = 0; i < row.size(); i++)
				row[i] = !row[i];
		}
		return image;
	}
};

void printImage(const std::vector<std::vector<std::vector<int>>>& images)
{
	for (const auto& t : images)
	{
		std::cout << "---"<< std::endl;
		std::cout << "[" << std::endl;
		for (int r = 0; r < t.size(); r++)
		{
			std::cout << "[";
			for (int c = 0; c < t[r].size(); c++)
			{
				std::cout << t[r][c];
				if (c + 1 < t[r].size())
					std::cout << ", ";
			}
			 std::cout << "]" << std::endl;
		}
		std::cout << "]" << std::endl;
	}
}

int main()
{
	std::vector<std::vector<std::vector<int>>> tests = {
			{{1,1,0},{1,0,1},{0,0,0}},
			{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}}
		};
	std::cout << "Original :";
	printImage(tests);
	std::cout << "Result :";

	for (auto& t : tests)
		t = Solution().flipAndInvertImage(t);
	printImage(tests);

}
