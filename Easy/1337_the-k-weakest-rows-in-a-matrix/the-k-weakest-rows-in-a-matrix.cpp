#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

class Solution
{
public:
	std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k)
	{
		std::vector<std::pair<int, int>> strength;

		for (int i = 0; i < mat.size(); i++)
		{
			int soldiers = std::count(mat[i].begin(), mat[i].end(), 1);
			strength.push_back({soldiers, i});
		}

		std::sort(
			strength.begin(), strength.end(),
			[](const auto& a, const auto& b) {
				if (a.first == b.first) return a.second < b.second;
				return a.first < b.first;
			}
		);

		std::vector<int> result;
		for (int i = 0; i < k; ++i)
			result.push_back(strength[i].second);
		return result;
	}
};

typedef struct testCase {
	std::vector<std::vector<int>> m;
	int k;
} testCase;

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
	std::vector<testCase> tests = {
		{{{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}}, 3},
		{{{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}}, 2},
	};

	for (auto& [mat, k] : tests)
	{
		std::cout << "---\nmat:";
		printMat(mat);
		std::cout << ", k: " << k << "\nkWeakestRows: ";
		printV(Solution().kWeakestRows(mat, k));
		std::cout << std::endl;
	}
	return 0;
}
