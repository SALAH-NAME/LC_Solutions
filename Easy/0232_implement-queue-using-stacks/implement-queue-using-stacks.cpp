#include <stack>

class MyQueue
{
private:
	std::stack<int> _inbox;
	std::stack<int> _outbox;

public:
  MyQueue() {}
  
  void push(int x)
	{
		_inbox.push(x);
  }
  
  int pop()
	{
		if (_outbox.empty())
		{
			while (!_inbox.empty())
			{
				_outbox.push(_inbox.top());
				_inbox.pop();
			}
		}
		int res = _outbox.top();
		_outbox.pop();
		return res;
  }
  
  int peek()
	{
		if (_outbox.empty())
		{

			while (!_inbox.empty())
			{
				_outbox.push(_inbox.top());
				_inbox.pop();
			}
		}
		return _outbox.top();
  }
  
  bool empty()
	{
		return _inbox.empty() && _outbox.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
