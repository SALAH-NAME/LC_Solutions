#include <functional>
#include <queue>

class KthLargest
{
public:
	int kth;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	KthLargest(int k, std::vector<int>& nums)
	{
		kth = k;
		for (int n : nums)
		{
			minHeap.push(n);
			if (minHeap.size() > kth) minHeap.pop();
		}
	}

	int add(int val)
	{
		minHeap.push(val);
		if (minHeap.size() > kth) minHeap.pop();
		return minHeap.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
