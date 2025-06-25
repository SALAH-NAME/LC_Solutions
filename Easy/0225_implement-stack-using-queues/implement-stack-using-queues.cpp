#include <queue>
#include <utility>

class MyStack
{
private:
	std::queue<int> q1;
	std::queue<int> q2;
	std::queue<int>* p1 = &q1;
	std::queue<int>* p2 = &q2;

	void swapPtr(std::queue<int>*& p1, std::queue<int>*& p2)
	{
		std::swap(p1, p2);
	}

public:
	MyStack() {}

	void push(int x)
	{
		p1->push(x);
	}

	int pop()
	{
		while (p1->size() > 1)
		{
			p2->push(p1->front());
			p1->pop();
		}
		int res = p1->front();
		p1->pop();
		swapPtr(p1, p2);
		return res;
	}

	int top()
	{
		int res;
		while (!p1->empty())
		{
			res = p1->front();
			p2->push(res);
			p1->pop();
		}
		swapPtr(p1, p2);
		return res;
	}

	bool empty()
	{
		return q1.empty() && q2.empty();
	}
};
