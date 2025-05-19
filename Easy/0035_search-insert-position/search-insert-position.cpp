#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>


int searchInsert(std::vector<int>& nums, int target)
{
	int low =0, high = nums.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target)
	{
		std::size_t pos = 0;
		std::vector<int> half(nums.begin(), nums.end());

		while (true)
		{
			std::size_t mid = half.size() / 2;
			if (target <= half[mid])
			{
				half = std::vector<int>(half.begin(), half.begin() + mid);
			}
			else
			{
				half = std::vector<int>(half.begin() + mid, half.end());
				pos += mid;
			}
			if (mid == 0)
				break;
		}
		if (!half.empty() && half[0] < target)
			pos++;
		
		return pos;
	}
};


void printVector(const std::vector<int>& vec, bool line = true)
{
	for (const int& num : vec)
		std::cout << num << " ";
	if (line)
		std::cout << std::endl;
}

int main()
{
	std::vector<std::pair<std::vector<int>, int>> tests = {
		{{1, 3, 5, 6}, 5},
		{{1,3,5,6}, 2},
		{{1,3,5,6}, 7},
		{{1}, 5},
		{{1,6}, 5},
		{{7,9}, 5},
		{{9}, 5}
	};


	for (auto& test : tests)
	{
		Solution sol;
		int value = test.second;
		std::vector<int>& vec = test.first;
		
		std::cout << "Value: " << value << " | ";
		std::cout << "Vector: ";
		printVector(vec, false);
		std::cout << " -_=> " << sol.searchInsert(vec, value) << std::endl << std::endl;
		
	}
	return 0;
}
