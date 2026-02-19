#include <vector>
#include <iostream>

class Solution
{
public:
	int findKthPositive(std::vector<int>& arr, int k)
	{
		int missingCount = 0;
		int current = 1;
		int index = 0;

		while (true)
		{
			if (index < arr.size() && arr[index] == current)
				index++;
			else
			{
				missingCount++;
				if (missingCount == k)
					return current;
			}
			current++;
		}
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> v;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{2,3,4,7,11}, 5},
		{{1,2,3,4}, 4},
	};

	for (auto& [v, k] : tests)
	{
		std::cout << "---\narr: ";
		printV(v);
		std::cout << ", k: " << k << "\n";
		std::cout << "findKthPositive: " << Solution().findKthPositive(v, k);
		std::cout << std::endl;
	}
	return 0;
}

