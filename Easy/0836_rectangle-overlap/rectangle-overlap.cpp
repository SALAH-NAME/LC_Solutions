#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
public:
	bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2)
	{
		return !(
			rec1[1] >= rec2[3] ||
			rec2[1] >= rec1[3] ||
			rec1[0] >= rec2[2] ||
			rec2[0] >= rec1[2]
		);
	}
};

typedef struct testCase
{
		std::vector<int> rec1;
		std::vector<int> rec2;
} testCase;

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
	std::vector<testCase> tests = {
			{{0,0,2,2}, {1,1,3,3}},
			{{0,0,1,1}, {1,0,2,1}},
			{{0,0,1,1}, {2,2,3,3}},
			{{-6,-10,9,2}, {0,5,4,8}},
		};

	for (auto& t : tests) {
		std::cout << "{";
		printVector(t.rec1);
		std::cout << ", ";
		printVector(t.rec1);
		std::cout << "}";
		std::cout << " => Overlap: " << (Solution().isRectangleOverlap(t.rec1, t.rec2) ? "True" : "False");
		std::cout << std::endl;
	}

	return 0;
}
