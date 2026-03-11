#include <vector>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
	bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int>>& pieces)
	{
		std::unordered_map<int, std::vector<int>> mp;
		for (auto& piece : pieces)
			mp[piece[0]] = piece;

		int i = 0;
		while (i < arr.size())
		{
			if (mp.find(arr[i]) == mp.end())
					return false;
			auto& piece = mp[arr[i]];
			for (int val : piece)
			{
				if (i >= arr.size() || arr[i] != val)
					return false;
				++i;
			}
		}
		return true;
	}
};

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

typedef struct testCase
{
	std::vector<int> a;
	std::vector<std::vector<int>> p;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{15,88}, {{88},{15}}},
		{{49,18,16}, {{16,18,49}}},
		{{91,4,64,78}, {{78},{4,64},{91}}},
	};

	for (auto& [a, p] : tests)
	{
		std::cout << "---\narr: ";
		printV(a);
		std::cout << ", pieces: ";
		printMat(p);
		std::cout << "\ncanFormArray: ";
		std::cout << (Solution().canFormArray(a, p) ? "True" : "False") << std::endl;
	}
	return 0;
}
