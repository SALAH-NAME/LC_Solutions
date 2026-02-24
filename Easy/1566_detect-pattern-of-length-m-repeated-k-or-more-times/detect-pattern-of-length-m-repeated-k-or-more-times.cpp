#include <vector>
#include <iostream>

class Solution
{
public:
	bool containsPattern(std::vector<int>& arr, int m, int k)
	{
		int n = arr.size();
		for (int i = 0; i + m * k <= n; i++)
		{
			bool valid = true;
			for (int j = 0; j < m; j++)
			{
				for (int t = 1; t < k; t++)
				{
					if (arr[i + j] != arr[i + j + t * m])
					{
						valid = false;
						break;
					}
				}
				if (!valid) break;
			}
			if (valid) return true;
		}
		return false;
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
  std::vector<int> a;
	int m;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{1,2,4,4,4,4}, 1, 3},
		{{1,2,1,2,1,1,1,3}, 2, 2},
		{{1,2,1,2,1,3}, 2, 3},
	};

	for (auto& [a, m, k] : tests)
	{
		std::cout << "---\narr: ";
		printV(a);
		std::cout << ", m: " << m << ", k: " << k << "\ncontainsPattern: ";
		std::cout << (Solution().containsPattern(a, m, k) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
