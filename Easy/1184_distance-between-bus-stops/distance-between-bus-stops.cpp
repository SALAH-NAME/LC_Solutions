#include <vector>
#include <iostream>
#include <numeric>

class Solution
{
public:
	int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination)
	{
		if (start > destination) std::swap(start, destination);

		int total = std::accumulate(distance.begin(), distance.end(), 0);

		int forward = 0;
		for (int i = start; i < destination; i++)
			forward += distance[i];

		return std::min(forward, total - forward);
	}
};

typedef struct testCase
{
	std::vector<int> v;
	int s;
	int d;
} testCase;

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

int main()
{
	std::vector<testCase> tests = {
		{{1,2,3,4},0,1},
		{{1,2,3,4},0,2},
		{{1,2,3,4},0,3},
	};

	for (auto& tc : tests)
	{
		std::cout << "---\ndistance: ";
		printV(tc.v);
		std::cout << ", start: " << tc.s << ", destination: " << tc.d;
		std::cout << "\ndistanceBetweenBusStops: ";
		std::cout	<< Solution().distanceBetweenBusStops(tc.v, tc.s, tc.d);
		std::cout << std::endl;
	}
	return 0;
}
