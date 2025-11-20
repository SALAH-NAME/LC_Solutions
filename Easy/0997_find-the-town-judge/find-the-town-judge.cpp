#include <iostream>
#include <vector>

class Solution
{
public:
	int findJudge(int n, std::vector<std::vector<int>>& trust)
	{
		std::vector<int> score(n+1, 0);

		for (auto& p : trust)
		{
			score[p[0]]--;
			score[p[1]]++;
		}

		for (int i = 1; i <= n; i++)
		{
			if (score[i] == n - 1)
				return i;
		}
		return -1;
	}
};


void printMat(const std::vector<std::vector<int>>& mat)
{
	std::cout << "{";
	for (int i = 0; i < mat.size(); i++)
	{
		std::cout << "{";
		for (int j = 0; j < mat[i].size(); j++)
		{
		 	std::cout << mat[i][j];
			if (j < mat[i].size() - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		if (i < mat.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}
 
typedef struct testCase {
	int n;
	std::vector<std::vector<int>> trust;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{2, {{1,2}}},
		{3, {{1,3}, {2,3}}},
		{3, {{1,3}, {2,3}, {3, 1}}},
		{3, {{1,2}, {3,2}}},
		{3, {{1,3}, {2,3}, {3,2}}},
	};

	for (auto& [n, trust] : tests)
	{
		std::cout << "---\nN: " << n << ", trust: ";
		printMat(trust);
		std::cout << "\nfindJudge: " << Solution().findJudge(n, trust);
		std::cout << std::endl;
	}
	return 0;
}
