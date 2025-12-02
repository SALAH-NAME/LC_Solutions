#include <iostream>
#include <queue>
#include <vector>

class Solution
{
public:
	int lastStoneWeight(std::vector<int>& stones)
	{
		std::priority_queue<int> pq(stones.begin(), stones.end());

		while (pq.size() > 1)
		{
			int y = pq.top(); pq.pop();
			int x = pq.top(); pq.pop();
			if (y != x)
				pq.push(y - x);
		}
		return pq.empty() ? 0 : pq.top();
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
			{2,7,4,1,8,1},
			{1},
		};

	for (auto& s : tests)
	{
		std::cout << "---\nstones: ";
		printVector(s);
		std::cout << "\nlastStoneWeight: " << Solution().lastStoneWeight(s);
		std::cout << std::endl;
	}
	return 0;
}
