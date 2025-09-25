#include <algorithm>
#include <vector>

class MyHashSet
{
private:
	std::vector<int> set;
public:
	MyHashSet()
	{
	}

	void add(int key)
	{
		set.push_back(key);
	}

	void remove(int key)
	{
		set.erase(std::remove(set.begin(), set.end(), key), set.end());
	}

	bool contains(int key)
	{
		for (int n : set)
			if (n == key) return true;
		return false;
 	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
