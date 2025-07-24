#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
private:
	std::string timeToString(int h, int m)
	{
		std::ostringstream oss;
		oss << h << ":" << std::setw(2) << std::setfill('0') << m;
		return oss.str();
	}
public:
	std::vector<std::string> readBinaryWatch(int turnedOn)
	{
		std::vector<std::string> res;
	
		for (int h = 0; h < 12; ++h)
			for (int m = 0; m < 60; ++m)
				if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
					res.push_back(timeToString(h, m));
		return res;
	}
};
