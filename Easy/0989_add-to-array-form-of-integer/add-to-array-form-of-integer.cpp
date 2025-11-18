#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> addToArrayForm(std::vector<int>& num, int k)
	{
		int n = num.size();
		int i = n - 1;

		std::vector<int> result;

		while (i >= 0 || k > 0)
		{
			if (i >= 0)
			{
				k += num[i];
				i--;
			}
			result.push_back(k % 10);
			k /= 10;
		}
		std::reverse(result.begin(), result.end());
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

typedef struct testCase
{
	std::vector<int> num;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{{1, 2, 0, 0}, 34},
			{{2,7,4}, 181},
			{{2,1,5}, 806},
		};

	for (auto& [num, k] : tests)
	{
		std::cout << "---\nnum: ";
		printVector(num);
		std::cout << ", k: " << k;
		std::cout << "\naddToArrayForm: ";
		num = Solution().addToArrayForm(num, k);
		printVector(num);
		std::cout << std::endl;
	}
}
