#include <algorithm>
#include <utility>
#include <vector>

class MyHashMap
{
private:
	std::vector<std::pair<int, int>> data;

public:
	MyHashMap() {}

	void put(int key, int value)
	{
		for (int i = 0; i < data.size(); ++i)
		{
			if (key == data[i].first)
			{
				data[i].second = value;
				return ;
			}
		}
		data.push_back({key, value});
	}

	int get(int key)
	{
		for (int i = 0; i < data.size(); ++i)
			if (key == data[i].first)
				return data[i].second;
		return -1;
	}

	void remove(int key)
	{
		data.erase(std::remove_if(data.begin(), data.end(), [key](const std::pair<int, int>& p) { return p.first == key; }), data.end());
 	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
