#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> sortedSquares(std::vector<int>& nums)
	{
		int n = nums.size();
		std::vector<int> reslut(n);
		int left = 0, right = n - 1;
		int pos = n - 1;

		while (left <= right)
		{
			int leftSquare = nums[left] * nums[left];
			int rightSquare = nums[right] * nums[right];

			if (leftSquare > rightSquare)
			{
				reslut[pos--] = leftSquare;
				left++;
			}
			else
			{
				reslut[pos--] = rightSquare;
				right--;
			}
		}
		return reslut;
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
			{-4,-1,0,3,10},
			{-7,-3,2,3,11},
		};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printVector(nums);
		std::cout << "\nsortedSquares: ";
		std::vector<int> squares = Solution().sortedSquares(nums);
		printVector(squares);
		std::cout << std::endl;
	}
}
