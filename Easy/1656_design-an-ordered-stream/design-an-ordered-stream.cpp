#include <vector>
#include <iostream>

class OrderedStream
{
private:
	std::vector<std::string> stream;
	int ptr;
	int n;

public:
	OrderedStream(int n)
	{
		stream.resize(n);
		ptr = 1;
		this->n = n;
	}

	std::vector<std::string> insert(int idKey, string value)
	{
		stream[idKey - 1] = value;
		std::vector<std::string> result;

		while (ptr <= n && !stream[ptr - 1].empty())
		{
			result.push_back(stream[ptr - 1]);
		 	ptr++;
		}

		return result;
	}
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
