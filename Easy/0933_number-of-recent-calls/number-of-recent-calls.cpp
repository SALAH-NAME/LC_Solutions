#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

class RecentCounter
{
private:
	std::deque<int> _requests;

public:
	RecentCounter()
	{
		_requests.clear();
	}

	int ping(int t)
	{
		_requests.push_back(t);

		while (!_requests.empty() && t - _requests.front() > 3000)
			_requests.pop_front();

		return _requests.size();
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "[";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{1, 100, 3001, 3002},
		};

	for (auto& in : tests)
	{
		RecentCounter obj;
		std::cout << "---\nInput: ";
		printVector(in);
		for (int i = 0; i < in.size(); i++)
			in[i] = obj.ping(in[i]);
		std::cout << "\nOutput: ";
		printVector(in);
		std::cout << std::endl;
	}
}
